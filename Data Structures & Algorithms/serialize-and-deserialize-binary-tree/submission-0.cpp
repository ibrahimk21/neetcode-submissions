/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void preorderTraversal(TreeNode* root, string& s)
    {
        if(root == nullptr)
        {
            s.append("null,");
            return;
        }

        s.append(to_string(root->val).append(","));

        preorderTraversal(root->left, s);

        preorderTraversal(root->right, s);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        preorderTraversal(root, s);
        return s;
    }

    TreeNode* solve(const string& data, int& index) {
        if (index >= data.size()) return nullptr;

        // Check for "null"
        if (data[index] == 'n') {
            // Move index past "null," (5 characters)
            index += 5; 
            return nullptr;
        }

        // It's a number. Find where it ends (the next comma).
        int start = index;
        while (index < data.size() && data[index] != ',') {
            index++;
        }

        // Extract the number string and convert
        // substr(start_pos, length)
        int val = stoi(data.substr(start, index - start));
        
        // Move index past the comma we just found
        index++; 

        TreeNode* node = new TreeNode(val);
        node->left = solve(data, index);
        node->right = solve(data, index);
        
        return node;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        return solve(data, index);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
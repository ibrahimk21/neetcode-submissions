/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> inMap;
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int preStart,
                    int preEnd, int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }
        // our root is at preStart
        int rootInInorder = inMap[preorder[preStart]];
        TreeNode* root = new TreeNode(preorder[preStart]);

        int leftSize = rootInInorder - inStart;

        // LEFT CHILD
        // Preorder: [Root, (Left Subtree), (Right Subtree)]
        // Inorder:  [(Left Subtree), Root, (Right Subtree)]
        root->left = build(preorder, inorder, preStart + 1, preStart + leftSize,
                           inStart, rootInInorder - 1);

        // RIGHT CHILD
        // We don't need to calculate rightSize manually.
        // We just go from the end of the left subtree to the existing preEnd.
        root->right = build(preorder, inorder, preStart + leftSize + 1, preEnd,
                            rootInInorder + 1, inEnd);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        return build(preorder, inorder, 0, preorder.size() - 1, 0,
                     inorder.size() - 1);
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, int depth, vector<int>& res) {
        if (!root) return;

        // The "First Arrival" Check
        // If we are visiting this depth for the first time, record the node.
        if (res.size() == depth) {
            res.push_back(root->val);
        }

        // GO RIGHT FIRST (Prioritize the view)
        solve(root->right, depth + 1, res);
        
        // THEN GO LEFT (To catch deeper nodes hiding underneath)
        solve(root->left, depth + 1, res);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        solve(root, 0, res);
        return res;
    }
};
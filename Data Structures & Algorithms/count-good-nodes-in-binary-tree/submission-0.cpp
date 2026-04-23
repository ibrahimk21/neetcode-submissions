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
    // count is passed by REFERENCE (int& count) -> Global memory
    // maxSoFar is passed by VALUE (int maxSoFar) -> Local history
    void solve(TreeNode* root, int maxSoFar, int& count) {
        if (!root) return;

        if (root->val >= maxSoFar) {
            count++;
            maxSoFar = root->val; // Update local max for this path
        }

        solve(root->left, maxSoFar, count);
        solve(root->right, maxSoFar, count);
    }

    int goodNodes(TreeNode* root) {
        int count = 0;
        solve(root, root->val, count);
        return count;
    }
};

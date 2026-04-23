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
    void solve(TreeNode* root, int k, int& count, int& result) {
        if (root == nullptr || count >= k) return;

        solve(root->left, k, count, result);

        count++;
        if (count == k) {
            result = root->val;
            return;
        }

        solve(root->right, k, count, result);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = 0, result = -1;
        solve(root, k, count, result);

        return result;
    }
};
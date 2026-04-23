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
    int getMax(TreeNode* root, int& currentMax)
    {
        if(!root) return 0;

        int askLeft = getMax(root->left, currentMax);
        int askRight = getMax(root->right, currentMax);
        askLeft = (askLeft < 0) ? 0 : askLeft;
        askRight = (askRight < 0) ? 0 : askRight;

        int sum = askLeft + askRight + root->val;
        currentMax = max(currentMax, sum);

        return root->val + max(askLeft, askRight);
    }
    int maxPathSum(TreeNode* root) {
        int max = INT_MIN;
        getMax(root, max);
        return max;
    }
};

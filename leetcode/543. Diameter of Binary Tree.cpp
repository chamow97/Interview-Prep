/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maximum = 0;
    int dfs(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int leftLevel = dfs(root -> left);
        int rightLevel = dfs(root -> right);
        maximum = max(maximum, leftLevel + rightLevel);
        return 1 + max(leftLevel, rightLevel);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        maximum = 0;
        dfs(root);
        return maximum;
    }
};

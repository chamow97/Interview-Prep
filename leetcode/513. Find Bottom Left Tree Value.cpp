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
    int maxDepth;
    void dfs(TreeNode *root, int level, int &leftVal) {
        if(root == NULL) {
            return;
        }
        dfs(root -> left, level + 1, leftVal);
        dfs(root -> right, level + 1, leftVal);
        if(level > maxDepth) {
            maxDepth = level;
            leftVal = root -> val;
        }
    }
    int findBottomLeftValue(TreeNode* root) {
        maxDepth = 0;
        int leftVal = root -> val;
        dfs(root, 0, leftVal);
        return leftVal;
    }
};

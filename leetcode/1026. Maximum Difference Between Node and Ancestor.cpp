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
    int maxDiff;
    void dfs(TreeNode *root, int maxV, int depth, int minV) {
        if(root == NULL) {
            return;
        }
        if(depth)
        maxDiff = max(maxDiff, max(abs(maxV - root -> val), abs(minV - root -> val)));
        dfs(root -> left, max(maxV, root -> val), depth + 1, min(minV, root -> val));
        dfs(root -> right, max(maxV, root -> val), depth + 1, min(minV, root -> val));
    }
    int maxAncestorDiff(TreeNode* root) {
        maxDiff = 0;
        dfs(root, 0, 0, INT_MAX);
        return maxDiff;
    }
};

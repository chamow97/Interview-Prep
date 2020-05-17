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
    int ans;
    void dfs(TreeNode* root, int val) {
        if(root == NULL) {
            return;
        }
        if(root -> left == NULL && root -> right == NULL) {
            ans += ((2 * val) + root -> val);
        }
        dfs(root -> left, (2 * val) + root -> val);
        dfs(root -> right, (2 * val) + root -> val);
    }
    int sumRootToLeaf(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        ans = 0;
        dfs(root, 0);
        return ans;
    }
};

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
    int sum;
    void dfs(TreeNode *root, bool isLeft) {
        if(root == NULL) {
            return;
        }
        if(isLeft && root -> left == NULL && root -> right == NULL) {
            sum += root -> val;
        }
        dfs(root -> left, true);
        dfs(root -> right, false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        sum = 0;
        dfs(root, false);
        return sum;
    }
};

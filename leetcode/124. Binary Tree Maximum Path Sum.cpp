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
    int solve(TreeNode *root, int &result) {
        if(root == NULL) {
            return 0;
        }
        // either take it or leave it
        int left = max(0, solve(root -> left, result));
        int right = max(0, solve(root -> right, result));
        result = max(result, left + right + root -> val);
        return max(0, max(left, right)) + root -> val;
        
    }
    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
        solve(root, result);
        return result;
    }
};

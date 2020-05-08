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
    void solve(TreeNode *root, int depth, vector<int> &ans) {
        if(root == NULL) {
            return;
        }
        if(ans.size() > depth) {
            ans[depth] = max(ans[depth], root -> val);
        } else {
            ans.push_back(root -> val);
        }
        solve(root -> left, depth + 1, ans);
        solve(root -> right, depth + 1, ans);
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        solve(root, 0, ans);
        return ans;
    }
};

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
    void dfs(TreeNode *root, string &str) {
        if(root == NULL) {
            return;
        }
        if(root -> left == NULL && root -> right == NULL) {
            str += (to_string(root -> val) + "$");
            return;
        }
        dfs(root -> left, str);
        dfs(root -> right, str);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string s1 = "", s2 = "";
        dfs(root1, s1);
        dfs(root2, s2);
        return s1 == s2;
    }
};

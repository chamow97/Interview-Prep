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
    string dfs(TreeNode* root, string str) {
        if(root == NULL) {
            return "|";
        }
        string S = (char)('a' + root -> val) + str;
        if(root -> left == NULL && root -> right == NULL) {
            return S;
        } else {
            return min(dfs(root -> left, S), dfs(root -> right, S));
        }
    }
    string smallestFromLeaf(TreeNode* root) {
        return dfs(root, "");
    }
};

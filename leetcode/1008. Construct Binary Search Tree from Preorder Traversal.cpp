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
    int i;
    Solution() {
        i = 0;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder, int maxRange = INT_MAX) {
        if(i >= preorder.size() || preorder[i] > maxRange) {
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[i++]);
        root -> left = bstFromPreorder(preorder, root -> val);
        root -> right = bstFromPreorder(preorder, maxRange);
        return root;
    }
};

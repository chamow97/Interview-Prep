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
    int sum = 0;
    void dfs(TreeNode* root, int parent, int grandParent) {
        if(root == NULL) {
            return;
        }
        if(grandParent % 2 == 0) {
            sum += root -> val;
        }
        dfs(root -> left, root -> val, parent);
        dfs(root -> right, root -> val, parent);
    }
    int sumEvenGrandparent(TreeNode* root) {
        sum = 0;
        dfs(root, -1, -1);
        return sum;
    }
};

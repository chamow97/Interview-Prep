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
    int k1;
    int solution;
    int whichK;
public:
    void infix(TreeNode *root)
    {
        if(root -> left != NULL)
        {
            infix(root -> left);
        }
        ++whichK;
        if(whichK == k1)
        {
            solution = root -> val;
        }
        if(root -> right != NULL)
        {
            infix(root -> right);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        k1 = k;
        whichK = 0;
        solution = -1;
        infix(root);
        return solution;
    }
};

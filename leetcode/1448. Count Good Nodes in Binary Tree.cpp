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
    void findGoodNodes(TreeNode *root, int maxVal) {
        if(root == NULL) {
            return;
        }
        if(maxVal <= root -> val) {
            ans++;
        }
        findGoodNodes(root -> left, max(maxVal, root -> val));
        findGoodNodes(root -> right, max(maxVal, root -> val));
    }
    int goodNodes(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        ans = 0;
        findGoodNodes(root, root -> val);
        return ans;
    }
};

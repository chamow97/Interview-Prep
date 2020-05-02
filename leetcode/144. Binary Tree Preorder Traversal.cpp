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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()) {
            TreeNode* front = s.top();
            s.pop();
            if(front != NULL) {
                result.push_back(front -> val);
                s.push(front -> right);
                s.push(front -> left);
            }
        }
        return result;
    }
};

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
    multiset<int> ms;
    void dfs(TreeNode *root) {
        if(root == NULL) {
            return;
        }
        ms.insert(root -> val);
        dfs(root -> left);
        dfs(root -> right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        dfs(root1);
        dfs(root2);
        vector<int> ans;
        for(auto i : ms) {
            ans.push_back(i);
        }
        return ans;
    }
};

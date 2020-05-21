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
    int total;
    void dfs(TreeNode *root, int sum, unordered_map<int, int> &m, int curr) {
        if(root == NULL) {
            return;
        }
        curr += root -> val;
        if(m.find(curr - sum) != m.end()) {
            total += m[curr - sum];
        }
        m[curr]++;
        dfs(root -> left, sum, m, curr);
        dfs(root -> right, sum, m, curr);
        m[curr]--;
    }
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> m;
        m[0]++;
        total = 0;
        dfs(root, sum, m, 0);
        return total;
    }
};

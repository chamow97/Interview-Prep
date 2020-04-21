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
    int maxLevel;
    unordered_map<int, int> levelSum;
    void dfs(TreeNode *root, int level) {
        if(root == NULL) {
            return;
        }
        maxLevel = max(maxLevel, level);
        levelSum[level] += root -> val;
        dfs(root -> left, level + 1);
        dfs(root -> right, level + 1);
    }
    int maxLevelSum(TreeNode* root) {
        maxLevel = 0;
        levelSum.clear();
        dfs(root, 0);
        int maxVal = INT_MIN;
        int maxL = 0;
        for(int i = 0; i <= maxLevel; i++) {
            if(levelSum[i] > maxVal) {
                maxVal = levelSum[i];
                maxL = i;
            }
        }
        return maxL + 1;
    }
};

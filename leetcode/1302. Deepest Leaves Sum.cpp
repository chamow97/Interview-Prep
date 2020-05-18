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
    vector<int> depthSum;
    int maxDepth;
    int deepestLeavesSum(TreeNode* root) {
        maxDepth = 0;
        depthSum.resize(0);
        queue< pair<TreeNode*, int> > q;
        q.push({root, 0});
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            if(it.second >= depthSum.size()) {
                depthSum.push_back(0);
            }
            depthSum[it.second] += it.first -> val;
            if(it.first -> left != NULL) {
                q.push({it.first -> left, it.second + 1});
            }
            if(it.first -> right != NULL) {
                q.push({it.first -> right, it.second + 1});
            }
        }
        return depthSum[depthSum.size() - 1];
    }
};

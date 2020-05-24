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
    void dfs(TreeNode *root, vector<int> freq) {
        if(root == NULL) {
            return;
        }
        freq[root -> val]++;
        if(root -> left == NULL && root -> right == NULL) {
            int oddCount = 0;
            for(int i = 1; i <= 9; i++) {
                if(freq[i] % 2 == 1) {
                    oddCount++;
                }
            }
            if(oddCount <= 1) {
                ans++;
            }
            return;
        }
        dfs(root -> left, freq);
        dfs(root -> right, freq);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        ans = 0;
        vector<int> freq(10, 0);
        if(root == NULL) {
            return 0;
        }
        dfs(root, freq);
        return ans;
    }
};

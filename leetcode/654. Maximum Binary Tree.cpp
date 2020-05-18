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
    TreeNode* solve(vector<int> &nums, int st, int end) {
        if(st > end) {
            return NULL;
        }
        int maxIndex = max_element(nums.begin() + st, nums.begin() + end + 1) - nums.begin();
        TreeNode* newI = new TreeNode(nums[maxIndex]);
        newI -> left = solve(nums, st, maxIndex - 1);
        newI -> right = solve(nums, maxIndex + 1, end);
        return newI;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        return solve(nums, 0, n - 1);
    }
};

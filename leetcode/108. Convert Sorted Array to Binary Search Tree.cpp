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
    TreeNode* getBST(vector<int> &nums, int low, int high) {
        if(low > high) {
            return NULL;
        }
        int mid = (low + high) / 2;
        TreeNode* curr = new TreeNode(nums[mid]);
        curr -> left = getBST(nums, low, mid - 1);
        curr -> right = getBST(nums, mid + 1, high);
        return curr;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return getBST(nums, 0, nums.size() - 1);
    }
};

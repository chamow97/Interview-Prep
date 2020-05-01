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
    bool isPossible(TreeNode *root, vector<int> &arr, int index) {
        if(index == arr.size() - 1) {
            if(root != NULL && root -> left == NULL && root -> right == NULL && arr[index] == root -> val) {
                return true;
            }
            return false;
        }
        if(root == NULL) {
            return false;
        }
        if(root -> val == arr[index]) {
            return isPossible(root -> left, arr, index + 1) || isPossible(root -> right, arr, index + 1);
        } else {
            return false;
        }
    }
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return isPossible(root, arr, 0);
    }
};

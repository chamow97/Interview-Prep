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
    bool isCousins(TreeNode* root, int x, int y) {
        // BFS
        if(root == NULL) {
            return false;
        }
        queue< pair< pair<TreeNode*, TreeNode*>, int> > q;
        q.push({{NULL, root}, 0});
        int xLevel = -1, yLevel = -1;
        TreeNode* xParent = NULL;
        TreeNode* yParent = NULL;
        while(!q.empty()) {
            pair< pair<TreeNode*, TreeNode*>, int > top = q.front();
            q.pop();
            TreeNode* parent = top.first.first;
            TreeNode* currentNode = top.first.second;
            int level = top.second;
            if(currentNode -> val == x) {
                xLevel = level;
                xParent = parent;
            }
            if(currentNode -> val == y) {
                yLevel = level;
                yParent = parent;
            }
            if(currentNode -> left != NULL) {
                q.push({{currentNode, currentNode -> left}, level + 1});
            }
            if(currentNode -> right != NULL) {
                q.push({{currentNode, currentNode -> right}, level + 1});
            }
            
        }
        return xLevel > 0 && yLevel > 0 && xLevel == yLevel && xParent != NULL && yParent != NULL && xParent -> val != yParent -> val;
    }
};

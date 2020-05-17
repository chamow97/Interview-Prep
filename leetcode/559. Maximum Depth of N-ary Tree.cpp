/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxi;
    void dfs(Node* root, int depth) {
        if(root == NULL) {
            return;
        }
        maxi = max(maxi, depth);
        for(auto i : root -> children) {
            dfs(i, depth + 1);
        }
    }
    int maxDepth(Node* root) {
        if(root == NULL) {
            return 0;
        } 
        maxi = 0;
        dfs(root, 0);
        return maxi + 1;
    }
};

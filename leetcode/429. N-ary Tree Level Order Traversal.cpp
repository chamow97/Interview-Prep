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
    vector<vector<int>> levelOrder(Node* root) {
        queue< pair<Node*, int> > q;
        vector< vector<int> > ans;
        if(root == NULL) {
            return ans;
        }
        q.push({root, 0});
        while(!q.empty()) {
            pair<Node*, int> top = q.front();
            q.pop();
            if(top.second >= ans.size()) {
                ans.push_back(vector<int>(0));
            }
            ans[top.second].push_back(top.first -> val);
            for(auto i : top.first -> children) {
                q.push({i, top.second + 1});
            }
        }
        return ans;
    }
};

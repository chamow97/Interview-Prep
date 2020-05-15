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
    vector<int> postorder(Node* root) {
        vector<int> ans;
        if(root == NULL) {
            return {};
        }
        stack<Node*> s;
        s.push(root);
        while(!s.empty()) {
            auto front = s.top();
            s.pop();
            ans.push_back(front -> val);
            for(auto i : front -> children) {
                s.push(i);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

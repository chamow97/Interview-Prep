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
    vector<int> preorder(Node* root) {
        vector<int> ans;
        stack<Node*> s;
        if(root == NULL) {
            return {};
        }
        s.push(root);
        while(!s.empty()) {
            Node* front = s.top();
            s.pop();
            ans.push_back(front -> val);
            vector<Node*> curr;
            for(auto i : front -> children) {
                curr.push_back(i);
            }
            reverse(curr.begin(), curr.end());
            for(auto i :  curr) {
                s.push(i);
            }
        }
        return ans;
    }
};

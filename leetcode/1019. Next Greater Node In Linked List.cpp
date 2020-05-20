/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        stack< pair<int, int> > s;
        unordered_map<int, int> m;
        int i = 0;
        
        while(head != NULL) {
            while(!s.empty() && s.top().first < head -> val) {
                m[s.top().second] = head -> val;
                s.pop();
            }
            s.push({head -> val, i});
            i++;
            head = head -> next;
        }
        vector<int> ans(i, 0);
        for(auto i : m) {
            ans[i.first] = i.second;
        }
        return ans;
    }
};

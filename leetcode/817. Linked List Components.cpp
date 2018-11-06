/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        map<int, int> m;
        for(int i = 0; i < G.size(); i++)
        {
            m[G[i]]++;
        }
        int cc = 0;
        int prev = -1;
        ListNode *curr = head;
        while(curr != NULL)
        {
            if(m[curr->val] > 0)
            {
                ++cc;
                while(1)
                {
                    if(curr == NULL)
                    {
                        break;
                    }
                    int now = curr->val;
                    now = m[now];
                    if(now <= 0)
                    {
                        break;
                    }
                    curr = curr -> next;
                }
            }
            else
            {
                curr = curr -> next;
            }
        }
        return cc;
    }
};
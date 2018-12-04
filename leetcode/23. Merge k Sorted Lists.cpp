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
    vector<int> ans;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for(int i = 0; i < lists.size(); i++)
        {
            ListNode *temp = lists[i];
            while(temp != NULL)
            {
                ans.push_back(temp -> val);
                temp = temp -> next;
            }
        }
        sort(ans.begin(), ans.end());
        ListNode *head = NULL, *prev = NULL;
        for(int i = 0; i < ans.size(); i++)
        {
            ListNode *temp = new ListNode(ans[i]);
            temp -> next = NULL;
            if(head == NULL)
            {
                head = temp;
                prev = temp;
            }
            else
            {
                prev -> next = temp;
                prev = temp;
            }
        }
        return head;
    }
};
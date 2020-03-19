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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        
        ListNode *head3 = NULL, *top3 = NULL;
        if(head1 == NULL)
        {
            return head2;
        }
        if(head2 == NULL)
        {
            return head1;
        }
        while(head1 != NULL && head2 != NULL)
        {
            if(head1 -> val <= head2 -> val)
            {
                ListNode *temp = new ListNode(head1 -> val);
                if(top3 == NULL)
                {
                    top3 = temp;
                    head3 = temp;
                }
                else
                {
                    head3 -> next = temp;
                    head3 = temp;
                }
                head1 = head1 -> next;
            }
            else
            {
                ListNode *temp = new ListNode(head2 -> val);
                if(top3 == NULL)
                {
                    top3 = temp;
                    head3 = temp;
                }
                else
                {
                    head3 -> next = temp;
                    head3 = temp;
                }
                head2 = head2 -> next;
            }
        }
        while(head1 != NULL)
        {
            ListNode *temp = new ListNode(head1 -> val);
            head3 -> next = temp;
            head3 = temp;
            head1 = head1 -> next;
        }
        while(head2 != NULL)
        {
            ListNode *temp = new ListNode(head2 -> val);
            head3 -> next = temp;
            head3 = temp;
            head2 = head2 -> next;
        }
        return top3;
    }
};

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp = head, *prev = head, *ref = head;
        while(n-- && ref != NULL)
        {
            ref = ref -> next;
        }
        if(ref == NULL)
        {
            head = head -> next;
            return head;
        }
        while(ref != NULL)
        {
            prev = temp;
            temp = temp -> next;
            ref = ref -> next;
        }
        prev -> next = temp -> next;
        return head;
    }
};
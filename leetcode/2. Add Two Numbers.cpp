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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, sum = 0;
        ListNode *head = NULL, *resultList, *prev = NULL;
        while(l1 || l2 || carry)
        {
            sum = carry;
            if(l1)
            {
                sum += l1 -> val;
                l1 = l1 -> next;
            }
            if(l2)
            {
                sum += l2 -> val;
                l2 = l2 -> next;
            }
            carry = sum / 10;
            sum %= 10;
            ListNode *now = new ListNode(sum);
            if(prev)
            {
                prev -> next = now;
            }
            else
            {
                head = now;
            }
            prev = now;
        }
        return head;
        
    }
};
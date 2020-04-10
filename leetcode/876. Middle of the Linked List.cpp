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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        if(slow -> next == NULL) {
            return slow;
        }
        ListNode* fast = head -> next;
        while(fast != NULL) {
            if(slow -> next != NULL) {
                slow = slow -> next;
            }
            if(fast -> next != NULL && fast -> next -> next != NULL) {
                fast = fast -> next -> next;
            } else {
                fast = NULL;
            }
        }
        return slow;
    }
};

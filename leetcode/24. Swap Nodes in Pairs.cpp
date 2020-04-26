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
    ListNode* swapNodes(ListNode* head) {
        if(head == NULL || head -> next == NULL) {
            return head;
        } 
        ListNode* newHead = head -> next;
        ListNode* temp = head -> next -> next;
        newHead -> next = head;
        head -> next = swapNodes(temp);
        return newHead;
    }
    ListNode* swapPairs(ListNode* head) {
        return swapNodes(head);
    }
};

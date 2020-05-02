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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head -> next) {
            return head;
        }
        if(head -> next -> val != head -> val) {
            head -> next = deleteDuplicates(head -> next);
            return head;
        }
        else {
            while(head -> next && head -> next -> val == head -> val) {
                ListNode* nodeToBeDeleted = head;
                head = head -> next;
                delete nodeToBeDeleted;
            }
            ListNode *nodeToBeDeleted = head;
            ListNode *nextNode = head -> next;
            delete nodeToBeDeleted;
            return deleteDuplicates(nextNode);
        }
    }
};

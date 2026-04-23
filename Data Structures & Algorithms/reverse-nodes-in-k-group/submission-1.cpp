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
    // Helper: Standard Reverse Linked List
    // Returns the new head of the reversed list
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prevGroupEnd = dummy;
        ListNode* curr = head;
        
        while (curr) {
            // 1. Check if we have k nodes left
            ListNode* groupEnd = curr;
            for (int i = 1; i < k; i++) {
                // If we run out of nodes, we are done!
                if (!groupEnd->next) return dummy->next;
                groupEnd = groupEnd->next;
            }
            
            // 2. Identify the start of the NEXT group
            ListNode* nextGroupStart = groupEnd->next;
            
            // 3. Isolate the current group
            groupEnd->next = nullptr;
            
            // 4. Reverse the current group
            // 'curr' was the old head, so after reverse, it becomes the new tail.
            // 'groupEnd' was the old tail, so after reverse, it becomes the new head.
            ListNode* newGroupHead = reverseList(curr);
            
            // 5. Connect Previous Group -> New Head
            prevGroupEnd->next = newGroupHead;
            
            // 6. Connect New Tail -> Next Group
            curr->next = nextGroupStart;
            
            // 7. Advance pointers for next iteration
            prevGroupEnd = curr; // 'curr' is the tail of the group we just finished
            curr = nextGroupStart;
        }
        
        return dummy->next;
    }
};

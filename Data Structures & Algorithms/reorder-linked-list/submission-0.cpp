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
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* findMiddle(ListNode* head)
    {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    void zip(ListNode* head1, ListNode* head2)
    {
        ListNode* curr = head1;
        ListNode* next = head2;
        while(curr && next)
        {
            ListNode* temp = curr->next;
            curr->next = next;
            curr = next;
            next = temp;
        }
    }
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // 1. Find Middle
        ListNode* middle = findMiddle(head);
        
        // 2. The Cut (Critical Step)
        ListNode* secondHalf = middle->next; // Save the start of part 2
        middle->next = nullptr;              // Sever the first half
        
        // 3. Reverse the Second Half
        secondHalf = reverse(secondHalf);
        
        // 4. Merge
        zip(head, secondHalf); // FIX 2: Void function, no return
    }
};
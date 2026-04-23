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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return head;

        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = curr->next;
        if(next == nullptr) return head;

        while(next != nullptr)
        {
            ListNode* temp = next->next;

            curr->next = prev;
            next->next = curr;

            prev = curr;
            curr = next;
            next = temp;
        }

        return curr;
    }
};
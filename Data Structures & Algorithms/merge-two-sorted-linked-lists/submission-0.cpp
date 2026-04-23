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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* mergedList = new ListNode();
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        ListNode* mergedListCurr = mergedList;
        while(curr1 != nullptr && curr2 != nullptr)
        {
            if(curr1->val < curr2->val)
            {
                if(curr1->next == nullptr && curr2->next == nullptr)
                {
                    mergedListCurr->next = new ListNode(curr1->val, nullptr);
                    mergedListCurr = mergedListCurr->next;
                    curr1 = curr1->next;
                }
                else
                {
                    mergedListCurr->next = new ListNode(curr1->val, new ListNode());
                    mergedListCurr = mergedListCurr->next;
                    curr1 = curr1->next;
                }
            }
            else
            {
                if(curr1->next == nullptr && curr2->next == nullptr)
                {
                    mergedListCurr->next = new ListNode(curr2->val, nullptr);
                    mergedListCurr = mergedListCurr->next;
                    curr2 = curr2->next;
                }
                else
                {
                    mergedListCurr->next = new ListNode(curr2->val, new ListNode());
                    mergedListCurr = mergedListCurr->next;
                    curr2 = curr2->next;
                }
            }
        }
        while(curr2 != nullptr)
        {
            if(curr2->next == nullptr)
            {
                mergedListCurr->next = new ListNode(curr2->val, nullptr);
                mergedListCurr = mergedListCurr->next;
                curr2 = curr2->next;
            }
            else
            {
                mergedListCurr->next = new ListNode(curr2->val, new ListNode());
                mergedListCurr = mergedListCurr->next;
                curr2 = curr2->next;
            }
            
        }
        while(curr1 != nullptr)
        {
            if(curr1->next == nullptr)
            {
                mergedListCurr->next = new ListNode(curr1->val, nullptr);
                mergedListCurr = mergedListCurr->next;
                curr1 = curr1->next;
            }
            else
            {
                mergedListCurr->next = new ListNode(curr1->val, new ListNode());
                mergedListCurr = mergedListCurr->next;
                curr1 = curr1->next;
            }
        }
        return mergedList->next;
    }
};
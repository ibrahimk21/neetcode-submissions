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
    struct Compare
    {
        bool operator()(ListNode* a, ListNode* b)
        {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;
        ListNode* dummy = new ListNode();

        for(ListNode* listHead: lists)
        {
            if(listHead != nullptr)
            {
                minHeap.push(listHead);
            }
        }
        ListNode* curr = dummy;
        while(!minHeap.empty())
        {
            ListNode* currMin = minHeap.top();
            minHeap.pop();

            curr->next = currMin;
            curr = curr->next;
            
            currMin = currMin->next;
            if(currMin)
            {
                minHeap.push(currMin);
            }
        }
        return dummy->next;
    }
};
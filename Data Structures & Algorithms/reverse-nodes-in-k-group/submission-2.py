# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        groupPrev = dummy
        
        while True:
            # 1. Find the end of the current k-group
            kth = self.getKth(groupPrev, k)
            if not kth:
                break  # Not enough nodes left, obey the Leftover Rule!
                
            groupNext = kth.next
            
            # 2. Reverse the group
            # TRICK: Instead of prev = None, initialize prev to the NEXT group.
            # This automatically connects the tail of our reversed chunk to the rest of the list!
            prev = groupNext
            curr = groupPrev.next
            
            while curr != groupNext:
                temp = curr.next
                curr.next = prev
                prev = curr
                curr = temp
                
            # 3. Stitch the previous chunk to the new head of this chunk
            temp = groupPrev.next  # This is the old head, which is now the tail!
            groupPrev.next = kth   # kth is the new head of the reversed group
            groupPrev = temp       # Move the anchor forward for the next loop
            
        return dummy.next

    # Helper function to jump 'k' steps safely
    def getKth(self, curr, k):
        while curr and k > 0:
            curr = curr.next
            k -= 1
        return curr
        
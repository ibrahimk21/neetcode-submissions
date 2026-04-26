# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        # we keep 2 pointers with a gap of n steps, 
        # then slide both of them to the end and remove the node sitting at the first pointer

        left = right = head
        # creating the gap
        for _ in range(n):
            right = right.next

        if not right:
            return head.next
        
        # sliding the 2 pointers until the end
        while right.next:
            right = right.next
            left = left.next
        
        # remove node at left
        left.next = left.next.next

        return head

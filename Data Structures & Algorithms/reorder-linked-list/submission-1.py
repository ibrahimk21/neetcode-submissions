# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        # find middle
        slow = fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        second_half = slow.next
        slow.next = None
        middle = second_half
        # reverse from the middle
        prev = None
        curr = middle
        while curr:
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp
        # alternate between lists
        curr1, curr2 = head, prev
        while curr1 and curr2:
            temp1 = curr1.next
            temp2 = curr2.next
            
            curr1.next = curr2
            curr2.next = temp1
            
            curr1 = temp1
            curr2 = temp2
            
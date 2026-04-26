"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        # create a map between old and new nodes
        map = {None: None}

        # only clone the nodes themselves without their pointer and fill the map
        curr = head
        while curr:
            map[curr] = Node(curr.val)
            curr = curr.next
        
        # now copy the pointers
        curr = head
        while curr:
            original, clone = curr, map[curr]
            clone.next = map[original.next]
            clone.random = map[original.random]
            curr = curr.next
        
        return map[head]
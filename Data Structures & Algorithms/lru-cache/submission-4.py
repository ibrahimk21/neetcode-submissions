class Node:
    def __init__(self, key = 0, val = 0, next = None, prev = None):
        self.key = key 
        self.val = val
        self.next = next
        self.prev = prev

class LRUCache:

    def __init__(self, capacity: int):
        self.map = {}
        self.head = Node()
        self.tail = Node()
        self.capacity = capacity
        self.current_capacity = 0

        self.head.next = self.tail
        self.tail.prev = self.head

    def get(self, key: int) -> int:
        # FIX 1: If the key isn't in the map, return -1 instead of crashing
        if key not in self.map:
            return -1

        wanted_value = self.map[key].val
        
        # Extract the node
        self.map[key].prev.next = self.map[key].next
        self.map[key].next.prev = self.map[key].prev
        
        # Snap it to the front
        self.map[key].next = self.head.next
        self.map[key].prev = self.head
        
        # FIX 2: Tell the head and the old first node to point backward at the moved node
        self.head.next.prev = self.map[key]
        self.head.next = self.map[key]

        return wanted_value
        

    def put(self, key: int, value: int) -> None:
        if key in self.map:
            self.map[key].val = value
            
            # Extract the node
            self.map[key].prev.next = self.map[key].next
            self.map[key].next.prev = self.map[key].prev
            
            # Snap it to the front
            self.map[key].next = self.head.next
            self.map[key].prev = self.head
            
            # FIX 2: Tell the head and the old first node to point backward at the moved node
            self.head.next.prev = self.map[key]
            self.head.next = self.map[key]
            
        else:
            new_node = Node(key, value, self.head.next, self.head)
            self.map[key] = new_node
            
            new_node.prev.next = new_node
            new_node.next.prev = new_node
            
            self.current_capacity += 1
            
            if self.current_capacity > self.capacity:
                evicted_node = self.tail.prev
                
                evicted_node.prev.next = self.tail
                self.tail.prev = evicted_node.prev
                
                self.current_capacity -= 1
                del self.map[evicted_node.key]
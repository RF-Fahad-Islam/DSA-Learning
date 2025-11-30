class Node:
    def __init__(self, data):
        self.data = data
        self.next = None  # Initially, the next node is None

class LinkedList:
    def __init__(self):
        self.head:Node|None = None  # Initially, the list is empty

    def append(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            return
        last_node = self.head
        while last_node.next:
            last_node = last_node.next
        last_node.next = new_node # type: ignore

    def prepend(self,data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            return
        new_node.next = self.head # type: ignore
        self.head = new_node
    
    def insert(self,data,i):
        if i==0:
            self.prepend(data)
            
        current:Node|None = self.head
        for _ in range(1,i):
            current = current.next

        new_node = Node(data)
        new_node.next = current.next # type: ignore
        current.next = new_node # type: ignore
        
    def display(self):
        current = self.head
        elements = []
        while current:
            elements.append(str(current.data))
            current = current.next
        print(" -> ".join(elements))

# Example Usage:
my_list = LinkedList()
my_list.append(10)
my_list.append(20)
my_list.append(30)
my_list.prepend(110)
my_list.insert(202, 2)
my_list.display() # Output: 10 -> 20 -> 30
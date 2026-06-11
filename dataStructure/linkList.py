from asyncio.windows_events import NULL
from math import pi

from pyparsing import lineEnd


class Node:
    def __init__(self, data):
        self.data = data
        self.next = NULL
class LinkList:
    def __init__(self):
        self.head = NULL
        self.tail = NULL
        self.n = 0

    def getNode(self, data):
        return Node(data)
    def addHead(self, data):
        if self.head == NULL:
            self.head = self.tail = self.getNode(data)
            self.n += 1
            return
        node = self.getNode(data)
        node.next = self.head
        self.head = node
        self.n += 1
    def addTail(self, data):
        if self.head == NULL:
            self.head = self.tail = self.getNode(data)
            self.n += 1
            return
        node = self.getNode(data)
        self.tail.next = node
        self.tail = node
        self.n += 1
    def addAtPos(self, data, pos):
        if pos < 1:
            self.addHead(data)
            return
        elif pos > self.n:
            self.addTail(data)
            return
        node = self.getNode(data)
        temp = self.head
        count = 0
        while count < pos - 1:
            count += 1
            temp = temp.next
        node.next = temp.next
        temp.next = node
        self.n += 1
    def printList(self):
        temp = self.head
        while temp != NULL:
            print(temp.data, end=" ")
            temp = temp.next
        print("\n")
    def deleteHead(self):
        if self.head != NULL:
            temp = self.head
            self.head = self.head.next
            del temp
    def clear(self):
        while self.head != NULL:
            temp = self.head
            self.head = self.head.next
            del temp
    def copy(self, other):
        temp = other.head
        while temp != NULL:
            self.addTail(temp.data)
            temp = temp.next
list = LinkList()
for i in range(5):
    list.addTail(i)
for i in range(5):
    list.addHead(i)
list.printList()
list.deleteHead()
list.deleteHead()
list.printList()
list.clear()
print("after clear:")
list.printList()

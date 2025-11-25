
from .linkedlist import LinkedList
from .node import Node

class Filemanager:
    def serialization(self,list):
        current =list.head
        with open("file.txt","w") as file:
            while current != None:
                file.write(str(current.data)+"-->")
                current =current.next
        
    def deserialization(self):
        list =LinkedList()
        with open("file.txt","r") as file:
            data =file.read()
            items = data.split("-->")
            for item in items:
                if item:
                    list.insert(item)
                return list
            
        
from .node import Node

class LinkedList:
    
    
    def __init__(self):
        self.head =None
        
    def insert(self,item):
        theNode = Node(item)
        
        if self.head ==None:
            self.head =theNode
            return
        
        current=self.head
        while(current.next !=None):
            current = current.next
        
        current.next =theNode
        
        return
    
    
    def search(self,value):
        
        current =self.head
        
        while(current !=None):
            if(current.data==value):
                print(value,"found ")
                return
            
            current =current.next
        print("not found")  
        
        
        return
    
    def remove(self,value):
        
        if self.head == None:
            print("list is empty")
            return
        if self.head.data==value:
            self.head = self.head.next
            return
        
        previousnode =None
        current =self.head
        
        while(current.next!=None):
            previousnode =current
            current=current.next
            if(current.data==value):
                previousnode.next=current.next
                return
            
        print("number not found")
        return
    
    def display(self):
        
        current=self.head
        
        if current==None:
            print("List is empty")
            return
        while (current!=None):
            print(current.data,end= "---->")
            current=current.next
        
        return
    
from linkedist import Node,LinkedList,Filemanager

list =LinkedList()
mgr = Filemanager()

list.insert(34)
list.insert(45)
list.insert(67)
mgr.serialization(list)


# while (True):
#     print("\n1.insert the new node\n2.delete the node\n3.search the node\n4.display the node\n5.exit")
#     choice=int(input("enter the choice:"))
    
#     match choice:
        
#         case 1:
#             item=int(input("enter the item to insert"))
#             list.insert(item)
        
#         case 2:
#             value= int(input("enter the item to be deleted"))
            
#             list.remove(value)
        
#         case 3:
#             value= int(input("enter the value to search"))
            
#             list.search(value)
        
#         case 4:
#             list.display()
            
#         case 5:
#             print("exiting the code")
#             exit()
            

    
    
    
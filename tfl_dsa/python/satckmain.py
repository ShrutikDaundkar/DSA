from stack import Book, Shelf


shelf=Shelf()
while(True):
    
    print("-----menu-----")
    print("\n1.add the book\n2. remove the book \n3.display all the book in shelf\n4.exit")
    choice =int(input("enter the choice:"))
    
    match choice:
        case 1:
            booktitle =input("enter the book title")
            author =input("enter the author")
            book =Book(booktitle ,author)
            shelf.push(book)
        case 2:
            shelf.pop()
            
        case 3:
            shelf.display()
            
        case 4:
            print("exiting the code")
            exit()
                
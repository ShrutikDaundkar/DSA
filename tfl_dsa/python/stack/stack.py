SIZE = 5
class Book:
    def __init__(self, bookTitle, author):
        self.bookTitle = bookTitle
        self.author = author




class Shelf:
    def __init__(self):
        self.books = [None] * SIZE
        self.top = -1

    def push(self, book):
        if self.top == SIZE - 1:
            print("Shelf is full, book not added")
            return
        self.top += 1
        self.books[self.top] = book
        print("Pushed:", book.bookTitle)

    def pop(self):
        if self.top == -1:
            print("Stack is empty")
            return Book("empty", "none")
        removed = self.books[self.top]
        print("Popped:", removed.bookTitle)
        self.top -= 1
        return removed

    def peek(self):
        if self.top == -1:
            print("Shelf is empty")
            return
        print("Book on top:", self.books[self.top].bookTitle)
        
    def display(self):
        if self.top ==-1:
            print("stack is empty")
            return
        
        print("show all books")
        for i in range(self.top ,-1,-1):
            print("Name:",self.books[i].bookTitle)
    
def main():
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
                        
main()
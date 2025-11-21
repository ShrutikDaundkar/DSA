import json
from .shelf import Shelf
from .book import Book

class Filemanager:
    def serialization(self, shelf):
        
        datalist=[]
        for i in range(0,shelf.top+1):
            data={
                "title":shelf.books[i].bookTitle,
                "author":shelf.books[i].author
            }
            datalist.append(data)
        with open("data.json","w") as file:
            json.dump(datalist,file)
    
    
    def deserialization(self):
        shelf =Shelf()
        with open("data.json","r") as file:
            datalist=json.load(file)
            
            for data in datalist:
                book =Book(data["title"],data["author"])
                shelf.push(book)
        return shelf
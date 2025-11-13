#include<iostream>
#include "stack.h"

using namespace std;

int main(){
    Stack backstack;
    Stack forwardstack;
    string current_page ="Home";

    int choice;
    string url;

    do {
        cout <<"welcome to the broswer\n";
        cout<<"==============================\n";
        cout<<"current page:-"<<current_page;
        cout <<"\n=============================\n";
        cout<<"1.visiting new page\n";
        cout<<"2.prevoius page\n";
        cout <<"3.next page\n";
        cout <<"4.exit\n";
        cout <<"enter the choice";
        cin>>choice;

        switch(choice){
        
        case 1:
        backstack.push(current_page);
        cout<<"enter the url ";
        cin>> url;
        current_page = url;
        forwardstack.clear();
        break;

        case 2:
        if (backstack.isEmpty()){
            cout<<" no prevoius page to visit";
        }
        else{
            forwardstack.push(current_page);
            current_page = backstack.pop();
            break;
        }

        case 3:
        if (forwardstack.isEmpty()){
            cout<<"no next page to visit";
        }
        else{
            backstack.push(current_page);
            current_page = forwardstack.pop();
            break;
        }

        case 4:
        cout<<"exiting the broswer";
        break;

        default:
        cout <<"invaild number";
    }
    

    }while (choice!=4);
    
    return 0;
    
}


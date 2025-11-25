class Node{
    int value;
    Node next;
    public Node(int value){
        this.value =value;
        this.next=null;

    }

}

class operation{
    Node head;

    operation(){
        this.head=null;
    }

    public void insert(int data){
        Node newNode= new Node(data);
        if (head ==null){
            head= newNode;
            return;
        }
        Node current=head;
        while(current.next!= null){
            current=current.next;
        }
        current.next =newNode;
    }

    public void display(){
        if(head== null){
            System.out.println("list is empty");
        }

        Node current = head;
        while(current!= null){
            System.out.print (current.value+"-->");
            current=current.next;
        }
    }
    
    void remove(int data){


    }

    void search(int data){
        
    }
}

class linkedlist{
    public static void main(String[] args) {

        operation op =new operation();
        op.insert(45);
        op.insert(34);
        op.insert(78);
        op.display();
        
    }
}
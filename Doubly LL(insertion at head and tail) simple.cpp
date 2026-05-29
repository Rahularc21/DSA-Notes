#include <iostream>
using namespace std;
class Node{
public:
  int val;
  Node* next;
  Node* prev;
  Node(int data){
      val=data;
      next=prev=NULL;
  }
};
void print(Node* head){
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}

Node* insertAtHead(Node* head,int data){
    Node* temp=new Node(data);
    if(head!=NULL){
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
    else{
        head=temp;
    }
    return head;
}

Node* insertAtTail(Node* head,int data){
    if(head){
        Node* tail=head;
        while(tail->next !=NULL){
            tail=tail->next;
        }
        Node* temp=new Node(data);
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
    else{
        Node* temp=new Node(data);
        head=temp;
    }
    return head;
    
}
int main() {
    Node* head=new Node(10);
    print(head);


    head=insertAtHead(head,5);
    print(head);
    
    head=insertAtTail(head,20);
    print(head);
}

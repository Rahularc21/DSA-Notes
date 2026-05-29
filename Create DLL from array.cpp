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

Node* createDLL(int arr[],int n){
    //it is basically insertion at tail right so lets take a tail pointer too..
    Node* head=NULL, *tail = NULL;
    for(int i=0;i<n;i++){
        if(head==NULL){
            head=new Node(arr[i]);
            tail=head;
        }
        else{
            Node* temp=new Node(arr[i]);
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
        }
    }
    return head;
}
int main() {
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    Node* head=createDLL(arr,n);
    print(head);
}

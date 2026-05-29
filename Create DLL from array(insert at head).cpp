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
    Node* head=NULL;
    for(int i=0;i<n;i++){
        if(head==NULL){
            head=new Node(arr[i]);
        }
        else{
            Node* temp=new Node(arr[i]);
            temp->next=head;
            head->prev=temp;
            head=temp;
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

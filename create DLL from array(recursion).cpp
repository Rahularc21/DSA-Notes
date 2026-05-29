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

Node* createDLL(int arr[],int idx,int n,Node* p){
    if(idx==n){
        return NULL;
    }
    Node* head=new Node(arr[idx]);
    head->prev=p;
    head->next=createDLL(arr,idx+1,n,head);
    return head;
}
int main() {
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    Node* head=createDLL(arr,0,n,NULL);
    print(head);
}

//insert At Beginning....
#include <iostream>
using namespace std;
class Node{
public:
  int val;
  Node* next;
  Node(int val){
      this->val=val;
      next=NULL;
  }
};
Node* createLL(int arr[],int n){
    Node* head=NULL;
    for(int i=0;i<n;i++){
        if(head==NULL){
            head=new Node(arr[i]);
        }
        else{
            Node* curr=new Node(arr[i]);
            curr->next=head;
            head=curr;
        }
    }
    return head;
}
void print(Node* head){
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
}
int main() {
    int arr[]={1,2,3,4,5,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    Node* head=createLL(arr,n);
    print(head);
}

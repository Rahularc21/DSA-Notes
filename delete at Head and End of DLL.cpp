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

Node* createDLL(int arr[],int n){
    Node* head=NULL;
    Node* curr=NULL;
    for(int i=0;i<n;i++){
        if(head==NULL){
            head=new Node(arr[i]);
            curr=head;
        }
        else{
            Node* temp=new Node(arr[i]);
            curr->next=temp;
            temp->prev=curr;
            curr=curr->next;
        }
    }
    return head;
}

Node* deleteHead(Node* head){
   if(head!=NULL){
   //1 node or more
        if(head->next==NULL){
            delete head;
            return NULL;
        }
        else{
            Node* temp=head;
            head=head->next;
            head->prev=NULL;
            delete temp;
            return head;
        }
   }
   return head;
}

Node* deleteEnd(Node* head){
    //edge case...
    if(head){
        if(head->next==NULL){
            delete head;
            return NULL;
        }
        else{
            Node* temp=head;
            Node* pre=NULL;
            while(temp->next!=NULL){
                pre=temp;
                temp=temp->next;
            }
            pre->next=NULL;
            delete temp;
        }
    }
    return head;
}
void print(Node* head){
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}
int main() {
   int arr[]={1,2,4,5,6};
   int n=sizeof(arr)/sizeof(arr[0]);
   Node* head=NULL;
   head=createDLL(arr,n);
   print(head);
   head=deleteHead(head);
   print(head);
   head=deleteEnd(head);
   print(head);
}

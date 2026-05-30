//insert at posititon after of DLL
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
Node* insertAtIdx(Node* head,int val,int pos){
//insert at head,last and middle....
    if(pos==0){
        if(head==NULL){
            head=new Node(val);
            return head;
        }
        else{
            Node* temp=new Node(val);
            temp->next=head;
            head->prev=temp;
            head=temp;
            return head;
        }
    }
    else{
        Node* curr=head;
        while(--pos){
            curr=curr->next;
        }
        if(curr==NULL && pos>0){
            cout<<"Invalid Position"<<endl;
            return head;
        }
        if(curr->next==NULL){
            Node* temp=new Node(val);
            curr->next=temp;
            temp->prev=curr;
            return head;
        }
        else{
            Node* temp=new Node(val);
            temp->next=curr->next;
            temp->prev=curr;
            curr->next=temp;
            temp->next->prev=temp;
            return head;
        }
    }
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
   head=insertAtIdx(head,50,5);
   print(head);
}

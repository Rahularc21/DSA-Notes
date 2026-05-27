#include <iostream>
using namespace std;

class Node{
public:
    int val;
    Node* next;

    Node(int data){
        val=data;
        next=NULL;
    }
};

Node* createLL(int arr[],int n){
    Node* head=NULL;
    Node* curr=head;

    for(int i=0;i<n;i++){
        if(head==NULL){
            head=new Node(arr[i]);
            curr=head;
        }
        else{
            Node* temp=new Node(arr[i]);
            curr->next=temp;
            curr=curr->next;
        }
    }
    return head;
}

void display(Node* head){
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
}
int main() {

    int arr[]={2,3,4,5,7,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    Node* head=createLL(arr,n);
    display(head);
}

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



Node* createLL(int arr[],int idx,int n){
    if(idx==n) return  NULL;
    Node* head=new Node(arr[idx]);
    head->next=createLL(arr,idx+1,n);
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
    
    Node* head=createLL(arr,0,n);
    display(head);
}

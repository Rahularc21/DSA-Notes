//insert At index.....
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
    if(idx==n){
        return NULL;
    }
    Node* curr=new Node(arr[idx]);
    curr->next=createLL(arr,idx+1,n);
    return curr;
}

Node* insertAtIdx(Node* head,int idx,int val){
    if(idx==0){
        Node* temp=new Node(val);
        temp->next=head;
        return temp;
    }
    // Base Case 2: SAFETY CHECK (Agar index out of bounds ho)
    if (head == NULL) {
        return head; 
    }
    head->next=insertAtIdx(head->next,idx-1,val);
    return head;
}

void display(Node* head){
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}
int main() {

    int arr[]={2,3,4,5,7,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    Node* head=createLL(arr,0,n);
    
    display(head);
    head=insertAtIdx(head,2,50);
    display(head);
}

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

Node* createLL(int arr[],int idx,int n,Node* prev){
    if(idx==n){
        return prev;
    }
    Node* temp=new Node(arr[idx]);
    temp->next=prev;
    return createLL(arr,idx+1,n,temp);
}

void insertAtIdx(Node* head,int idx,int val){
    Node* temp=head;
    for(int i=1;i<idx;i++){
        temp=temp->next;
    }
    Node* t=new Node(val);
    t->next=temp->next;
    temp->next=t;
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
    
    Node* head=createLL(arr,0,n,NULL);
    
    display(head);
    insertAtIdx(head,2,50);
    display(head);
}

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
    if(idx==n) return NULL;
    Node* curr=new Node(arr[idx]);
    curr->next=createLL(arr,idx+1,n);
    return curr;
}

Node* deleteAtIdx(Node* head,int pos){
    if(head == NULL || pos<=0) return NULL;
    if(pos==1){
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
        
    }
    head->next=deleteAtIdx(head->next,pos-1);
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
    
    head=deleteAtIdx(head,3);
    display(head);
}

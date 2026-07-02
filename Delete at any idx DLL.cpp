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

Node* deletePos(Node* head,int pos){
    if(head){
        if(pos==1){
            if(head->next==NULL){
                delete head;
                return NULL;
            }
            else{
                Node* temp=head;
                head=head->next;
                head->prev=NULL;
                delete temp;
            }
        }
        else{
            Node* curr=head;
            while(--pos && curr!=NULL){
                curr=curr->next;
            }
            //out of bound
            if(curr==NULL){
                cout<<"Invalid pos"<<endl;
                return head;
            }
            //last node
            if(curr->next==NULL){
                curr->prev->next=NULL;
                delete curr;
            }
            else{
                curr->prev->next=curr->next;
                curr->next->prev=curr->prev;
                delete curr;
            }
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
    head=deletePos(head,2);
    print(head);
}

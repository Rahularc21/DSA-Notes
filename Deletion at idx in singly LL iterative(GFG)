/*
class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        if(x==1){
            Node* temp=head;
            head=head->next;
            delete temp;
        }
        else{
            Node* temp=head;
            Node* prev=NULL;
            for(int i=1;i<x;i++){
                prev=temp;
                temp=temp->next;
            }
            prev->next=temp->next;
            delete temp;
        }
        return head;
        
    }
};



//M-2

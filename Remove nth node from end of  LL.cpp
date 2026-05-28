/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size=0;
        ListNode* temp=head;
        while(temp){
            size++;
            temp=temp->next;
        }
        int x=size-n;
        //2 pointers for deleting the node and prev to point to next 
        ListNode* prev=NULL;
        temp=head;
        if(x==0){
            //deleting head only
            head=head->next;
            delete temp;
            return head;
        }
        while(x--){
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        delete temp;
        return head;
    }
};

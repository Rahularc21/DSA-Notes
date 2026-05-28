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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* tail=NULL;
        int n=0;
        while(curr){
            n++;
            tail=curr;
            curr=curr->next;
        }
        if(n==0) return NULL;
        k=k%n;
        if(k==0) return head;
        int count=n-k;
        curr=head;
        while(count--){
            prev=curr;
            curr=curr->next;
        }
        tail->next=head;
        head=curr;
        prev->next=NULL;
        return head;

    }
};




M2) by array-->
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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* curr=head;
        vector<int> arr;
        while(curr){
            arr.push_back(curr->val);
            curr=curr->next;
        }
        if(arr.size()==0) return NULL;
        k=k%arr.size();
        int i=arr.size()-k;
        curr=head;
        while(curr){
            i=i%arr.size();
            curr->val=arr[i];
            i++;
            curr=curr->next;
        }
        return head;
    }
};

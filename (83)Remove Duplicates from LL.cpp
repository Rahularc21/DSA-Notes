// M-1 with array(extra space)
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
    ListNode* deleteDuplicates(ListNode* head){
        if(head==NULL) return head;
        vector<int> ans;
        ListNode* temp=head->next;
        ans.push_back(head->val);
        while(temp){
            if(ans[ans.size()-1]!=temp->val){
                ans.push_back(temp->val);
            }
            temp=temp->next;
        }
        // ans=[1,2]
        int idx=0;
        temp=head;
        ListNode* prev=NULL;
        while(idx<ans.size()){
            temp->val=ans[idx];
            idx++;
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        return head;
    }
};




// M-2 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return head;
        ListNode* prev=head;
        ListNode* curr=head->next;
        while(curr){
            if(prev->val==curr->val){
                prev->next=curr->next;
                delete curr;
                curr=prev->next;
            }
            else{
                prev=prev->next;
                curr=curr->next;
            }
        }
        return head;
    }
};

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
    ListNode* removeNthFromEnd(ListNode* head, int m) {
        
        // ListNode* curr=head;
        // int cnt=0;

        // while(curr){
        //     cnt++;
        //     curr=curr->next;
        // } 
        // if(m>cnt)
        // return NULL;


        // int n=cnt-m+1;
        // curr=head;

        // ListNode* prev=NULL;
        // ListNode* nextNode=NULL;
        // while(curr){
        //     n--;
        //     if(n==0){
        //         nextNode=curr->next;
        //         break;
        //     }

        //     prev=curr;
        //     curr=curr->next;

        // }

        // if(prev){
        //     prev->next=nextNode;
        //     curr->next=NULL;
        //     delete curr;
        // }else{
        //     curr=curr->next;
        //     return curr;
        // }

        // return head;
        if(!head)
        return NULL;

        ListNode* dummy=new ListNode(0,head);
        ListNode* fast=dummy;
        ListNode* slow=dummy;


        for(int i=0;i<m;i++){
            fast=fast->next;
        }

        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }

        ListNode* toBeDeleted=slow->next;
        slow->next=slow->next->next;
        
    
        ListNode* newhead=dummy->next;
        delete dummy;

        return newhead;




    }
};
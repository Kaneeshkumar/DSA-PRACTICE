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
    ListNode* findMiddle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;

        if(fast==NULL)
        return NULL;

        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        return slow;
    }

    ListNode* merge2LL(ListNode* l1,ListNode* l2){

        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;

        while(l1 && l2){
            if(l1->val<=l2->val){
                temp->next=l1;
                temp=l1;
                l1=l1->next;
            }else{
                temp->next=l2;
                temp=l2;
                l2=l2->next;
            }
        }

        if(l1){
            temp->next=l1;
        }

        if(l2){
            temp->next=l2;
        }
        ListNode* newHead=dummy->next;

        delete dummy;

        return newHead;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || head->next==NULL)
        return head;

        ListNode* middle=findMiddle(head);
        ListNode* right=middle->next;
        middle->next=NULL;
        ListNode* left1=sortList(head);
        ListNode* right1=sortList(right);

       return merge2LL(left1,right1);
    }
};
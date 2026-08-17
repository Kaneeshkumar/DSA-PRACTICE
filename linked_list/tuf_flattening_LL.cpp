/*
Definition of special linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *child;
    ListNode()
    {
        val = 0;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode* next2)
    {
        val = data1;
        next = next1;
        child = next1;
    }
};
*/

class Solution {
private:
    ListNode* mergeBothLL(ListNode* l1,ListNode* l2){

        ListNode* dummy=new ListNode(-1);
        dummy->next=NULL;
        dummy->child=NULL;

        ListNode* res=dummy;

        while(l1 && l2){
            if(l1->val<=l2->val){
                res->child=l1;
                res=l1;
                l1=l1->child;
            }else{
                res->child=l2;
                res=l2;
                l2=l2->child;
            }
            res->next=NULL;
        }

        if(l1)
        res->child=l1;
        
        if(l2)
        res->child=l2;

        res->next=NULL;

        ListNode* newHead=dummy->child;
        delete dummy;

        return newHead;






    }
public:
    ListNode* flattenLinkedList(ListNode* &head) {

        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* mergedHead=flattenLinkedList(head->next);
        return mergeBothLL(head,mergedHead);

    }
};
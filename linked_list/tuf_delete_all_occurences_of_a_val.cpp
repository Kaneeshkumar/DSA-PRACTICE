/*
Definition of doubly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};
*/

class Solution {
public:
    ListNode * deleteAllOccurrences(ListNode* head, int target) {

            ListNode* prev1=NULL;
            ListNode* curr=head;
            ListNode* newHead=NULL;

            while(curr){
                ListNode* nextNode=curr->next;
                if(curr->val!=target){
                    if(!prev1){
                        prev1=curr;
                        newHead=curr;
                    }else{
                        prev1->next=curr;
                        curr->prev=prev1;
                        prev1=curr;
                    }
                }else{
                    curr->prev=NULL;
                    curr->next=NULL;
                    delete curr;
                }
                    curr=nextNode;
                
            }


    if(prev1)
    prev1->next = NULL;

    if(newHead)
    newHead->prev=NULL;

            return newHead;
    }
};
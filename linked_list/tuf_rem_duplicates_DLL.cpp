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
    ListNode * removeDuplicates(ListNode *head) {
        if(!head)
        return NULL;

        if(!head->next)
        return head;

        ListNode* temp=head->next;
        ListNode* newHead=head;

     
        ListNode* prevNode=head;
        int prev=prevNode->val;

        while(temp){
            ListNode* nextNode=temp->next;
            if(temp->val!=prev){
                prevNode->next=temp;
                temp->prev=prevNode;
                prevNode=temp;
                prev=temp->val;
            }else{
                delete temp;
            }

            temp=nextNode;
        }

        prevNode->next=NULL;

        return newHead;

    }
};
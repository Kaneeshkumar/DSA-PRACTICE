/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution {
public:
    ListNode* reversed(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* lastNode=reversed(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=NULL;

        return lastNode;




    }
    ListNode *addOne(ListNode *head) {
        
        ListNode* curr=head;
        ListNode* newHead=reversed(curr);
        ListNode* newHead1;
        int cval;
        ListNode* temp=NULL;

        int carry=1;

        while(carry || newHead){
            if(newHead){
                 cval=newHead->val+carry;
            }else{
                cval=carry;
            }

            ListNode* newnode=new ListNode(cval%10);
            if(!temp){
            temp=newnode;
            newHead1=temp;
            }
            else{
            temp->next=newnode;
            temp=newnode;
            }

            carry=cval/10;
            if(newHead)
            newHead=newHead->next;
        }

        ListNode* reversedHead=reversed(newHead1);

        return reversedHead;

    }
};
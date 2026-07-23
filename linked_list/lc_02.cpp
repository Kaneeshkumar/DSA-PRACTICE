

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        

        int carry=0;
        ListNode* head1=l1;
        ListNode* head2=l2; 
        ListNode* prev=NULL;
        ListNode* m;

        while(head1 || head2 || carry){
            int cval=0;
            if(head1){
                cval+=head1->val;
            }

            if(head2){
                cval+=head2->val;
            }

            cval+=carry;
            ListNode* newnode=new ListNode(cval%10);

            if(prev)
            prev->next=newnode;
            else
            m=newnode;

            prev=newnode;

            carry=cval/10;

            if(head1){
                head1=head1->next;
            }

            if(head2){
                head2=head2->next;
            }
        }

        return m;
    }
};
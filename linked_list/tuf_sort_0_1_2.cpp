/*
Definition of singly linked list:
class ListNode{
  public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};
*/

class Solution {
    public:
        ListNode* sortList(ListNode* &head) {
            //your code goes here

            if(!head)
            return NULL;

            ListNode* curr=head;
            ListNode* head0=NULL;
            ListNode* head1=NULL;
            ListNode* head2=NULL;


            ListNode* new0=NULL;
            ListNode* new1=NULL;
            ListNode* new2=NULL;

            while(curr){
                ListNode* nextNode=curr->next;
                if(curr->data==0){
                if(!head0){
                    head0=curr;
                    new0=curr;
                }else if(head0){
                    new0->next=curr;
                    new0=curr;
                }
                }


                 else if(curr->data==1){
                if(!head1){
                    head1=curr;
                    new1=curr;
                }else if(head1){
                    new1->next=curr;
                    new1=curr;
                }
                }

                 if(curr->data==2){
                if(!head2){
                    head2=curr;
                    new2=curr;
                }else if(head2){
                    new2->next=curr;
                    new2=curr;
                }
                }

                    curr=nextNode;
            }

              if(new2)
                new2->next=NULL;
                
                if(new0)
                new0->next= head1 ? head1:head2;

                if(new1){
                    new1->next=head2;
                }


                if(head0)
                return head0;   
                
                else if(head1)
                return head1;

                return head2;


        }
};
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
    ListNode* oddEvenList(ListNode* head) {
        if(!head)
        return NULL;
        
        ListNode* odd=head;
        ListNode* even=head->next;


        ListNode* anotherE=NULL;

        ListNode* newodd=odd;
        ListNode* neweven=NULL;

    


        while(newodd->next){
            if(anotherE!=NULL){
                anotherE->next=newodd->next;
            }

            neweven=newodd->next;
            anotherE=neweven;
            if(neweven->next){
                newodd->next=neweven->next;
            }else{
                break;
            }

            newodd=neweven->next;
        }
        if(anotherE)
        anotherE->next=NULL;
        newodd->next=even;

        return head;
    }
};
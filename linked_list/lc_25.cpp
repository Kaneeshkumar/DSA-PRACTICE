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
private:
    ListNode* findK(ListNode* temp,int k){
        k=k-1;

        while(temp && k!=0){
            temp=temp->next;
            k--;
        }

        return temp;
    }

    void reverseLL(ListNode* temp){

        auto nextNode=temp->next;
        ListNode* head=temp;
        ListNode* nextOne=temp->next;

        while(temp){
            auto nextNode=nextOne;
            if(nextNode){
                nextOne=nextNode->next;
            }
            if(nextNode)
            nextNode->next=temp;
            temp=nextNode;

        }

        if(head)
        head->next=NULL;
        return;
    }
public:

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)
        return NULL;

        ListNode* temp=head;
        ListNode* prev=NULL;
        ListNode* nextNode;

        while(temp){

            auto kth=findK(temp,k);

            if(!kth){
                if(prev){
                    prev->next=nextNode;
                }
                break;
            }else{
                nextNode=kth->next;
                kth->next=NULL;

                reverseLL(temp);
                if(prev!=NULL){
                    prev->next=kth;
                }else{
                    head=kth;
                }

                prev=temp;
                temp=nextNode;
            }
        }

        return head;

    }
};
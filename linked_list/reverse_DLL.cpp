/*
class ListNode {
public:
    int data;
    ListNode* prev;
    ListNode* next;

    ListNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};
*/

class Solution {
public:
    ListNode* reverseDLL(ListNode* head) {
        // Your code goes here
        ListNode* temp=head;
        ListNode* tail=head;

        while(tail->next!=NULL){
            tail=tail->next;
        }

        while(tail!=temp){
            int var=temp->data;
            temp->data=tail->data;
            tail->data=var;

            temp=temp->next;
            if(temp==tail)
            break;
            tail=tail->prev;
        }

        return head;

    }
};
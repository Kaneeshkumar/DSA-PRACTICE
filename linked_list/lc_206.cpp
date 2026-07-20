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
    ListNode* reverseList(ListNode* head) {
        if(!head)
        return NULL;

        ListNode* curr=head;
        ListNode* nextNode=head->next;
        curr->next=NULL;

        while(nextNode){
            ListNode* succ=nextNode->next;
            nextNode->next=curr;
            curr=nextNode;
            nextNode=succ;
        }

        return curr;


    }
};
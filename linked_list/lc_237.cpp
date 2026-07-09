/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
     
       ListNode* currNode=node;
       ListNode* prev;
     while(currNode!=NULL){
        ListNode* nextNode=currNode->next;

        if(nextNode)
        currNode->val=nextNode->val;

        else{
            prev->next=NULL;
        break;
        }

        prev=currNode;
        currNode=nextNode;
     }
     
    }
};
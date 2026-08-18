/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        Node* newHead=NULL;

        while(temp){ //making a copyNode for every temp node between the original temp and its next
            Node* nextNode=temp->next;
            Node* newnode=new Node(temp->val);
            if(temp==head){
                newHead=newnode;
            }
            temp->next=newnode;
            newnode->next=nextNode;

            temp=nextNode;
        }


        temp=head;

        while(temp){ //linking the random ptr of copyNode based on the original
            Node* copyNode=temp->next;
            Node* randomPtr=temp->random;

            if(randomPtr)
            copyNode->random=randomPtr->next;
            else
            copyNode->random=NULL;

            temp=temp->next->next;
        }


        temp=head;
        Node* dummy=new Node(-1);
        Node* res=dummy;

        while(temp){ //connecting the next ptr by using a dummy node
            res->next=temp->next;
            res=temp->next;
            temp->next=temp->next->next;
            temp=temp->next;
        }

        Node* newHead1=dummy->next;
        delete dummy;

        return newHead1;

    }
};
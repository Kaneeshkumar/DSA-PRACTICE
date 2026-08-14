
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
        ListNode* rotateRight(ListNode* head, int k) {
            if(!head)
            return NULL;
            
            vector<ListNode*> nums;
            ListNode* temp=head;
            int cnt=0;

            while(temp){
                cnt++;
                nums.push_back(temp);
                temp=temp->next;
            }

            int n=nums.size();
            k=k%cnt;

            while(k){
                ListNode* lastNode=nums[nums.size()-1];
                ListNode* llastNode=nums[nums.size()-2];

                llastNode->next=NULL;
                lastNode->next=head;
                head=lastNode;

                k--;
                nums.pop_back();
            }

            return head;
        }
    };
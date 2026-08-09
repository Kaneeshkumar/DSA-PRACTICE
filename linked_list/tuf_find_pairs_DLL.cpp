    /*
    class ListNode {
    public:
        int val;
        ListNode* next;
        ListNode* prev; 

        ListNode(int value) : val(value), next(nullptr), prev(nullptr) {}

        ~ListNode() {
            delete next;
        }
    };
    */

    class Solution {
    public:
        vector<vector<int>> findPairsWithGivenSum(ListNode* head, int target) {
            // Your code goes here

            ListNode* start=head;
            ListNode* end=head;
            vector<vector<int>> ans;

            while(end->next!=NULL){
                end=end->next;
            }

            while(start!=end){
                int first=start->val;
                int second=end->val;
                int cval=first+second;

                if(cval==target){
                    ans.push_back({first,second});
                    start=start->next;
                    if(start==end)
                    break;
                    end=end->prev;          
                }else if(cval<target){
                    start=start->next;
                }else
                end=end->prev;
            }


            return ans;


        }
    };
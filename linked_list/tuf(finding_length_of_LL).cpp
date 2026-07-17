#include<bits/stdc++.h>
class Solution {
public:
    int getLength(ListNode* head) {
        // Your code goes here
        int cnt=0;
        ListNode* head1=head;
        while(head1){
            cnt++;
            head1=head1->next;
        }

        return cnt;
    }
};

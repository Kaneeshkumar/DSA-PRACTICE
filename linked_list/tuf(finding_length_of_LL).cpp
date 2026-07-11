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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        // your code here
            if(!root)
            return 0;


            int lh=calcLH(root->left);
            int rh=calcRH(root->right);

            if(lh==rh)
            return pow(2,lh)-1;



        
    }
};
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
 class Box{
    public:
    int maxi,mini,sum;
    bool isBST;
    Box(){
        maxi=INT_MIN;
        mini=INT_MAX;
        sum=0;
        isBST=true;
    }
 };
 Box* findmax(TreeNode* root,int& ts){
    if(!root){
      return  new Box();
    }else{
       auto l=findmax(root->left,ts);
      auto r=findmax(root->right,ts);

      if(l->isBST && r->isBST && l->maxi<root->val && r->mini>root->val){
        int ts1=root->val+l->sum+r->sum;
        Box* b1=new Box();
        b1->sum=root->val+l->sum+r->sum;
        b1->maxi=max(root->val,r->maxi);
        b1->mini=min(root->val,l->mini);
        ts=max(ts,b1->sum);
        return b1;
      }else{
        Box* b2=new Box();
        b2->maxi=INT_MAX;
        b2->mini=INT_MIN;
        b2->isBST=false;
        return b2;
      }

    }
 }
 
class Solution {
public:
    int maxSumBST(TreeNode* root) {
        int ts=0;
        findmax(root,ts);
        return ts;
    }
};
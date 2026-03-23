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
    // void inorder1(TreeNode* root,vector<int>& ans,int &i){
    //     if(!root)
    //     return;

    //     inorder1(root->left,ans,i);
    //     root->val=ans[i++];
    //     inorder1(root->right,ans,i);
    // }
    // void inorder(TreeNode* root,vector<int>& ans){
    //     if(!root)
    //     return;

    //     inorder(root->left,ans);
    //     ans.push_back(root->val);
    //     inorder(root->right,ans);
    // }
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;
    TreeNode* first;
    void inorder1(TreeNode* root){
        if(!root)
        return ;

        inorder1(root->left);
        if(root->val<prev->val){
            if(!first){
            first=prev;
            middle=root;
        }else{
            last=root;
        }
        }
        prev=root;
        inorder1(root->right);
    }

      
    void recoverTree(TreeNode* root) {
        // vector<int> ans;
        // int i=0;
        // inorder(root,ans);
        // sort(ans.begin(),ans.end());

        // inorder1(root,ans,i);
        // return;
      
     first=last=NULL;
      prev=new TreeNode(INT_MIN);
      inorder1(root);

      if(first && last)
      swap(first->val,last->val);
      else
      swap(first->val,middle->val);
      return;


    }
};
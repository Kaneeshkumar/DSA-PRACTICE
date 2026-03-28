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
    TreeNode* bst(vector<int>& preorder,int& i,int maxi){
        if(i==preorder.size() || preorder[i]>maxi)
        return NULL;

        TreeNode* root=new TreeNode(preorder[i++]);
        root->left=bst(preorder,i,root->val);
        root->right=bst(preorder,i,maxi);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // TreeNode* root=new TreeNode(preorder[0]);
        // for(int i=1;i<preorder.size();i++){
        //     TreeNode* newnode=new TreeNode(preorder[i]);
        //     TreeNode* start=root;
        //     TreeNode* prev=NULL;
        //     while(root){
        //         prev=root;
        //         if(root->val>preorder[i])
        //         root=root->left;
        //         else
        //         root=root->right;
        //     }
        //     if(preorder[i]>prev->val)
        //     prev->right=newnode;
        //     else
        //     prev->left=newnode;
        //     root=start;
        // }
        // return root;
        int i=0;
        return bst(preorder,i,INT_MAX);
    }
};
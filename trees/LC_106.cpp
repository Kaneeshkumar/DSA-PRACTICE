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
    TreeNode* createTree(vector<int>& inorder,int inst,int inend,vector<int>& postorder,int postst,int postend,unordered_map<int,int>& m){
        if(inst>inend || postst>postend){
            return NULL;
        }

        TreeNode* root=new TreeNode(postorder[postend]);
        int curridx=m[root->val];
        int numleft=curridx-inst;

        root->left=createTree(inorder,inst,curridx-1,postorder,postst,postst+numleft-1,m);
        root->right=createTree(inorder,curridx+1,inend,postorder,postst+numleft,postend-1,m);
        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>m;
        int i=0;
        for(int val:inorder){
            m[val]=i;
            i++;
        }
        return createTree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,m);
    }
};
/**
 * Definition for an n-ary tree node.
 * class TreeNode {
 * public:
 *     int val;
 *     vector<TreeNode*> children;
 * 
 *     TreeNode() {}
 * 
 *     TreeNode(int _val) {
 *         val = _val;
 *     }
 * 
 *     TreeNode(int _val, vector<TreeNode*> _children) {
 *         val = _val;
 *         children = _children;
 *     }
 * };
 **/

class Solution {
public:
    TreeNode* cloneTree(TreeNode* root) {
       if(!root)
       return NULL;

       queue<pair<TreeNode*,TreeNode*>> q,nq;
       q.push({root,NULL});
       TreeNode* nroot=new TreeNode(root->val);
       nq.push({nroot,NULL});


       while(!q.empty()){
        auto front=q.front();
        auto nfront=nq.front();

        auto child=front.first;
        auto par=front.second;
        auto nchild=nfront.first;
        auto npar=nfront.second;

        q.pop();
        nq.pop();

        if(npar){
            npar->children.push_back(nchild);
        }

        for(auto it:child->children){
            q.push({it,child});
            TreeNode* newChild=new TreeNode(it->val);
            nq.push({newChild,nchild});
        }

       }

       return nroot;
    }
};
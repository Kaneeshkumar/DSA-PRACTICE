/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        unordered_map<int,TreeNode*> m;
//         TreeNode* curr=root;

//         while(root && root->val!=p->val){
//             m[root->val]=root;
//             if(p->val<root->val){
//                 root=root->left;
//             }else{
//                 root=root->right;
//             }
//         }
//         if(!root)
//         return NULL;

//         m[p->val]=p;
//         TreeNode* ans=NULL;

//         while(curr && curr->val!=q->val){
//             if(m.find(curr->val)!=m.end()){
//                 ans=m[curr->val];
//             }else{
//                 m[curr->val]=curr;
//             }
//             if(q->val<curr->val){
//                 curr=curr->left;
//             }else{
//                 curr=curr->right;
//             }
//         }
//         if(m.find(curr->val)!=m.end())
//                 ans=m[curr->val];
//         if(!ans && curr->val==q->val){
//             return curr;
//         }
// return ans;

while(root){
    if(p->val<root->val && q->val<root->val){
        root=root->left;
    }else if(p->val>root->val && q->val>root->val){
        root=root->right;
    }else{
        return root;
    }
}
      return NULL;
}
};
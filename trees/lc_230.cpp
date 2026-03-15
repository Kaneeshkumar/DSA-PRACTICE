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
    int addinto(TreeNode* root,vector<int>& ans){
        if(root==NULL){
            return 0;
        }
        int a1=addinto(root->left,ans);
        int a2=addinto(root->right,ans);
        ans.push_back(root->val);
        return root->val;
    }
    int kthSmallest(TreeNode* root, int k) {
    //     vector<int> ans;
    //    int notans= addinto(root,ans);
    //     sort(ans.begin(),ans.end());
    //     int y=0;
    //     for(int val:ans){
    //         y++;
    //         if(y==k){
    //             return val;
    //         }
    //     }
    //     return -1;

    stack<TreeNode*> s;
    while(true){
        while(root){
            s.push(root);
            root=root->left;
        }
        root=s.top();
        s.pop();
        k--;
        if(k==0){
            return root->val;
        }
        root=root->right;

    }
    return -1;
    }
};
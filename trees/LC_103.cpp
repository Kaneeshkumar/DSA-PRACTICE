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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
                vector<vector<int>> ans1;
        if(root==NULL){
            return ans;
        }
        stack<TreeNode*> s;
        s.push(root);
        int k=0;
        
        ans.push_back({root->val});

        while(!s.empty()){
            int sz=s.size();
            vector<int> v;
            vector<TreeNode*> v1;

            if(k%2==0){
            for(int i=0;i<sz;i++){
                TreeNode* curr=s.top();
                if(curr->right){
                v.push_back(curr->right->val);
                v1.push_back(curr->right);
            }if(curr->left){
                  v.push_back(curr->left->val);
                v1.push_back(curr->left);
                
            }
            s.pop();
            }
            }else{
                 for(int i=0;i<sz;i++){
                TreeNode* curr=s.top();
                if(curr->left){
                v.push_back(curr->left->val);
                v1.push_back(curr->left);
                }
                if(curr->right){
                v.push_back(curr->right->val);
                v1.push_back(curr->right);
                 }
                s.pop();
            }
            }
            ans.push_back(v);
            for(auto it:v1){
                s.push(it);
            }
            k++;
        }
        int i=0;
        for(auto it:ans){
            if(i!=ans.size()-1){
                ans1.push_back(it);
            }
            i++;
        }
        return ans1;
    }
};
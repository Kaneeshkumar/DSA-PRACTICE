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
    void markParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& m){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto curr=q.front();
                q.pop();

                if(curr->left){
                    m[curr->left]=curr;
                    q.push(curr->left);
                }

                
                if(curr->right){
                    m[curr->right]=curr;
                    q.push(curr->right);
                }
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(!root){
            return ans;
        }
        unordered_map<TreeNode*,TreeNode*> m;
        markParents(root,m);

        queue<TreeNode*> q;
        unordered_map<TreeNode*,bool> visited;
        q.push(target);
        visited[target]=true;
        int level=0;

        while(!q.empty()){
            int sz=q.size();
            if(level++==k)
            break;
            for(int i=0;i<sz;i++){
                auto curr=q.front();
                q.pop();

                if(curr->left && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left]=true;
                }

                  if(curr->right && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right]=true;
                }


                if(m[curr] && !visited[m[curr]]){
                    q.push(m[curr]);
                    visited[m[curr]]=true;
                }

            }
        }

        
        while(!q.empty()){
            auto curr=q.front();
            ans.push_back(curr->val);
            q.pop();
        }

        return ans;

         
    }
};
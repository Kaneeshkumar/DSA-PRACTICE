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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root){
            return ans;
        }
        queue<pair<int,TreeNode*>>q;
        q.push({0,root});
        map<int,int> m;

        while(!q.empty()){
            auto front=q.front();
            int x=front.first;
            auto node=front.second;
            q.pop();

            m[x]=node->val;
            if(node->left){
                q.push({x+1,node->left});
            }
            if(node->right){
                q.push({x+1,node->right});
            }

        }
        for(auto it:m){
            ans.push_back(it.second);
        }
        return ans;
    }
};
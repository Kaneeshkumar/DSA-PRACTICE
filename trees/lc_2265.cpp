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
    int cnt=0;
    pair<int,int> calcNodes(TreeNode* root){
        if(!root)
        return {0,0};

        auto left=calcNodes(root->left);
        auto right=calcNodes(root->right);

        int totalNodes=left.first+right.first+1;
        int csum=root->val+left.second+right.second;

        if(csum/totalNodes==root->val)
        cnt++;

        return {totalNodes,csum};




    }
    int averageOfSubtree(TreeNode* root) {
        auto notAns=calcNodes(root);
        return cnt;
    }
};
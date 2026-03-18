/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
	public:
		vector<int> succPredBST(TreeNode* root,int key){
			//your code goes here
            TreeNode* curr=root;
            int successor=-1,predeccessor=-1;

            while(root){
                if(root->data<=key)
                root=root->right;
                else if(root->data>key){
                    successor=root->data;
                    root=root->left;
                }

            }

             while(curr){
                if(curr->data>=key)
                curr=curr->left;
                else if(curr->data<key){
                    predeccessor=curr->data;
                    curr=curr->right;
                }

            }
            return {predeccessor,successor};
		}
};
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{	
	public:
         int calcceil(TreeNode* root,int key){
            if(!root)
            return -1;
            int prev=-1;
            
            while(root){
                if(root->data==key){
                    prev=key;
                    break;
                }
                if(root->data<key){

                root=root->right;
                }else{
                    prev=root->data;
                    root=root->left;
                }

            }
            return prev;
        }
        int calcfloor(TreeNode* root,int key){
            if(!root)
            return -1;
            int prev=-1;
            
            while(root){
                if(root->data==key){
                    prev=root->data;
                    break;
                }
                if(root->data>key){

                root=root->left;
                }else{
                                        prev=root->data;

                    root=root->right;
                }

            }
            return prev;
        }
		vector<int> floorCeilOfBST(TreeNode* root,int key){
			//your code goes here
            vector<int> ans;
            TreeNode* curr=root;
            int floor=calcfloor(root,key);
            int ceil=calcceil(curr,key);
            ans.push_back(floor);
            ans.push_back(ceil);
            return ans;

		}
};
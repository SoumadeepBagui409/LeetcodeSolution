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
    int ans(TreeNode* root,string val){
        if(root->left==NULL and root->right==NULL){
            if(val == "left"){
                return root->val;
            }
            return 0;
        }
        int value = 0;
        if(root->left!=NULL){
            value = value + ans(root->left,"left");
        }
        if(root->right!=NULL){
            value = value + ans(root->right, "right");
        }
        return value;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return ans(root,"root");
    }
};
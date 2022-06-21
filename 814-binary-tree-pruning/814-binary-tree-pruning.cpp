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
    int dfs(TreeNode* root){
        if(root==NULL)return 0;
        if(root->left==NULL and root->right==NULL)return root->val;
        int op1,op2;
        op1 = dfs(root->left);
        op2 = dfs(root->right);
        if(op1==0){
            root->left=NULL;
        }
        if(op2 == 0){
            root->right=NULL;
        }
        return max(op1,max(op2,root->val));
    }
    TreeNode* pruneTree(TreeNode* root) {
        int value = dfs(root);
        if(value==0){
            return NULL;
        }
        return root;
    }
};
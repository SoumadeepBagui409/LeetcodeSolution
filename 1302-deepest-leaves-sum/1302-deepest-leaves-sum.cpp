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
        int op1,op2;
        op1 = op2 = 0;
        op1 = dfs(root->left);
        op2 = dfs(root->right);
        return 1 + max(op1,op2);
    }
    int cal(TreeNode* root, int MaxHeight,int CurrHeight){
        if(CurrHeight==MaxHeight-1 and root!=NULL){
            return root->val;
        }
        if(root==NULL){
            return 0;
        }
        int op1,op2;
        op1 = op2 = 00;
        op1 = cal(root->left,MaxHeight,CurrHeight+1);
        op2 = cal(root->right,MaxHeight,CurrHeight+1);
        return op1 + op2;
    }
    int deepestLeavesSum(TreeNode* root) {
       int Maxheight = dfs(root); 
        return cal(root,Maxheight,0);
    }
};
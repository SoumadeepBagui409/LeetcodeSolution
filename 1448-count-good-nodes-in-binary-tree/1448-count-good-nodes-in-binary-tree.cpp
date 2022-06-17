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
    int recCur(TreeNode* root,int mini){
        if(root == NULL)return 0;
        int op1,op2;
        op1 = op2 = 0;
        int check = (mini<=root->val);
        if(root->left!=NULL){
            op1 = recCur(root->left,max(mini,root->val));
        }if(root->right!=NULL){
            op2 = recCur(root->right,max(mini,root->val));
        }
        return op1 + op2 + check;
    }
    int goodNodes(TreeNode* root) {
        int ans = recCur( root , -100000 );
        return ans;
    }
};
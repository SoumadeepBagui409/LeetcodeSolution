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
    int allPos(TreeNode* root, int value){
        if(root==NULL){
            return 0;
        }
        int currVal = abs(value-root->val);
        int op1 = allPos(root->left,value);
        int op2 = allPos(root->right,value);
        
        return max(op1,max(op2,currVal));
    }
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL){
            return INT_MIN;
        }
        
        int value = root->val;
        
        int op1,op2;
        op1 = allPos(root->left,value);
        op2 = allPos(root->right,value);
        
        int op3,op4;
        op3 = maxAncestorDiff(root->left);
        op4 = maxAncestorDiff(root->right);
        
        return max(op1,max(op2,max(op3,op4)));
    }
};
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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        if(cloned==NULL)return NULL;
        TreeNode* value1;
        TreeNode*value2;
        value1 = value2 = NULL;
        if(target->val==cloned->val)return cloned;
        if(cloned->left!=NULL){
            value1 = getTargetCopy(original,cloned->left,target);
        }
        if(cloned->right!=NULL){
            value2 = getTargetCopy(original,cloned->right,target);
        }
        if(value1!=NULL)
        return value1;
        if(value2!=NULL)
            return value2;
        return NULL;
        
    }
};
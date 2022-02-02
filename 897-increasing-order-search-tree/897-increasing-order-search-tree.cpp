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
    void inOrder(vector<int> &val,TreeNode* root){
        if(root==NULL){
            return;
        }
        inOrder(val,root->left);
        //cout<<root->val<<" ";
        val.push_back(root->val);
        inOrder(val,root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> val;
        inOrder(val,root);
        TreeNode *head = new TreeNode;
        TreeNode *thead = head;
       //cout<<val.size();
        for(int i = 0;i<val.size();i++){
            thead->val = val[i];
            if(val.size()-1!=i){
                thead->right = new TreeNode;
                thead = thead->right;
            }
        }
        return head;
    }
};
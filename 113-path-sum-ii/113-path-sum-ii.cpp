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
    vector<vector<int>> ans;
    vector<int> tvl;
public:
    bool cal(TreeNode* root,int sum,int currSum){
        if(root->left==NULL and root->right==NULL){
            if(sum==currSum+root->val){
                tvl.push_back(root->val);
                ans.push_back(tvl);
                tvl.pop_back();
                return true;
            }
            return false;
        }
        bool op1,op2;
        op1 = op2 = false;
        tvl.push_back(root->val);
        if(root->left){
              op1 = cal(root->left,sum,currSum + root->val);
        }
        if(root->right)
        op2 = cal(root->right,sum,currSum+root->val);
        tvl.pop_back();
        return op1 | op2;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            vector<vector<int>> grb;
            return grb;
        }
        bool ans1 = cal(root,targetSum,0);
        return ans;
    }
};
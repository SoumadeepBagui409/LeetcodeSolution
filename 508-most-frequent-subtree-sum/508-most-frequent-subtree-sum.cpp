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
    map<int,int> freq;
    vector<int> value;
public:
    int dfsSum(TreeNode* root){
        if(root==NULL){
          return 0;  
        }
        int op1 = dfsSum(root->left);
        int op2 = dfsSum(root->right);
        int sum = op1 + op2 + root->val;
        if(freq.find(sum)==freq.end())
        value.push_back(sum);
        freq[sum]++;
        
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int val = dfsSum(root);
        vector<int> ans;
        int MaxFreq = INT_MIN;
        for(auto x:freq){
            MaxFreq = max(MaxFreq,x.second);
        }
        for(auto x:value){
            if(freq[x]==MaxFreq){
                ans.push_back(x);
            }
        }
        return ans;
    }
};
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
    int dfsUptoTwo(TreeNode* node, int step){
        if(node==NULL)return 0;
        if(step==2){
           return node->val;
        }
        int op1,op2;
        op1 = op2 = 0;
        if(node->left!=NULL){
            op1 += dfsUptoTwo(node->left,step+1);
        }
        if(node->right!=NULL){
            op2+=dfsUptoTwo(node->right,step+1);
        }
        return op1 + op2;
    }
    int sumEvenGrandparent(TreeNode* root) {
        vector<TreeNode*> AllRoots;
        queue<TreeNode*> CurrNodeHolder;
        CurrNodeHolder.push(root);
        while(!CurrNodeHolder.empty()){
            auto currNode = CurrNodeHolder.front();
            if(currNode->val%2==0){
                AllRoots.push_back(currNode);
            }
            CurrNodeHolder.pop();
            if(currNode->left!=NULL){
                CurrNodeHolder.push(currNode->left);
            }
            if(currNode->right!=NULL){
                CurrNodeHolder.push(currNode->right);
            }
        }
        int ans = 0;
        for(auto x:AllRoots){
            
            ans+=dfsUptoTwo(x,0);
        }
        return ans;
    }
};
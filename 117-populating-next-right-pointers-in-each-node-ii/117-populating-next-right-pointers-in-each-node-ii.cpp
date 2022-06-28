/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
        {
            return root;
        }
        map<int,vector<Node*>> HorzLyr;
        queue<pair<Node*,int>> tvl;
        tvl.push({root,1});
        while(!tvl.empty()){
            pair<Node*,int> ans = tvl.front();
            tvl.pop();
            Node* currNode = ans.first;
            int level = ans.second;
            HorzLyr[level].push_back(currNode);
            if(currNode->left!=NULL){
               tvl.push({currNode->left,level+1});
            }
            if(currNode->right!=NULL){
                tvl.push({currNode->right,level+1});
            }
        }
        for(auto x:HorzLyr){
            
            vector<Node*> currLayer = x.second;
            for(int i = 1; i<currLayer.size();i++){
                currLayer[i-1]->next = currLayer[i];
            }
            currLayer[currLayer.size()-1]->next = NULL;
        }
        return root;
    }
};
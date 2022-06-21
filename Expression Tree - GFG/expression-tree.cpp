// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct node {
    string data;
    struct node *left;
    struct node *right;

    node(string x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

bool isExpression(string &s) {
    if (s == "+" or s == "-" or s == "*" or s == "/") return true;
    return false;
}



 // } Driver Code Ends
/*The structure of node is as follows
struct node{
    string data;
    node *left;
    node *right;
};
*/

class Solution{
  public:
    /*You are required to complete below method */
    int cal(int op1,int op2,string ch){
       
        if(ch=="+")return op1 + op2 ;
        else if(ch== "-")return op1 - op2;
        else if (ch=="/")return op1/op2;
        else if(ch=="*") return op1 * op2;
    }
    int dfsCal(node* root){
        if(root->left==NULL and root->right==NULL){
          
        return stoi(root->data);
    }
    int op1 = dfsCal(root->left);
    int op2 = dfsCal(root->right);
    int ans = cal(op1,op2,root->data);
   
    return ans;
    }
    int evalTree(node* root) {
       return dfsCal(root);
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s[n];
        for (int i = 0; i < n; i++) cin >> s[i];

        int p = 0;
        node *root = new node(s[p++]);
        queue<node *> q;
        q.push(root);
        while (!q.empty()) {
            node *f = q.front();
            q.pop();
            node *l, *r;
            if (isExpression(f->data)) {
                l = new node(s[p++]);
                r = new node(s[p++]);
                f->left = l;
                f->right = r;
                q.push(l);
                q.push(r);
            }
        }
        Solution obj;
        cout << obj.evalTree(root) << endl;
    }
}
  // } Driver Code Ends
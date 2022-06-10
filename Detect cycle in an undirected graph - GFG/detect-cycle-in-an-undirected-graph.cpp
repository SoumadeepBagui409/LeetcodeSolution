// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V,0);
        for(int i = 0;i<V;i++){
            if(visited[i])continue;
            queue<pair<int,int>> tvl;
        tvl.push({i,i});
        visited[i] = true;
        while(!tvl.empty()){
            auto curr = tvl.front();
            tvl.pop();
            for(auto ngb: adj[curr.first]){
                if(!visited[ngb]){
                    visited[ngb] = true;
                    tvl.push({ngb,curr.first});
                }else if(visited[ngb] and ngb!=curr.second)return true;
            }
        }
    
        }
        
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends
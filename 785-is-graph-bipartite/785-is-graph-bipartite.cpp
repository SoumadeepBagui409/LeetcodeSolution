class Solution {
public:
    bool dfs(vector<vector<int>>& graph,int src,vector<int> &value,int curr){
        value[src] = curr;
        bool ans = true;
        for(auto x:graph[src]){
            if(value[x] == -1){
                ans = ans & dfs(graph,x,value,!curr);
            }
            if(value[x]== curr)return false;
        }
        return ans;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size() - 1;
        vector<int> value(graph.size(),-1);
        bool ans = true;
        for(int i = 0;i<=n;i++){
            if(value[i] == -1)
            ans = ans & dfs(graph, i, value,0);
        }
        return ans;
        
    }
};
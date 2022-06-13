class Solution {
public:
    bool cycle(map<int,vector<int>> &adj,int src,vector<bool> &visited, map<int,bool> &pathChecker){
        visited[src] = true;
        pathChecker[src] = true;
        bool ans = false;
        for(auto x:adj[src]){
            if(!visited[x]){
                ans = ans | cycle(adj,x,visited,pathChecker); 
            }else if(pathChecker[x]){
                    return true;
            }
        }
        return ans;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int,vector<int>> adj;
        for(auto x:prerequisites){
            adj[x[1]].push_back(x[0]);
        }
        map<int,bool> pathCheck;
        vector<bool> visited(numCourses,-1);
        bool aCyclic = true;
        for(int i = 0;i<numCourses;i++){
            if(!visited[i])
            aCyclic = aCyclic & !cycle(adj,i,visited,pathCheck);
        }
        if(!aCyclic){
            vector<int> garbage;
            return garbage;
        }
        vector<int> inOrder(numCourses,0);
        for(int i = 0 ; i < numCourses; i++){
            for(auto x:adj[i]){
                inOrder[x]++;
            }
        }
        vector<int> finalAns;
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > queue;
        for(int i = 0 ; i < numCourses; i++){
            if(inOrder[i]==0){
                queue.push({inOrder[i],i});
            }
        }
        
        while(!queue.empty()){
            auto currNode = queue.top();
            queue.pop();
            finalAns.push_back(currNode.second);
            for(auto x:adj[currNode.second]){
                inOrder[x]--;
                if(inOrder[x]==0){
                    queue.push({inOrder[x],x});
                }
            }
        }
        if(finalAns.size()!=numCourses){
            vector<int> val;
            return val;
        }
        return finalAns;
        
    }
};
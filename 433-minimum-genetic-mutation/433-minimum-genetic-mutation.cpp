class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        vector<char> alpha = {'A','C','G','T'};
        set<string> genes ;
        map<string,bool> visited;
        for(auto x:bank){
            genes.insert(x);
            visited[x] = false;
        }
        queue<pair<string,int>> tvl;
        tvl.push({start,0});
        visited[start] = true;
        while(!tvl.empty()){
            auto currDna = tvl.front();
            tvl.pop();
            string s = currDna.first;
            if(s==end){
                return currDna.second;
            }
            for(int i = 0;i<s.size();i++){
                for(auto x:alpha){
                    s[i] = x;
                    if(s!=currDna.first and genes.find(s)!=genes.end() and !visited[s]){
                        visited[s]=true;
                        tvl.push({s,currDna.second+1});
                    }
                }
                s = currDna.first;
            }
        }
        return -1;
    }
};
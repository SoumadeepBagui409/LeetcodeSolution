class Solution {
public:
    int max(int a,int b){
        return(a>b)?a:b;
    }
    int maxDistance(vector<vector<int>>& grid) {
        vector<vector<int>>dir = {{-1,0},{1,0},{0,-1},{0,1}};
        queue<vector<int>> tvl;
        bool isIn = false;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    vector<int> cal;
                    cal.push_back(i);
                    cal.push_back(j);
                    cal.push_back(0);
                    tvl.push(cal);
                }
            }
        }
        int a = -1;
        while(!tvl.empty()){
            auto ans = tvl.front();
            tvl.pop();
            for(auto x:dir){
                int x1 = ans[0]+x[0];
                int y1 = ans[1]+x[1];
                int level = ans[2];
                if(x1>=0 and x1<grid.size() and y1>=0 and y1<grid[0].size() and grid[x1][y1]==0){
                    grid[x1][y1] = level+1;
                    a = max(grid[x1][y1],a);
                    vector<int> nextPos;
                    nextPos.push_back(x1);
                    nextPos.push_back(y1);
                    nextPos.push_back(grid[x1][y1]);
                    tvl.push(nextPos);
                }
            }
        }
        // for(auto x:grid){
        //     for(auto y:x){
        //         cout<<y<<" ";
        //     }
        //     cout<<"\n";
        // }
        return a;
    }
};
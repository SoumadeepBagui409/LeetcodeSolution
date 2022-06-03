class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> direction = {{-1,0},{1,0},{0,-1},{0,1}};
        int freshOranges = 0;
        queue<vector<int>> que;
        for(int i =0;i<grid.size();i++){
            for(int j = 0;j<grid[i].size();j++){
                if(grid[i][j]==2){
                    vector<int> val;
                    val.push_back(i);
                    val.push_back(j);
                    val.push_back(0);
                    que.push(val);
                }
                    
                freshOranges += (grid[i][j]==1);
            }
        }
        int ans = 0;
        while(!que.empty()){
            auto currOrange = que.front();
            que.pop();
            int posX = currOrange[0];
            int posY = currOrange[1];
            int level = currOrange[2];
            ans = max(ans,level);
            for(auto x:direction){
                int x1 = posX + x[0];
                int y1 = posY + x[1];
                if(x1>=0 and x1<grid.size() and y1>=0 and y1<grid[0].size() and grid[x1][y1]==1){
                   vector<int> val;
                    val.push_back(x1);
                    val.push_back(y1);
                    val.push_back(level+1);
                    que.push(val);
                    grid[x1][y1] = 2;
                    freshOranges--;
                
                }
            }
            
        }
    
        if(freshOranges==0)
        return ans;
        return -1;
    }
};
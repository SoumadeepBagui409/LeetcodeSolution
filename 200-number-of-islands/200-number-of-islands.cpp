class Solution {
    vector<vector<int>> direction;
    int rowSize;
    int colSize;
public:
    Solution(){
        direction = {{-1,0},{1,0},{0,-1},{0,1}};
    }
    bool isInside(int x,int y){
        if(x>=0 and x<rowSize and y>=0 and y<colSize){
            return true;
        }
        return false;
    }
    void dfs(vector<vector<char>> &grid,int i,int j){
        
        grid[i][j] = '0';
        
        for(auto x1:direction){
            int x = i+x1[0];
            int y = j+x1[1];
            if(isInside(x,y) and grid[x][y]=='1'){
                dfs(grid,x,y);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        rowSize = grid.size();
        colSize = grid[0].size();
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[i].size();j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(grid,i,j);
                }
            }
        }
        return ans;
    }
};
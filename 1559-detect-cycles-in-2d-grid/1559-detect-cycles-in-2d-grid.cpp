class Solution {
    vector<vector<int>> direction;
public:
    Solution(){
        direction = {{-1,0},{1,0},{0,-1},{0,1}};
    }
    bool isInside(int x,int y,vector<vector<char>> &grid){
        if(x>=0 and x<grid.size() and y>=0 and y<grid[0].size())return true;
        return false;
    }
    bool isParent(int parentI,int parentJ,int i,int j){
        if(parentI==i and parentJ==j)return false;
        return true;
    }
    bool cycle(vector<vector<char>>&grid,int i,int j,int parentI,int parentJ,int change,char alpha){
        //cout<<i<<" "<<j<<"\n";
        grid[i][j] = alpha - change;
        bool ans = false;
        for(auto direct: direction){
            int x1 = i + direct[0];
            int y1 = j + direct[1];
            if(isInside(x1,y1,grid) and isParent(parentI,parentJ,x1,y1) and grid[x1][y1] == alpha){
                
                auto currPos = cycle(grid,x1,y1,i,j,change,alpha);
                ans = ans | currPos;
            }else if(isInside(x1,y1,grid) and  isParent(parentI,parentJ,x1,y1)  and grid[x1][y1] == alpha - change){
                //cout<<i<<" "<<j<<" "<<x1<<" "<<y1<<" "<<parentI<<" "<<parentJ<<"\n";
                return true;
            }
        }
        return ans;
    }
    void display(vector<vector<char>> &grid){
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[i].size();j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int change = 'a'-'A';
        bool ans =false;
        for(int i = 0; i<grid.size();i++){
            for(int j = 0 ;j<grid[i].size() ; j++){
                if(grid[i][j]>='a'){
                bool check = cycle(grid,i,j,-1,-1,change,grid[i][j]);
                ans = ans | check;
                   //display(grid);
                    //cout<<"\n";
                }
                //cout<<"\n";
            }
        }
       // cout<<"\n";
        return ans;
    }
};
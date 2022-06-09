class Solution {
    vector<vector<int>> direction;
public:
    Solution(){
        direction = {{-1,0},{1,0},{0,-1},{0,1}};
    }
    void dfs(vector<vector<char>> &board, int i,int j){
        board[i][j] = '1';
        for(auto x1:direction){
            int x = i + x1[0];
            int y = j + x1[1];
            if(x>=0 and x<board.size() and y>=0 and y<board[0].size() and board[x][y]=='O'){
                dfs(board,x,y);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        vector<pair<int,int>> value;
        for(int i =0;i<board.size();i++){
            if(board[i][0]=='O')
            value.push_back({i,0});
        }
        for(int i =0;i<board.size();i++){
            if(board[i][board[0].size()-1]=='O')
            value.push_back({i,board[0].size()-1});
        }
        for(int i = 0;i<board[0].size();i++){
            if(board[0][i]=='O')
            value.push_back({0,i});
        }
        for(int i = 0;i<board[0].size();i++){
            if(board[board.size()-1][i]=='O')
            value.push_back({board.size()-1,i});
        }
        for(auto x:value){
            if(board[x.first][x.second]=='O')
            dfs(board,x.first,x.second);
        }
        // for(auto x:board){
        //     for(auto y:x){
        //         cout<<y<<" ";
        //     }
        //     cout<<"\n";
        // }
        for(int i =0;i<board.size();i++){
            for(int j = 0;j<board[i].size();j++){
                if(board[i][j]=='1'){
                    board[i][j] = 'O';
                }
                else if(board[i][j]=='O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
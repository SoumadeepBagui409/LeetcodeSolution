class Solution {
    vector<vector<int>> direction;
public:
    Solution(){
        direction = {{-1,0},{1,0},{0,1},{0,-1}};
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> pacific(heights.size(),vector<bool>(heights[0].size(),false));
        vector<vector<bool>> atlantic(heights.size(),vector<bool>(heights[0].size(),false));
        
        for(int i = 0 ; i<heights.size();i++){
            if(!pacific[i][0]){
                queue<pair<int,int>> value;
                value.push({i,0});
                pacific[i][0] = true;
                while(!value.empty()){
                    auto currPos = value.front();
                    value.pop();
                    for(auto x:direction){
                        int x1 = currPos.first+x[0];
                        int y1 = currPos.second+x[1];
                        if(x1>=0 and x1<heights.size() and y1>=0 and y1<heights[0].size() and !pacific[x1][y1] and heights[x1][y1]>=heights[currPos.first][currPos.second]){
                            pacific[x1][y1]= true;
                            value.push({x1,y1});
                        }
                    }
                }
            }
        }
        
        for(int i = 0;i<heights[0].size() ; i++){
            if(!pacific[0][i]){
                queue<pair<int,int>> value;
                value.push({0,i});
                pacific[0][i] = true;
                while(!value.empty()){
                    auto currPos = value.front();
                    value.pop();
                    for(auto x:direction){
                        int x1 = currPos.first+x[0];
                        int y1 = currPos.second+x[1];
                        if(x1>=0 and x1<heights.size() and y1>=0 and y1<heights[0].size() and !pacific[x1][y1] and heights[x1][y1]>=heights[currPos.first][currPos.second]){
                            pacific[x1][y1]= true;
                            value.push({x1,y1});
                        }
                    }
                }
            }
        }
        
        for(int i = 0;i<heights.size();i++){
            if(!atlantic[i][heights[0].size()-1]){
                 queue<pair<int,int>> value;
                value.push({i,heights[0].size()-1});
                atlantic[i][heights[0].size()-1] = true;
                while(!value.empty()){
                    auto currPos = value.front();
                    value.pop();
                    for(auto x:direction){
                        int x1 = currPos.first+x[0];
                        int y1 = currPos.second+x[1];
                        if(x1>=0 and x1<heights.size() and y1>=0 and y1<heights[0].size() and !atlantic[x1][y1] and heights[x1][y1]>=heights[currPos.first][currPos.second]){
                            atlantic[x1][y1]= true;
                            value.push({x1,y1});
                        }
                    }
                }
            }
        }
        
        for(int i = 0;i<heights[0].size();i++){
            if(!atlantic[heights.size()-1][i]){
                queue<pair<int,int>> value;
                value.push({heights.size()-1,i});
                atlantic[heights.size()-1][i] = true;
                while(!value.empty()){
                    auto currPos = value.front();
                    value.pop();
                    for(auto x:direction){
                        int x1 = currPos.first+x[0];
                        int y1 = currPos.second+x[1];
                        if(x1>=0 and x1<heights.size() and y1>=0 and y1<heights[0].size() and !atlantic[x1][y1] and heights[x1][y1]>=heights[currPos.first][currPos.second]){
                            atlantic[x1][y1]= true;
                            value.push({x1,y1});
                        }
                    }
                }
            }
        }
        // for(int i =0;i<heights.size();i++){
        //     for(int j = 0;j<heights[i].size();j++){
        //         cout<<atlantic[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        // cout<<"\n";
        // for(int i =0;i<heights.size();i++){
        //     for(int j = 0;j<heights[i].size();j++){
        //         cout<<pacific[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        
        vector<vector<int>> ans;
        for(int i = 0;i<heights.size();i++){
            for(int j = 0;j<heights[i].size();j++){
                if(atlantic[i][j] and pacific[i][j]){
                    vector<int> val;
                    val.push_back(i);
                    val.push_back(j);
                    ans.push_back(val);
                }
            }
        }
        return ans;
    }
};
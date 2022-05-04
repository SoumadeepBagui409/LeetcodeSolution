class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> row,clm;
        for(int i = 0;i<matrix.size();i++){
            for(int j = 0;j<matrix[i].size();j++){
                if(matrix[i][j] == 0){
                    row.insert(i);
                    clm.insert(j);
                }
            }
        }
        for(auto x : row){
            for(int j = 0;j<matrix[x].size();j++){
             matrix[x][j] = 0;   
            }
        }
        for(auto y:clm){
            for(int i = 0;i<matrix.size();i++){
                matrix[i][y] = 0;
            }
        }
    }
};
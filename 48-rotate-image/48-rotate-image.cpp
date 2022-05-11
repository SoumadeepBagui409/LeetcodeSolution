class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i = 0; i<matrix.size();i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
        int row = 0;
        int clm = matrix[0].size()-1;
        while(row<matrix.size() and clm>=0){
            int row1 = row;
            int clm1 = clm;
            while(row1<matrix.size() and clm1>=0){
                swap(matrix[row][clm1] , matrix[row1][clm]);
                row1++;
                clm1--;
            }
            row++;
            clm--;
        }
    }
};
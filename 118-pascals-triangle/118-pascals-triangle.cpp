class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> value;   
        for(int i =1;i<=numRows;i++){
            vector<int> valer;
            if(i==1){
                valer.push_back(1);
                value.push_back(valer);
            }else if(i==2){
                valer.push_back(1);
                valer.push_back(1);
                value.push_back(valer);
            }else{
                valer.push_back(1);
                for(int y = 1;y<i-1;y++){
                    valer.push_back(value[i-2][y-1]+value[i-2][y]);
                }
                valer.push_back(1);
                value.push_back(valer);
            }
        }
        return value;
    }
};
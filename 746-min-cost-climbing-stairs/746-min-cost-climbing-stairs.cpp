class Solution {
public:
    int min(int a,int b){
        return (a>=b)?b:a;
    }
    int ans(vector<int>&cost,int idx,vector<int> &val){
        if(idx>=cost.size()){
            return 0;
        }
        if(val[idx]!=-1){
            return val[idx];
        }
        int op1,op2;
        op1 = cost[idx] + ans(cost,idx+1,val);
        op2 = cost[idx] + ans(cost,idx+2,val);
        return val[idx] = min(op1 , op2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> val1(cost.size()+1,-1);
        int val = ans(cost,0,val1);
         vector<int> val2(cost.size()+1,-1);
        int val3 = ans(cost,1,val2);
        return min(val,val3);
    }
};
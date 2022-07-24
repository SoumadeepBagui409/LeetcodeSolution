class Solution {
public:
    int findValue(vector<int> &coins,int amount,vector<int> &cache){
        if(amount == 0)return 0;
        if(amount<0)return 100000;
        if(cache[amount]!=-1)return cache[amount];
        int op1 = 100000;
        for(int i = 0; i<coins.size(); i++){
            op1 = min(op1,findValue(coins,amount-coins[i],cache));
        }
        return cache[amount] = 1+op1;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> cache(amount+1,-1);
        int val = findValue(coins,amount,cache);
        if(val>=100000)return -1;
        return val;
    }
};
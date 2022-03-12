class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left==0 || right == 0)return 0;
        if(left==right)return left;
        int val = 1;
        for(int i = int(log2(left))+1;i<=int(log2(right))+1;i++){
            if((1<<i)>=left and (1<<i)<=right){
                return 0;
            }
        }
        val = left;
        for(int i = left + 1;i<right;i++)val&=i;
        return val&right;
    }
};
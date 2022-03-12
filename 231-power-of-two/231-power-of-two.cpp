class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<0)return false;
        if(n==0){
            return false;
        }
        return log2(n) == 1.0*int(log2(n));
    }
};
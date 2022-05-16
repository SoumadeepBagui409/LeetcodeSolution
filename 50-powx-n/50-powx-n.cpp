class Solution {
public:
    double myPow(double x, int n){
        double ans = 1.0;
        long long int n1 = n;
        if(n1==0 || x==1.0)return ans;
        bool sign = (n>0)?true:false;
        if(sign==false)n1=-1*n1;
        while(n1>0){
            if(n1&1)ans*=x;
            x*=x;
            n1=n1>>1;
        }
        return (sign==true)?ans:1/ans;
    }
};
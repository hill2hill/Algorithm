class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0) return 0.0;
        if(n == 0)  return 1.0;
        bool posi = true;
        long long N = n;
        if(n < 0){
            N = -N;
            posi = false;
        }
        double res = 1.0;
        while(N){
            if(N & 1)   res *= x;
            x *= x;
            N >>= 1;
        }
        if(!posi)   res = 1/res;
        return res;
        
    }
};
class Solution {
public:
    double myPow(double x, int n) {
        double res=1;
        if (n < 0) {
        x = 1.0 / x;
        n = -n;
        }
        while(n>0){
           if(n&1){
              res=res*x;
           }
           x*=x;
           n/=2;
        }

        return res;
    }
};

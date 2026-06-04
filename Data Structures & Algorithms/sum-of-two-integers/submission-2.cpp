class Solution {
public:
    int getSum(int a, int b) {
        //vector<int>num1(32,0),num2(32,0);
        int z1=0,z2=0;
        int c=0;
        int res=0;
        for(int i=0;i<32;i++){
            if((1<<i) & a){
                z1=1;
            }
            if((1<<i) & b){
                z2=1;
            }
            if(c+z1+z2==1 || c+z1+z2==3){
                res+=(1<<i);
            }
            if(c+z1+z2>=2){
                c=1;
            }else c=0;
            z1=0;
            z2=0;
        }
        return res;
    }
};

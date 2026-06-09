class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& t) {
        
        int n=triplets.size();
        int a=0,b=0,c=0;
        int t1=t[0],t2=t[1],t3=t[2];
        
        for(int i=0;i<n;i++){
        
            if(triplets[i][0]==t1){
                if(max(triplets[i][1],b)<=t2 && max(triplets[i][2],c)<=t3){
                    a=t1;
                    b=max(triplets[i][1],b);
                    c=max(triplets[i][2],c);
                }
            }else if(triplets[i][1]==t2){
                if(max(triplets[i][0],a)<=t1 && max(triplets[i][2],c)<=t3){
                    b=t2;
                    a=max(a,triplets[i][0]);
                    c=max(c,triplets[i][2]);
                }
            }else if(triplets[i][2]==t3){
                if(max(triplets[i][0],a)<=t1 && max(triplets[i][1],b)<=t2){
                    c=t3;
                    b=max(triplets[i][1],b);
                    a=max(triplets[i][0],a);
                }
            }
        }

        return (a==t1 && b==t2 && c==t3);
    }
};

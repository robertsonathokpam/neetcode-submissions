class Solution {
public:
    vector<vector<int>>dp;
    int n;
    bool fn(int ind,string &s,int cnt){
         if(cnt<0) return 0;
         
         if(ind==n){
            if(cnt==0) return 1;
            else return 0;
         }

         if(dp[ind][cnt]!=-1) return dp[ind][cnt]; 
         if(s[ind]=='('){
            dp[ind][cnt]=fn(ind+1,s,cnt+1);
         }else if(s[ind]==')'){
            dp[ind][cnt]=fn(ind+1,s,cnt-1);
         }else {
            dp[ind][cnt]=fn(ind+1,s,cnt)|fn(ind+1,s,cnt+1)|fn(ind+1,s,cnt-1);
         }

         return dp[ind][cnt];
    }
    bool checkValidString(string s) {
        n=s.size();
        dp.assign(n+1,vector<int>(n+1,-1));
        return fn(0,s,0);
    }
};

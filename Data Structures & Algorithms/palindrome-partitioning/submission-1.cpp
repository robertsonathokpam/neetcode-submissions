class Solution {
public:
    string s;
    int n;
    bool ispal(int a,int b){
        string x=s.substr(a,b-a+1);
        string y=x;
        reverse(y.begin(),y.end());
        return y==x;
    }
    vector<vector<string>>ans;

    void fn(int ind,vector<string>res){

         if(ind==n){
            ans.push_back(res); 
            return;           
         }
         for(int i=ind;i<n;i++){
             if(ispal(ind,i)){
                  string x=s.substr(ind,i - ind + 1);
                  res.push_back(x);
                  fn(i+1,res);
                  res.pop_back();
             }
         }
    }
    vector<vector<string>> partition(string x) {
        s=x;
        n=s.size();
        vector<string>res;
        fn(0,res);
        return ans;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     map<int,int>mp;        
        int n=s.size();
        if(n==0) return 0;
        int len=0;
        int l=0;
        for(int r=0;r<n;r++){
            mp[s[r]]++;
            while(mp[s[r]]>1){
                mp[s[l]]--;
                l++;
            }
            len=max(len,r-l+1);
        }
        return len;
    }
};

class Solution {
public:
    bool alphaNum(char c) {
        return (c >= 'A' && c <= 'Z' ||
                c >= 'a' && c <= 'z' ||
                c >= '0' && c <= '9');
    }
    bool same(char a, char b){
        return (a==b) || (toupper(a)==toupper(b));
    } 
    bool isPalindrome(string s) {
        int n=s.size();
        int l=0,r=n-1;
        while(l<=r){
            while (l < r && !alphaNum(s[l])) {
                l++;
            }
            while (r > l && !alphaNum(s[r])) {
                r--;
            }
            if(!same(s[l],s[r])){
               return false;
            }
            l++;
            r--;
        }
        return true;
    }
};

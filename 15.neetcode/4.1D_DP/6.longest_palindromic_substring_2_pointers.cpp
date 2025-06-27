class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        string ans="";
        for(int i=0;i<n;j++) {
            // odd length center
            int l=i, r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                ans = (j-i+1 > ans.length()) ? s.substr(i,j-i+1): ans;
                l--;
                r++;
            }
            // even length centers
            l=i, r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                ans = (j-i+1 > ans.length()) ? s.substr(i,j-i+1): ans;
                l--;
                r++;
            }
        }
        return ans;
    }
};
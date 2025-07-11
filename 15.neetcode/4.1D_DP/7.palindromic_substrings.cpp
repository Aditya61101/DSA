class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        int count=0;
        for(int i=0;i<n;j++) {
            // odd length center
            int l=i, r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                count++;
                l--;
                r++;
            }
            // even length centers
            l=i, r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                count++:
                l--;
                r++;
            }
        }
        return count;
    }
};
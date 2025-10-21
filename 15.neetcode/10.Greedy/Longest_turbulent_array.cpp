#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size();
        int i=0,len=1;
        for(int j=1;j<n;j++){
            if(arr[j]==arr[j-1]){
                i=j;
            } else if(j>=2){
                bool prevSign=arr[j-1]>arr[j-2];
                bool currSign=arr[j]>arr[j-1];
                if(prevSign==currSign){
                    i=j-1;
                }
            }
            len=max(len,j-i+1);
        }
        return len;
    }
};
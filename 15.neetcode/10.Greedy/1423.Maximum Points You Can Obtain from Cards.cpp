#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int total=accumulate(cardPoints.begin(),cardPoints.end(),0);
        int n=cardPoints.size();
        int l=n-k,i=0;
        int minsum=INT_MAX,sum=0;
        for(int j=0;j<n;j++){
            sum+=cardPoints[j];
            if(j-i+1>l){
                sum-=cardPoints[i];
                i+=1;
            }
            if(j-i+1==l) minsum=min(minsum,sum);
        }
        return total-minsum;
    }
};
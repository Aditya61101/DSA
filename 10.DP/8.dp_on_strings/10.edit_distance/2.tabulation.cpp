//find minimum steps to convert s1 to s2 using insertion,deletion,replacement by any other character.
#include<iostream>
#include<vector>
using namespace std;

int main(){
    string s1="horse",s2="ros";
    int n1=s1.length(),n2=s2.length();
    vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
    for (int i=0; i<n1+1; i++){
        dp[i][0]=i;
    }
    for (int j=0; j<n2+1; j++){
        dp[0][j]=j;
    }
    for (int i=1; i<n1+1; i++){
        for (int j=1; j<n2+1; j++){
            if (s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                int insertOp=1+dp[i][j-1];
                int deleteOp=1+dp[i-1][j];
                int replaceOp=1+dp[i-1][j-1];
                dp[i][j]=min(insertOp,min(deleteOp,replaceOp));
            }
        }
    }
    cout<<dp[n1][n2];
}
//for base cases
//if the desired string(s2) gets exhausted before s1 getting exhausted this means that we need to remove every char of s1 before the current index 'i' i.e we require (i+1) delete operations.
//if s1 gets exhausted it means we have to add (j+1) characters of s2 into s1, so we require j+1 insert operations.
//while doing insert operation, we are inserting at the back so after insertion we search for next char of s2 in s1, thats why we did (i,j-1).
//while doing deletion operation, we are deleting the current char of s1 which means we are moving to next char of s1, being at the same char of s2, thats why we did (i-1,j).
//while doing replace operation, we are replacing current s1 char with the one at current s2 so that both of them matches, so after that we move to next char of both s1 and s2.
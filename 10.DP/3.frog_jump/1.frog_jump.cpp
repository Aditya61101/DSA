/*There is a frog on the '1st' step of an 'N' stairs long staircase. The frog wants to reach the 'Nth' stair. 'HEIGHT [i]' is the height of the '(i+1)th' stair.If Frog jumps from 'ith' to 'jth' stair, the energy lost in the jump is given by absolute value of (HEIGHT[i-1]-HEIGHT[j-1]). If the Frog is on 'ith' staircase, he can jump either to '(i+1)th' stair or to '(i+2)th' stair. Your task is to find the minimum total energy used by the frog to reach from '1st' stair to 'Nth' stair.*/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int solve(int i,vector<int>&arr){
    if (i==0)
        return 0;
    int climb1=solve(i-1,arr)+abs(arr[i-1]-arr[i]);
    int climb2=INT_MAX;
    if (i>1)
        climb2=solve(i-2,arr)+abs(arr[i-2]-arr[i]);
    return min(climb1,climb2);
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<solve(n-1,arr);
}
//sum up the additional tasks.
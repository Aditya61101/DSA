#include<iostream>
#include<cstring>
using namespace std;
#define lli long long int

static int dp1[1000];
static int dp2[1000];
int solve1(int arr[],int index){
    if (index==0){
        return arr[index];
    }
    if (index<0){
        return 0;
    }
    if(dp1[index]!=-1){
        return dp1[index];
    }
    int pick=arr[index]+solve1(arr,index-2);
    int notPick=solve1(arr,index-1);
    return dp1[index]=max(pick,notPick);
}
int solve2(int arr[],int index){
    if (index==1){
        return arr[index];
    }
    if (index<=0){
        return 0;
    }
    if(dp2[index]!=-1){
        return dp2[index];
    }
    int pick=arr[index]+solve2(arr,index-2);
    int notPick=solve2(arr,index-1);
    return dp2[index]=max(pick,notPick);
}
int solve(int arr[],int index){
    int result1=solve1(arr,index-1);
    int result2=solve2(arr,index);
    return max(result1,result2);
}
int main(){
    int arr[]={2,1,4,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    memset(dp1,-1,sizeof(dp1));
    memset(dp2,-1,sizeof(dp2));
    int result=solve(arr,n-1);
    cout<<result;
}
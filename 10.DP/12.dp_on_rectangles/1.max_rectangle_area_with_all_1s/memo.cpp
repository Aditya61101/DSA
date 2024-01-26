#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

int largestRectangleArea(vector<int>&heights){
    int n=heights.size();
    stack<int>st;
    vector<int>leftSmall,rightSmall;
    for(int i=0; i<n; i++){
      while(!st.empty()&&heights[st.top()]>= heights[i]){
          st.pop();
        }
        if (st.empty()){
          leftSmall[i]=0;
        }
        else{
          leftSmall[i]=st.top()+1;
        }
        st.push(i);
    }
    // clear the stack to be re-used
    while (!st.empty()){
        st.pop();
    }
    for(int i=n-1;i>=0; i--){
       while (!st.empty()&&heights[st.top()]>= heights[i]){
        st.pop();
       }
        if (st.empty()){
          rightSmall[i]=n-1;
        }
        else{
          rightSmall[i]=st.top()-1;
        }
        st.push(i);
    }
    int maxA=0;
    for (int i=0; i<n; i++){
       maxA=max(maxA,heights[i]*(rightSmall[i] -leftSmall[i]+1));
    }
    return maxA;
}
int main(){
    int r=4,c=5;
    vector<vector<int>>rect={{1,0,1,0,0},{1,0,1,1,1},{1,1,1,1,1},{1,0,0,1,0}};
    vector<int>height(c,0);
    int maxArea=0;
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            if (rect[i][j]==1){
                height[j]++;
            }
            else{
                height[j]=0;
            }
        }
        int area=largestRectangleArea(height);
        maxArea=max(maxArea,area);
    }
    cout<<maxArea;
}
#include<bits/stdc++.h>
using namespace std;

vector<int>first_negative(vector<int>&v,int k){
    int n=v.size();
    int i=0,j=0;
    vector<int>result;
    queue<int>neg;
    while(j<n){
        if (v[j]<0){
            neg.push(v[j]);
        }
        if(j-i+1==k){
          if (!neg.empty()){
            result.push_back(neg.front());
          }
          else{
            result.push_back(0);
          }
          if(!neg.empty()&&neg.front()==v[i]){
            neg.pop();
          }
          i++;
        }
        j++;
    }
    return result;
}
int main(){
   int n=7,k=3;
   vector<int>v={2,-5,1,8,2,-9,-1};
   auto result = first_negative(v,k);
   for (auto &it:result){
       cout<<it<<" ";
   } 
}
//Given N strings, print unique strings in lexicographical order with their frequency
//N<=10^5
//S.length()<=100  

#include<iostream>
#include<map>
using namespace std;

int main(){
 string arr[7]={"abc","cdf","abc","gf","cdf","ij","abc"};
 int n = sizeof(arr)/sizeof(arr[0]);
 map<string,int>m;
 for (size_t i = 0; i < n; i++){
     if(m.find(arr[i])!=m.end()){
         m[arr[i]]++;
     }
     else{
         m[arr[i]]=1;
     }
 }
 for (auto it:m){
     cout<<it.first<<" "<<it.second<<endl;
 }
}
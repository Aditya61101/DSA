#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//this is the comparator function
bool comparator(pair<int,int>x,pair<int,int>y){
    if (x.first!=y.first){
        return x.first<y.first;   
    }
        return x.second>y.second;
}
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>>a(n);
    for (size_t i = 0; i < n; i++){
        cin>>a[i].first>>a[i].second;
    }
    
    // for (size_t i = 0; i < n; i++){
    //     for (size_t j = i+1; j< n; j++){
    //         if (should_i_swap(a[i],a[j])){
    //             swap(a[i],a[j]);            
    //         }   
    //     }
    // }
    sort(a.begin(),a.end(),comparator);
    for (size_t i = 0; i < n; i++){
        cout<<a[i].first<<" "<<a[i].second<<endl;
    }
}
//the inbuilt swap function expects true if we dont want to swap and expects false when we want to swap.
//greater<pair<int,int>>(), is an inbuilt comparator function which sorts in decreasing order.
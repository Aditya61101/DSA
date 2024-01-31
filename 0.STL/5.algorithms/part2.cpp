#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main(){
    auto sum = [](int x, int y){ 
        return x + y; 
    }; // lambda function
    cout << sum(2,3)<<endl;
    vector<int>v={2,3,5};
    vector<int>v1={2,3,0,-1};
    cout<<all_of(v.begin(),v.end(),[](int x){
        return x>0;
    })<<endl;//checks if all the input in vector v is positive or not if it is then it returns 1 else 0.
    cout<<any_of(v1.begin(),v1.end(),[](int x){
        return x<0;
    })<<endl;//checks if any of the input in vector v1 is negative or not if it is then it returns 1 else 0.
    cout<<none_of(v1.begin(),v1.end(),[](int x){
        return x>0;
    })<<endl;//checks if all the input in vector v is positive or not if it is then it returns 0 else 1.It is complementary of all_of.
}
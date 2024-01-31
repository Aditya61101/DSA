//maximum no. of candies to be consumed
#include<iostream>
#include<set>
#include<math.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--){
        multiset<long long>candies;
        long long n,k,sum=0;
        cin>>n>>k;
        for (size_t i = 0; i < n; i++){
        long long x;
        cin>>x;
        candies.insert(x);
    }
        while(k--){
            auto it = --candies.end();
            sum+=*(it);
            int value = floor(*(it)/2);
            candies.insert(value);
            candies.erase(it);
        }
        cout<<sum;
    }
}
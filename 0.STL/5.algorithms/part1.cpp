#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main(){
    int n;
    cin>>n;
    string name="Aditya";
    vector<int>v(n);
    for (size_t i = 0; i < n; i++){
        cin>>v[i];
    }
    int min = *min_element(v.begin(),v.end());
    int max = *max_element(v.begin(),v.end());
    int sum = accumulate(v.begin(),v.end(),0);
    int countNum = count(v.begin(),v.end(),6);
    int findNum = *find(v.begin(),v.end(),3);
    reverse(name.begin(),name.end());

    cout<<max<<" "<<min<<" "<<sum<<" "<<countNum<<" "<<findNum<<" "<<name<<endl;
}
//min_element,max_element,find returns an iterator
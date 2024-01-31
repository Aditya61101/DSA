#include<iostream>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

int main(){
    int arr[]={4,5,5,7,8,25};
    set<int>s;
    map<int,int>m;
    for (size_t i = 0; i < s.size(); i++){
        int x;
        cin>>x;
        s.insert(x);
    } 
    int n=sizeof(arr)/sizeof(arr[0]);
    int *ptr1 = lower_bound(arr,arr+n,5);
    int *ptr2 = upper_bound(arr,arr+n,5);
    if (ptr1==(arr+n)||ptr2==(arr+n)){
        cout<<"not found";
    }
    else
    cout<<*ptr1<<" "<<*ptr2;
    
}
//lower_bound returns the value we are searching if that value is present in that array,vector etc.If not then it returns the value just greater than it present in that array,vector.
//upper_bound returns the value just greater than that we are searching even if that value is present in the array,vector or not. 
//to use this function, we should sort the array/vector etc in order to decrease the T.C of searching.
//for sets s, s.lower_bound(5) to find the lower bound of 5.
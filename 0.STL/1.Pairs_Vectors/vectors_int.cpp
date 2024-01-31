#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int> &v){ //by reference
    int n = v.size();//current size of vector
    for (size_t i = 0; i < n; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int>v;
    //taking input in a vector
    int n;
    cin>>n;
    for (size_t i = 0; i < n; i++){
        /* code */
        int x;
        cin>>x;
        v.push_back(x);//in the end of vector
    }
    v.push_back(6);//dynamic nature of vector
    v.pop_back();//to remove the last element of vector
    printVector(v);
    vector<int>v1(5,1);//11111 i.e v1 of size 5 and filled with 1
    //copying vector
    vector<int>v2=v;//by value,O(n)
    printVector(v2);

}
//memory allocation limit for local vector/array:10^5
//memory allocation limit for global vector/array:10^7  else TLE
//passing by reference changes the actual vector when the referenced vector is changed.
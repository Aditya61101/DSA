#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;

int main(){
    //to initialize a pair 
    pair<int,string> p;
    pair<string,int>p1;
    //to make a pair
    p=make_pair(2,"abc");
    //printing the elements of pair
    cout<<p.first<<" "<<p.second<<endl;
    //another way to make a pair
    p1={"aditya",85};
    cout<<p1.first<<" "<<p1.second<<endl;
    pair<int,string> &p2=p;//by reference
    pair<string,int>p3=p1;//by value
    p2.first=85;
    cout<<p2.first<<" "<<p2.second<<endl;

    //pair of arrays
    pair<int,int>p_array[3];
    p_array[0]={1,2};
    p_array[1]={2,3};
    p_array[2]={3,4};
    for (size_t i = 0; i < 3; i++){
        cout<<p_array[i].first<<" "<<p_array[i].second<<endl;
    }
    swap(p_array[0],p_array[2]);//swapping the pair of arrays
      for (size_t i = 0; i < 3; i++){
        cout<<p_array[i].first<<" "<<p_array[i].second<<endl;
    }
    pair<int,int>p_input;
    cout<<"enter value of pairs";
    cin>>p_input.first>>p_input.second;
    cout<<p_input.first<<" "<<p_input.second;

}
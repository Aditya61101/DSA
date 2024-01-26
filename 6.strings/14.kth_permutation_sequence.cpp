#include<iostream>
#include<string>
#include<vector>
using namespace std;

string solve(int n,int k){
    vector<int>ip;
    int fact=1;
    for (int i=1; i<n; i++){
        fact=fact*i;
        ip.push_back(i);
    }
    ip.push_back(n);
    string ans="";
    k=k-1;
    while (true){
        ans=ans+to_string(ip[k/fact]);//each grp will contain fact no. of factorials,so kth fact will lie in k/fact grp and we convert that int to char using to_string method.
        ip.erase(ip.begin()+k/fact);//after using that number we remove that number from original array.
        if (ip.size()==0){ //if during removal, the size of array becomes 0 then we break.
            break;
        }
        k=k%fact;
        fact=fact/ip.size();//decreasing the factorial value by its highest value
    }
    return ans;
}
int main(){
    int n=4,k=9;
    string result=solve(n,k);
    cout<<result;
}
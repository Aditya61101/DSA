#include<iostream>
#include<vector>
using namespace std;

vector<vector<string>>res;
bool isPalindrome(string ip,int start,int end){
    while (start<=end){
        if (ip[start]!=ip[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}
void solve(string &ip,vector<string> &op,int index){
    if (index==ip.length()){
        res.push_back(op);
        return;
    }
    for (int i = index; i <ip.length(); i++){
        if(isPalindrome(ip,index,i)){
            op.push_back(ip.substr(index,i-index+1));
            solve(ip,op,i+1);
            op.pop_back();
        }
    }
}
int main(){
    string ip="aab";
    vector<string>op;
    solve(ip,op,0);
    for (auto v:res){
        for (auto e:v){
            cout<<e<<" ";
        }
        cout<<'\n';
    }
}
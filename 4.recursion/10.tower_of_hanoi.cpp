#include<iostream>
using namespace std;

void solve(int n,char S,char D,char H){
    if (n==0){
        return;
    }
    solve(n-1,S,H,D);
    cout<<"moved "<<n<<" from "<<S<<" to "<<D<<endl;
    solve(n-1,H,D,S);
}
int main(){
    int n=5;
    char S='S',H='H',D='D';
    solve(n,S,H,D);

}
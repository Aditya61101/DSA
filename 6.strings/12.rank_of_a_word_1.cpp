#include<iostream>
#include<string>
using namespace std;

int fact(int n){
    if (n==1){
        return 1;
    }
    return n*fact(n-1);
}
void solve(string &str){
    int res=1;
    int n=str.length();
    int mul=fact(n);
    int count[256]={0};
    //incrementing the occurrence of each char present in the string str
    for (int i=0; i<n; i++){
        count[str[i]]++;
    }
    //computing amount of chars lower than the present char present in the string str
    for (int i = 1; i < 256; i++){
        count[i]+=count[i-1];
    }
    //actual calculation
    for (int i = 0; i <n-1; i++){
        mul=mul/(n-i);
        res+=count[str[i]-1]*mul;
        for (int j=str[i]; j<256; j++){
            count[j]--;
        }
    }
    cout<<res;
}
int main(){
    string str="string";
    solve(str);
}
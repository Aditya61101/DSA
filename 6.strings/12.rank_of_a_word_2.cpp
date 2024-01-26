#include<bits/stdc++.h>
using namespace std;

void solve(string &str){
    string firstWord=str;
    sort(firstWord.begin(),firstWord.end());
    int rank=1;
    do{
        if(firstWord!=str){
            rank++;
        }
        else{
            break;
        }
    } while (next_permutation(firstWord.begin(),firstWord.end()));
    cout<<rank;
    
}
int main(){
    string str="string";
    solve(str);
}
//T.C: O(n*log(n))
#include<bits/stdc++.h>
using namespace std;

int main(){
    string str="geeksforgeeks";
    int count[26]={0};
    for (int i = 0; i < str.length(); i++){
        //to increase the frequency of a character
        count[str[i]-'a']++;
    }
    for (int i = 0; i<26; i++){
        if(count[i]>0){
            //prints the character in sorted order
            cout<<char(i+'a')<<" ";
            cout<<count[i]<<endl;
        }
    }
}
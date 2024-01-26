#include<bits/stdc++.h>
using namespace std;

int countAnagram(string s1,string s2){
    // int mainSum = 0;
    // int k = s2.length();
    // for(int i=0; i<k; i++){
    //     mainSum+=s2[i]+'0'-'0';
    // }
    // int sum=0,i=0,j=0,count=0;
    // while(j<s1.length()){
    //     sum+=s1[j]+'0'-'0';
    //     if(j-i+1==k){
    //         if(sum==mainSum){
    //             count++;
    //         }
    //         sum-=s1[i]+'0'-'0';
    //         i++;
    //     }   
    //     j++;
    // }
    // return count;
}
int main(){  
    string s1="forxxorfxaofr";
    string s2="for";
    string s3="aabaabaa";
    string s4="aaxa";
    int result1 = countAnagram(s1,s2);
    int result2 = countAnagram(s3,s4);
    cout<<result1<<" "<<result2;
}
//anagram: a word or phrase made by transposing the letters of another word or phrase.
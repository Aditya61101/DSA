#include<iostream>
using namespace std;

void reverseWord(string &str,int start,int end){
    while (start<=end){
        swap(str[start],str[end]);
        start++;
        end--;
    }
}
void solve(string &str){
    int start=0;
    for (int end = 0; end < str.length(); end++){
        if(str[end]==' '){
            //to swap the letters before a space
            reverseWord(str,start,end-1);
            start=end+1;
        }   
    } 
    //to swap the last word of the sentence
    reverseWord(str,start,str.length()-1);
    //to swap the entire sentence
    reverseWord(str,0,str.length()-1);
}
int main(){
    string str="welcome to gfg";
    solve(str);
    cout<<str;
}
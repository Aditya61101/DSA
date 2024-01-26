#include<iostream>
using namespace std;

void RBsearch(string txt,string pat){
    int h=1,d=3,q=57;
    for (size_t i = 1; i < pat.length(); i++){
        h=(h*d)%q;
    }
    int p=0,t=0;
    for (size_t i = 0; i < pat.length(); i++){
        p=(p*d+pat[i])%q;
        t=(t*d+txt[i])%q;
    }
    for (int i = 0; i<=txt.length()-pat.length(); i++){   
        if (p==t){
            bool flag=true;
            for (size_t j = 0; j < pat.length(); j++){
                if (txt[i+j]!=pat[j]){
                    flag=false;
                    break;
                }
            }
            if (flag==true){
                cout<<i<<" ";
            }
            //computing hash function till last window
            if (i<txt.length()-pat.length()){
                t=(d*(t-txt[i]*h)+txt[i+pat.length()])%q;
            }
            if (t<0){
                t+=q;
            }
        }
    } 
}
int main(){
    string txt="geeksforgeeks";
    string pat="geek";
    RBsearch(txt,pat);
}
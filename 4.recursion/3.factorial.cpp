#include<iostream>
using namespace std;

int printFactorial(int n){
    if (n==1){
        return 1;
    }
    // return n*printFactorial(n-1);
    int fact= n*printFactorial(n-1);
    return fact;
}
int main(){
    int n=7;
    int result = printFactorial(n);
    cout<<result;
}
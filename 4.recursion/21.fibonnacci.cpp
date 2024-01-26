#include<iostream>
#include<cstring>
using namespace std;

int printFibonacci(int n){
    if (n==0||n==1){
        return n;
    }
    int result=printFibonacci(n-1)+printFibonacci(n-2);
    return result;
}
int main(){
    int n=6;
    int result=printFibonacci(n);
    cout<<result;
}
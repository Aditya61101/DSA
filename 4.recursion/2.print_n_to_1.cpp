#include<iostream>
using namespace std;

void printNumber(int n){
    if (n==0){
        return;
    }
    cout<<n<<" ";
    printNumber(n-1);
}
int main(){
    int n=15;
    printNumber(n);
}
/* given 2D array arr of N*N integers, given Q queries and in each query given a,b,c and d print sum of square represented by (a,b) as top left point and (c,d) as bottom right point */

#include<iostream>
using namespace std;
const int N =1e3+10;
int arr[N][N];
long long pf[N][N];
int main(){
    int n;
    cin>>n;
    for (size_t i = 1; i <=n; i++){
        for (size_t j = 1; j <=n; j++){
            cin>>arr[i][j];
            pf[i][j]=arr[i][j]+pf[i-1][j]+pf[i][j-1]-pf[i-1][j-1];
        }
    }
    int q;
    cin>>q;
    while (q--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        cout<<pf[c][d]-pf[a-1][d]-pf[c][b-1]+pf[a-1][b-1];
    }
}
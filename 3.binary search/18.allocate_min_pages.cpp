#include<bits/stdc++.h>
using namespace std;

bool isValid(int *arr,int n,int maxPages,int k){
    int stud=1,sumPages=0;
    for (int i=0; i<n; i++){
        sumPages+=arr[i];
        if (sumPages>maxPages){
            stud++;
            sumPages=arr[i];
            if(stud>k){
               return false;
            }
        }
    }
    return true; 
}
int allocateMinPages(int arr[],int n,int studs){
    
    //if no.of students is greater than no. of books
    if (n<studs){
        return -1;
    }
    int high,low,mid,res;
    int *maxElementIndex = max_element(arr,arr+n);
    low = *maxElementIndex;
    high = accumulate(arr,arr+n,0);
    res=-1;
    while (low<=high){
        mid=low+(high-low)/2;
        if (isValid(arr,n,mid,studs)){
            res=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return res;
}
int main(){
    int arr[]={10,20,30,40};//array may not be sorted
    int students=2;
    int n=sizeof(arr)/sizeof(arr[0]);
    int result=allocateMinPages(arr,n,students);
    cout<<result;
}
//1.atleast one whole book to one student
//2.one student can take books in continuous manner.
//3.all the books should be distributed.
//4.minimize the maximum no. of pages a student can read.
//working of isValid function:-
//calculating sum of pages for each students, if the sum of pages exceeds the maxVal we increase the no. student by 1 i.e we start giving books to the other student but if the no. of students goes beyond no. of actual students(k) then this is not a valid distribution, so we return false.
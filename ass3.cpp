#include<bits/stdc++.h>
#include<omp.h>
using namespace std;
typedef long long ll;
int getMin(int arr[],int n){
    int mn=INT_MAX;
    #pragma omp parallel for reduction(min:mn)
    for(int i=0;i<n;i++){
        if(arr[i]<mn)mn=arr[i];
    }
    return mn;
}
int getMax(int arr[],int n){
    int mx=INT_MIN;
    #pragma omp parallel for reduction(max:mx)
    for(int i=0;i<n;i++){
        if(arr[i]>mx)mx=arr[i];
    }
    return mx;
}
int getSum(int arr[],int n){
    int sum=0;
    #pragma omp parallel for reduction(+:sum)
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}
int getAverage(int arr[],int n){
    int sum=getSum(arr,n);
    return (double)sum/(double)n-1;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<getMin(arr,n)<<endl;
    cout<<getMax(arr,n)<<endl;
    cout<<getSum(arr,n)<<endl;
    cout<<getAverage(arr,n)<<endl;
    return 0;
}

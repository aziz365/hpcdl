#include<iostream>
#include<omp.h>
using namespace std;

void merge(int arr[],int l,int mid,int r){
    int temp[r-l+1];
    int i=l,j=mid+1,k=0;
    while(i<=mid && j<=r){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=r){
        temp[k++]=arr[j++];
    }
    for(int i=l,k=0;i<=r;i++,k++){
        arr[i]=temp[k];
    }
}
void mergeSort(int arr[],int l,int r){
    if(l>=r)return;
    int mid=(l+r)/2;
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            mergeSort(arr,l,mid);

        }
        #pragma omp section
        {
            mergeSort(arr,mid+1,r);

        }
    }
    merge(arr,l,mid,r);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=rand()%n;
    }
    int start=omp_get_wtime();
    #pragma omp parallel
    {
        mergeSort(arr,0,n-1);
    }
    int stop=omp_get_wtime();
    for(int &it:arr){
        cout<<it<<" ";
    }
    cout<<stop-start<<endl;
    return 0;
}
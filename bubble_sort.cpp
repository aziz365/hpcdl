#include<iostream>
#include<omp.h>
using namespace std;

void bubbleSort(int arr[],int n){
    for(int i=0;i<n;i++){
        int first=i%2;
        #pragma omp parallel for shared(arr,first)
        for(int j=first;j<n-1;j+=2){
            if(arr[j]>arr[j+1])swap(arr[j],arr[j+1]);
        }
    }

}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=rand()%n;
    }
    bubbleSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;

}
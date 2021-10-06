#include<bits/stdc++.h>
using namespace std;
//Contributed by : Isha Bansal
void merge(int arr[],int s,int mid,int e){
    int left=s;;
    int right=mid;
    int k=0;
    int temp[s+e+1];
    while(left<mid && right<=e){
        if(arr[left]<=arr[right]){
            temp[k++]=arr[left++];
        }
        else{
            temp[k++]=arr[right++];
        }
    }
    while(left<mid){
        temp[k++]=arr[left++];
    }
    while(right<=e){
        temp[k++]=arr[right++];
    }
    k=0;
    for(int i=s;i<=e;i++){
        arr[i]=temp[k++];
    }

}

void mergeSort(int arr[],int s,int e){
    if(s>=e)return;

    int mid=s+(e-s)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,mid+1,e);

}

int main(){
    int arr[]={3,6,2,8,3,1,5};
    mergeSort(arr,0,6);
    for(int i=0;i<=6;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

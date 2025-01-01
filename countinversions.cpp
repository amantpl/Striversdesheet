#include <bits/stdc++.h> 

void merge(long long*& arr,int low,int mid,int high,long long& count ){
    vector<int> temp;
    int i=low;
    int j=mid+1;

    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            count+=mid-i+1;
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }

    while(j<=high){
        temp.push_back(arr[j]);
        j++;
    }

    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}

void mergesort(long long*& arr,int low,int high,long long& count){
    if(low>=high){
        return ;
    }

    int mid=(low+high)/2;

    mergesort(arr,low,mid,count);
    mergesort(arr,mid+1,high,count);
    merge(arr,low,mid,high,count);
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    long long count=0;
    int low=0;
    int high=n-1;
    mergesort(arr,low,high,count);
    return count;
}
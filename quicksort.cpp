#include <iostream>
#include<algorithm>
using namespace std;
int partition(int arr[],int s,int e){
    int c=0;
    int pivot=arr[s];
    for(int i=s+1;i<=e;i++){
        if(arr[i]<pivot){
            c++;
        }
    }
    int cnt=c+s;
    swap(arr[cnt],arr[s]);
    int low=s,high=e;
    while(low<cnt && high>cnt){
        while(arr[low]<pivot){
            low++;
        }
        while(arr[high]>pivot){
            high--;
        }
        if(low<cnt && high>cnt) {
            swap(arr[low++], arr[high--]);
        }
        
    }
    return cnt;
}
void quicksort(int arr[],int s,int e){
    if(s>e){
        return;
    }
     int p = partition(arr, s, e);

    //left part sort karo
    quicksort(arr, s, p-1);

    //right wala part sort karo
    quicksort(arr, p+1, e);
}

int main()
{
    int arr[]={2,3,55,7,7,86,56,56,4,545,456,6,7,8,8};
    int e=sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,e-1);
    for(int i=0;i<e;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
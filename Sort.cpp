/******************************************************************************************************************************/
/************************************               ****** ****** ******  ******           ************************************/
/************************************               ***    **  ** *   **    **             ************************************/
/************************************               ****** **  ** *******   **             ************************************/
/************************************                  *** **  ** ** **     **             ************************************/
/************************************               ****** ****** **   **   **             ************************************/
#include<iostream> 
#include<algorithm>
#include<fstream>
#include<queue>
using namespace std;
// selection sort O(n*n)
void select_sort(int * arr , int size){
     for(int i=0 ;i <size;i++){
           int idx_min =i;
          for(int j=i+1; j<size;j++){
                if(arr[j]<arr[idx_min]){
                    idx_min =j;
                }
          }
          swap(arr[idx_min],arr[i]);
     }
}
// insert sort O(n*n)
void insert_sort(int * arr, int size){
    for(int i=1 ; i<size;i++)
    for(int j=i-1;j>=0;j--)
        if(arr[i]<arr[j])
        swap(arr[i],arr[j]);
        else break;        
}
// merge sort
void merge(int * arr, int l,int m ,int r){
         int n1 = m-l+1;
         int n2 = r-m;
         int L[n1];
         int R[n2];
         // create two arr to store arr[l] and arr[r]
         for(int i=0;i<n1;i++)
          L[i]= arr[l+i];
         for(int i=0 ; i< n2;i++)
          R[i] =arr[m+i+1];
          // sort and merge 
        int i=0,j =0,t=l;
        while(i<n1&&j<n2){
                if(L[i]<=R[j]){
                    arr[t]=L[i];
                    i++;
                }
                else
                {
                    arr[t]=R[j];
                    j++;
                }  
                t++;
        }
        while(i<n1){
            arr[t]=L[i];
            i++;
            t++;
        }
        while(j<n2){
            arr[t]=R[j];
            j++;
            t++;
        }
        
}
void merge_sort(int * arr, int l, int r){
    if(l<r){
        int m = l+ (r-l)/2;
        merge_sort(arr,l,m);
        merge_sort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}
void shell_sort(int *arr,int size){
    int interval =0;
    while(interval< size/3){
        interval = interval*3+1;
    }
    while(interval>0){
        for (int outer= interval; outer< size;outer++){
            int value_insert = arr[outer];
            int inner = outer;
            while(inner > interval-1 && arr[inner-interval] >= value_insert){ // insert sort 
               arr[inner]=arr[inner-interval];
               inner = inner -interval;
            }
            arr[inner] = value_insert;
        }
        interval =( interval-1)/3;
    }
    
}
// Quick sort with pivot is array[size-1]
int partition(int* arr,int left , int right , int pivot){
    int ind_left = left;
    int ind_right =right-1;
    while(true){
     if(arr[ind_left]<pivot)
     ind_left++;
     if(arr[ind_right]<pivot){
         swap(arr[ind_right],arr[ind_left]);
         ind_left++;
     }
     ind_right--;
    if(ind_left > ind_right){
         swap(arr[ind_left],arr[right]);
         return ind_left;
     }
    }
}
void quick_sort(int *arr , int left , int right){
     if(right-left <= 0)
     return;
     else
     {
          int pivot = arr[right];
          int parti = partition(arr,left,right,pivot);
          quick_sort(arr,left,parti-1);
          quick_sort(arr,parti+1,right);
     }
     
}
int main(){
    int *arr = new int [5];
    arr[0]=33;
    arr[1]=2;
    arr[2]=52;
    arr[3]=100;
    arr[4]=73;
    quick_sort(arr,0,4);
    for(int i=0; i<5;i++)
    cout<<arr[i]<<" ";
}
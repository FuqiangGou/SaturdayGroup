//
//  sort1.c
//  sort
//
//  Created by wby on 2019/11/28.
//  Copyright © 2019 wby. All rights reserved.
//  内排序：插入排序，折半查找，选择插入，泡排序，希尔排序，快排，堆排，二路归并排序（未实现）

#include <stdio.h>
void charusort(int k[],int n);
void zhebancharu(int k[],int n);
void print(int k[],int n);
void xuanzecharu(int k[],int n);
void paopaisort(int k[],int n);
void shellsort(int k[],int n);
void quickSort(int arry[], int left, int right);
void heap_sort(int k[],int n);
void adjust(int k[],int i,int n);
int main(){
    int K[]= {49,38,97,76,65,13,27,50};
//    charusort(K,8);
//    zhebancharu(K,8);
//    xuanzecharu(K,8);
//    paopaisort(K,8);
//    shellsort(K,8);
//    quickSort(K,0,7);
//    heap_sort(K,7);
    int a[]={13,27,38,49,50,65,76,97};
    int location=binarysearch(a,8,97);
    printf("输出结果为%d",location);
//    print(K,8);
}
//插入排序
void charusort(int k[],int n){
    int i,j;
    int temp;
    for (i=1;i<n;i++){
        temp = k[i];
        j=i-1;
        while(j>=0 && temp<k[j] ){
            k[j+1] = k[j];
            k[j]=temp;
            j--;
        }
    }
}

void print(int k[],int n){
    for (int i=0;i<n;i++){
        printf("%d\n",k[i]);
    }
}
//折半插入法
void zhebancharu(int k[],int n){
    int i,j,temp;
    for (i=1;i<n;i++){
        temp = k[i];
        int high = i-1;
        int low = 0;
        //确定插入位置为low
        while(low<=high){
            int mid=(low+high)/2;
            if(temp<k[mid]){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        for(j=i-1;j>=low;j--){
            k[j+1]=k[j];
        }
        k[low]=temp;
    }
}
//选择插入法
void xuanzecharu(int k[],int n){
    int i,j,d;
    int temp;
    for (i=0;i<n;i++){
        //寻找值最小的元素，并记录其位置
        d=i;
        for(j=i+1;j<n;j++){
            if(k[j]>k[d]){
                d=j;
            }
        }
        if(d!=i){
            //最小值元素非非排序元素的第一个元素时
            temp=k[i];
            k[i]=k[d];
            k[d]=temp;
        }
    }
}
//泡排序法
void paopaisort(int k[],int n){
    int i,j;
    int temp;
    for (i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(k[j]>k[j+1]){
                temp=k[j];
                k[j]=k[j+1];
                k[j+1]=temp;
            }
        }
    }
}
//希尔排序法
void shellsort(int k[],int n){
    int i,j,gap=n;
    int temp,flag;
    while(gap>1){
        gap=gap/2;
        do{
            flag=0;//每趟排序前，标志flag置为0
            for(i=0;i<n-gap;i++){
                j=i+gap;
                if(k[i]>k[j]){
                    temp=k[i];
                    k[i]=k[j];
                    k[j]=temp;
                }
            }
        }while(flag!=0);
        
    }
}
//快速排序
void quickSort(int arry[], int left, int right) {
    int begin =  left;
    int end = right;
    if(left > right) {
        return;
    }
    while(left != right) {
        while(right > left && arry[right] >= arry[begin]) {
            right --;
        }
        while(left < right && arry[left] <= arry[begin]) {
            left ++;
        }
        int tmp = arry[right];
        arry[right] = arry[left];
        arry[left] = tmp;
    }
    int tmpBase = arry[begin];
    arry[begin] = arry[left];
    arry[left] = tmpBase;
    quickSort(arry, begin, left - 1);
    quickSort(arry, left + 1, end);
}
//堆排序
void heap_sort(int k[],int n){
    int i;
    int temp;
    //建立初始堆
    for(i=n/2;i>=1;i--){
        adjust(k,i,n);
    }
    for(i=n-1;i>=1;i--){
        temp = k[i+1];
        k[i+1]=k[1];
        k[1]=temp;
        adjust(k,1,i);
    }
}
void adjust(int k[],int i,int n){
    int j;
    int temp;
    temp = k[i];
    j=2*i;
    while(j<=n){
        if(j<n&&k[j]<k[j+1]){
            j++;
        }
        if(temp>=k[j]){
            break;
        }
        k[j/2]=k[j];
        j=j*2;
    }
    k[j/2]=temp;
}
//练习1折半查找元素某元素{13,27,38,49,50,65,76,97};
int binarysearch(int a[],int n,int k){
    int low=0,high=n-1,mid;
    while(low<=high){
        mid=(high+low)/2;
        if(a[mid]==k){
            return mid;//返回mid
        }
        if(k>a[mid]){
            low=mid+1;//准备查找后半部分
        }else{
            high=mid-1;//准备查找前半部分
        }
    }
    return high;//返回high
}

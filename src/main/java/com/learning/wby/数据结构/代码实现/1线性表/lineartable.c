//
//  LinkList.c
//  LinkList
//
//  Created by wby on 2019/11/20.
//  Copyright © 2019 wby. All rights reserved.
//  顺序表
//
#include <stdio.h>
#define MaxSize 100
#define ElementType int
typedef struct {
    ElementType data[MaxSize];
    int length;
}Lineartable;
Lineartable* INITAL();
//插入法插入元素到线性表中
void INSERT(ElementType x,int i,Lineartable *lineartable);
//查找元素所在顺序表中位置
int LOCATE(Lineartable *lineartable,int item);
//线性表中指定位置插入元素
int INSERTITEM(Lineartable *lineartable,int i,int item);
void print(Lineartable *lineartable);
//删除元素，删除第i个位置的元素
int DELETE(Lineartable *lineartable,int i);
//插入元素到有序线性表中
void INSERTSORT(Lineartable *lineartable,ElementType item);
//通过键盘建立n个不重复元素的顺序表
void BUILDLIST(int A[],int n);
//删除数组中重复元素
void del(ElementType A[],int n);
int main()
{
    ElementType A[]={1,2,3,3,4,5,6,7,7,8};
    del(A,10);
//    //定义一个线性表
//    Lineartable *lineartable;
//    //初始化一个线性表
//    lineartable = INITAL();
//    //插入法插入元素到线性表中
//    for(int i=0;i<10;i++){
//        INSERT(i,i,lineartable);
//    }
//    //查找元素所在线性表位置
//    int result = LOCATE(lineartable,2);
//    printf("元素2所在位置为：%d\n",result);
//    //线性表中指定位置插入元素
//    printf("在第3个位置上插入元素12后元素显示如下\n：");
//    INSERTITEM(lineartable,3,12);
//    print(lineartable);
//    //删除指定位置线性表元素
//    printf("删除第3个位置元素后显示如下\n");
//    DELETE(lineartable,3);
//    print(lineartable);
//    //将新数据插入到有序的线性表中
//    printf("将新数据7插入到有序的顺序表中,并输出元素\n");
//    INSERTSORT(lineartable,7);
//    print(lineartable);
//    int b[] = {};
//    BUILDLIST(b,3);
};
//初始化线性表
Lineartable* INITAL(){
    Lineartable *lineartable;
    lineartable = (Lineartable *)malloc(sizeof(Lineartable));
    lineartable->length=0;
    return lineartable;
};
//insert插入法像线性表中插入元素
void INSERT(ElementType x,int i,Lineartable *lineartable){
    if(i<0||i>lineartable->length){
        //
        printf("插入位置不合理");
        return ;
    }else{
        for(int j=lineartable->length;j>=i-1;j--){
            lineartable->data[j+1]=lineartable->data[j];
        }
        lineartable->data[i-1]=x;
        lineartable->length++;
        return ;
    }
}
//查找元素所在顺序表中位置
int LOCATE(Lineartable *lineartable,int item){
    int n= lineartable->length;
    for(int i=0;i<n;i++){
        if (lineartable->data[i]==item){
            return i+1;//查找成功，返回所在表中位置
        }
    }
    return -1;//查找失败，返回-1
    
};
//插入元素,第i个位置上插入item
int INSERTITEM(Lineartable *lineartable,int i,int item){
    if(lineartable->length ==MaxSize|| i<1||i> (lineartable->length+1)){
        //测试空间是否满了
        return -1;//插入失败
    }else{
        for(int j= (lineartable->length -1);j>=i-1;j--){
            lineartable->data[j+1]=lineartable->data[j];//元素依次后移一个位置
        }
        lineartable->data[i-1]=item;//将item插入表的第i个位置
        lineartable->length ++;//线性表长度加1
        return 1;//插入成功
    }
};
//输出全部元素
void print(Lineartable *lineartable){
    for(int i=0;i< (lineartable->length);i++){
        printf("%d\t",lineartable->data[i]);
    }
}
//删除元素，删除第i个位置的元素
int DELETE(Lineartable *lineartable,int i){
    if(i<1||i>(lineartable->length)){//测试表空和位置合适与否
        return -1;//删除失败
    }
    for(int j=i;j<(lineartable->length);j++){
        lineartable->data[j-1]=lineartable->data[j];//元素依次前移一个位置
    }
    (lineartable->length)--;//线性表长度减1
    return 1;//删除成功
}
//插入元素到有序线性表中
void INSERTSORT(Lineartable *lineartable,ElementType item){
    int i,j;
    int n=lineartable->length;
    if(item >= lineartable->data[n-1]){
        //特殊情况，插入表尾部
         lineartable->data[n]=item;
    }else{
        i=0;
        while(item >= lineartable->data[i]){
            //寻找插入位置
           i++;
        }
        for(j=n-1;j>=i;j--){//将item插入表中
            lineartable->data[j+1]=lineartable->data[j];
        }
        lineartable->data[i]=item;
        lineartable->length ++;
    }
}
//通过键盘建立n个不重复元素的顺序表
void BUILDLIST(int A[],int n){
    int flag = 0,j,i=0;
    printf("input the first data\n");
    scanf("%d",&A[0]);
    while(i<n-1){
        printf("input data\n");
        scanf("%d",&A[i+1]);
        for (j=0; j<=i; j++) {
            if(A[j] == A[i+1]){
                flag =1;
                break;
            }
            
        }
        if(!flag){
            i++;
        }else{
            flag = 0;
        }
    }
}
//删除有序数组中重复元素
void del(ElementType A[],int n){
    int i=0,j;
    while(i<n-1){
        if(A[i]!=A[i+1]){//比较相邻元素
            i++;
        }else{
            for(j=i+1;j<n;j++){//删除元素，元素左移
                A[j-1]=A[j];
            }
            n--;
        }
    }
}
//删除有序数组中重复元素（升级版）
void del1(ElementType A[],int n){
    int i=0,k=0;
    if(n>1){
        for(int i=0;i<n;i++){
            if(A[i]!=A[k]){//当a[i]画与a[k]不相等时
                A[++k]=A[i];
            }
        }
        n=k+1;//得到删除后的数组表长
    }
}

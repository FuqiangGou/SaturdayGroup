//
//  BTREE.c
//  tree
//
//  Created by wby on 2019/12/16.
//  Copyright © 2019 wby. All rights reserved.
//  二叉树线性表存储结构（非递归）

#include <stdio.h>
#include <stdlib.h>
#define MaxNode 100
#define datatype int


//深度为h的二叉树，求其叶子结点个数
int leaf1(char bt[],int h);
//二叉树中序遍历（非递归）
void INORDER(char bt[],int n);
//二叉树前序遍历非递归
void PREORDER(char bt[],int n);
//二叉树按层次遍历（非递归）
void layerorder(char bt[],int n);
int main(){
    char bt[]={'a','b','c','d','e',NULL,'f',NULL,NULL,'g','h',NULL,NULL,NULL,NULL};
    int total=leaf1(bt,4);
    printf("leaf is %d\n",total);
    printf("中序遍历结果为\n");
    INORDER(bt,15);
    printf("\n前序遍历结果为\n");
    PREORDER(bt,15);
    printf("\n按层次遍历结果为\n");
    layerorder(bt,15);
}
//深度为h的二叉树，求其叶子结点个数（非递归）
int leaf1(char bt[],int h){
    int i,total=0;
    for(i=0;i<(int)(pow(2,h))-1;i++){
        //判断bt[i]是否为叶子结点
        if (bt[i]!=NULL ) {
            if((bt[i*2+1]==NULL && bt[2*i+2]==NULL)||(i>(int)(pow(2,h-1)-1))){
                total++;
            }
        }
        
    }
    return total;
}
//二叉树中序遍历非递归
void INORDER(char bt[],int n){
    int stack[MaxNode];
    int i=0;
    int top=-1;
    if(n>=0){
        do{
            while(i<n){
                stack[++top]=i;//bt[i]的位置i进栈
                i=i*2+1;//找到i的左孩子的位置
            }
            i=stack[top--];//退栈
            printf("%c",bt[i]);//访问结点bt[i]
            i=i*2+2; //找到i的右孩子的位置
        }while(!(top==-1&&i>n-1));
    }
}
//二叉树前序遍历非递归
void PREORDER(char bt[],int n){
    int stack[MaxNode];
    int i=0;
    int top=-1;
    if(n>=0){
        do{
            while(i<n){
                printf("%c",bt[i]);//访问结点bt[i]
                stack[++top]=i;//bt[i]的位置i进栈
                i=i*2+1;//找到i的左孩子的位置
            }
            i=stack[top--];//退栈
            
            i=i*2+2; //找到i的右孩子的位置
        }while(!(top==-1&&i>n-1));
    }
}
//二叉树按层次遍历（非递归）
void layerorder(char bt[],int n){
    //使用顺序队列
    char queue[MaxNode];
    char p;
    int front,rear;
    int i=0;
    if(n>=0){
        queue[0]=bt[0];
        front=-1;
        rear=0;
        while(front<rear && i<(n/2)){
            
            //若队列不为空
            p=queue[++front];
            printf("%c",p);//访问p指结点
            if(bt[(2*i+1)]!=NULL){//若左孩子非空
                queue[++rear]=bt[(2*i+1)];
            }
            if(bt[(2*i+2)]!=NULL){//若右孩子非空
                queue[++rear]=bt[(2*i+2)];
            }
            i=i+1;
        }
    }
}
//插入，同线性表结构插入
//删除，同线性表结构删除

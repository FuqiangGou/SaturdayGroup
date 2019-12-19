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
int main(){
    char bt[]={'a','b','c','d','e',NULL,'f',NULL,NULL,'g','h',NULL,NULL,NULL,NULL};
    int total=leaf1(bt,4);
    printf("leaf is %d\n",total);
    printf("中序遍历结果为\n");
    INORDER(bt,15);
   
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

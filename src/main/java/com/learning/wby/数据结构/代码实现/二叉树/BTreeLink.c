//
//  BTREELINK.c
//  tree
//
//  Created by wby on 2019/12/16.
//  Copyright © 2019 wby. All rights reserved.
//  二叉树链表（非递归）


#include <stdio.h>
#include <stdlib.h>
#define MaxNode 100
#define datatype char
typedef struct node{
    datatype data;
    struct node *lchild,*rchild;
}BTREE;
//顺序存储结构建立二叉链表
BTREE* buildbtree(char bt[],int n);
//二叉树的先序遍历（非递归）
void PreOrderTraverse(BTREE* T);
//二叉树中序遍历（非递归）
void INORDER(BTREE* T);
//二叉树按层次遍历（非递归）
void layerorder(BTREE* T);
//深度为h的二叉树，求其叶子结点个数
int leaf1(char bt[],int h);
//释放以p所指结点为根的子树上的所有结点,后序遍历的递归算法
void release(BTREE * p);
//删除某结点
BTREE* del(BTREE * t,datatype item);
int main(){
    char bt[]={'a','b','c','d','e',NULL,'f',NULL,NULL,'g','h',NULL,NULL,NULL,NULL};
    int total=leaf1(bt,4);
    printf("leaf is %d\n",total);
    BTREE* t=NULL;
    t=buildbtree(bt,15);
    printf("先序遍历：");
    PreOrderTraverse(t);
    printf("\n按中序遍历：");
    INORDER(t);
    printf("\n按层次遍历：");
    layerorder(t);
    printf("\n删除某结点后");
    t=del(t,'b');
    printf("先序遍历：");
    PreOrderTraverse(t);
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
//顺序存储结构建立二叉链表
BTREE* buildbtree(char bt[],int n){
    BTREE* t=NULL;
    t=(BTREE*)malloc(sizeof(BTREE));
    if(NULL == t){
        printf("分配空间失败");
        exit(-1);
    }
    for(int i=0;i<n;i++){
        t[i].data=bt[i];
        t[i].lchild=NULL;
        t[i].rchild=NULL;
    }
    for(int i=0;i<n;i++){
        int j=2*i+1;
        if(j<n&&bt[j]!=NULL){
            //有左孩子
            t[i].lchild=&t[2*i+1];
        }else{
            t[i].lchild=NULL;
        }
        int k = 2*i+2;
        if(k<n && bt[k]!=NULL){
            //有右孩子
            t[i].rchild=&t[2*i+2];
        }else{
            t[i].rchild=NULL;
        }
        
    }
    return t;
}
//二叉树的先序遍历（非递归）
void PreOrderTraverse(BTREE* T){
    BTREE* stack[MaxNode];
    BTREE* p=T;
    int top=-1;
    if(T!=NULL){
        do{
            while(p!=NULL){
                printf("%c",p->data);
                stack[++top]=p;
                p=p->lchild;
            }
            p=stack[top--];
            p=p->rchild;
        }while(!(p==NULL&&top==-1));
    }
}
//二叉树中序遍历非递归算法
void INORDER(BTREE* T){
    BTREE* stack[MaxNode];
    BTREE* p=T;
    int top=-1;
    if(T!=NULL){
        do{
            while(p!=NULL){
                stack[++top]=p;
                p=p->lchild;
            }
            p=stack[top--];
            printf("%c",p->data);
            p=p->rchild;
        }while(!(p==NULL&&top==-1));
    }
}
//按层次遍历（非递归）
void layerorder(BTREE* T){
    //使用顺序队列
    BTREE* queue[MaxNode];
    int front,rear;
    BTREE* p=T;
    if(T!=NULL){
        queue[0]=T;
        front=-1;
        rear=0;
        while(front<rear){
            //若队列不为空
            p=queue[++front];
            printf("%c",p->data);//访问p指结点
            if(p->lchild!=NULL){//若左孩子非空
                queue[++rear]=p->lchild;
            }
            if(p->rchild!=NULL){//若右孩子非空
                queue[++rear]=p->rchild;
            }
        }
    }
}
////释放以p所指结点为根的子树上的所有结点,后序遍历的递归算法
//void release(BTREE * p){
//    if(p!=NULL){
//        release(p->lchild);
//        release(p->rchild);
//        free(p);//释放一个链结点的空间
//    }
//}
////删除某结点（好难o(╯□╰)o ）--未实现
//BTREE* del(BTREE * t,datatype item){
//    BTREE * stack[MaxNode],*q,*p;
//    p=t;
//    int top=-1;
//    do{
//        while(p!=NULL){
//            //查看结点元素是否是item
//            if(p->data==item){
//                if (p==t) {
//                    t=NULL;
//                }else{
//                    printf("%c",q->lchild->data);
//                    printf("%c",p->data);
//                    if((q->lchild)==p){
//                        q->lchild == NULL;
//                    }else{
//                        q->rchild == NULL;
//                    }
//                }
//                release(p);
//
//            }
//            stack[++top]=p;
//            q=p;//记录双亲结点的位置
//            p=p->lchild;
//        }
//        p=stack[top--];
//        q=p;//记录双亲结点的位置
//        p=p->rchild;
//    }while(!(p==NULL && top == -1));
//    return t;
//}

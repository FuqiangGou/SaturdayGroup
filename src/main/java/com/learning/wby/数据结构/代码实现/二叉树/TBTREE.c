//
//  TBTREE.c
//  tree
//
//  Created by wby on 2019/12/17.
//  Copyright © 2019 wby. All rights reserved.
//  线索二叉树（感觉好难，不开心o(╯□╰)o ）

#include <stdio.h>
#define datatype char
#define NodeNum 100
typedef struct node{
    datatype data;
    struct node *lchild,*rchild;
    int lbit,rbit;
}TBTREE;
//创建一个二叉树
TBTREE * createbitree();
//线索二叉树的线索化
TBTREE* INTHREAD(TBTREE *T);
//中序遍历线索二叉树
void InorderTraverse(TBTREE* T);
int main(){
    TBTREE* T,*head;
    T=createbitree();
    head = INTHREAD(T);
    InorderTraverse(head);
}
//创建一个二叉树
TBTREE * createbitree(){
    TBTREE *T;
    char ch=0;
    printf("print ");
    scanf("%c",&ch);
    if(ch=='#'){
        T=NULL;
    }else{
        T = (TBTREE*)malloc(sizeof(TBTREE));
        T->data=ch;
        T->lchild = createbitree();
        T->rchild = createbitree();
    }
    return T;
}
//线索二叉树的线索化（中序遍历）--难>_<
TBTREE* INTHREAD(TBTREE *T){
    printf("线索二叉树的线索化\n");
    TBTREE* head,*p=T,*prior,*stack[NodeNum];
    int top=-1;
    head = (TBTREE*)malloc(sizeof(TBTREE));//申请线索二叉树的头结点空间
    head->lchild=T;
    head->rchild=head;
    head->lbit=1;
    prior=head;//假设中序序列的第一个结点的前驱为头结点
    do{
        while(p!=NULL){
            stack[++top]=p;//p指结点的地址进栈
            p=p->lchild;//p移到左孩子结点
        }
        p=stack[top--];//退栈
        if(p->lchild==NULL){//若当前访问结点的左孩子为空
            p->lchild=prior;//当前访问结点的左指针域指向前一次访问结点
            p->lbit=0;//当前访问结点的左标志域置0（表示地址为线索）
        }else{
            p->lbit=1;//当前访问结点的左标志域置1（表示地址为指针）
        }
        if(prior->rchild==NULL){//若前一次访问结点的右孩子为空
            prior->rchild=p;//前一次访问结点的右指针域指向当前访问结点
            prior->rbit=0;//前一次访问d结点的右指针域置0（表示地址为线索）
        }else{
            prior->rbit=1;//前一次访问结点的o右标志域置1（表示地址为指针）
        }
        prior=p;//记录当前访问的结点的地址
        p=p->rchild;//p移到右孩子结点
    }while(!(p==NULL&&top==-1));
    prior->rchild=head;//设中序序列的最后结点的后继为头结点
    prior->rbit=0;//prior指结点的右标志域置0（表示地址为线索）
    return head;//返回线索二叉树的头结点指针
}
//寻找直接后继结点
TBTREE * InOrderNext(TBTREE *T){
    TBTREE* p;
    p=T->rchild;
    if(T->rbit == 1){
        while(p->rbit == 1){
            p=p->lchild;
        }
    }
    return p;
}
//寻找直接前驱结点
TBTREE * InOrderPre(TBTREE *T){
    if(T->lbit==0){
        return T->lchild;
    }
    //找到左子树
    TBTREE *p;
    p=T->lchild;
    while(p->lbit==1){
        p=p->rchild;
    }
    return p;
}
//中序遍历线索二叉树
void InorderTraverse(TBTREE* T){
    printf("中序遍历线索二叉树\n");
    TBTREE* p=T->lchild;
    while(p!=T){
        //找到子树每一个结点
        while(p->lbit == 1){
            p=p->lchild;
        }
        printf("%c",p->data);
        //依次遍历直接后继，知道转移到右子树或者遍历结束
        while(p->rbit==0 && p->rchild!=T){
            p=p->rchild;
            printf("%c",p->data);
        }
        p=p->rchild;
    }
    printf("\n");
}

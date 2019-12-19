//
//  BTreeLink1.c
//  tree
//
//  Created by wby on 2019/12/16.
//  Copyright © 2019 wby. All rights reserved.
//  二叉树（链表）（递归）
#include<stdio.h>
#include<stdlib.h>
typedef struct BiTNode{
    char data;
    struct BiTNode *lchild,*rchild;
}BiTree;
//二叉树的先序遍历
void PreOrderTraverse(BiTree* T){
    if(T==NULL)
        return ;
    printf("%c ",T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}
//二叉树的中序遍历
void InOrderTraverse(BiTree* T){
    if(T==NULL)
        return ;
    InOrderTraverse(T->lchild);
    printf("%C ",T->data);
    InOrderTraverse(T->rchild);
}
void PostOrderTraverse(BiTree* T){
    if(T==NULL)
        return;
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf("%c ",T->data);
}

//创建一个二叉树
BiTree * CreateBiTree(){
    BiTree *T;
    char ch=0;
    printf("print ");
    scanf("%c",&ch);
    if(ch=='#'){
        T=NULL;
    }else{
        T = (BiTree*)malloc(sizeof(BiTree));
        T->data=ch;
        T->lchild = CreateBiTree();
        T->rchild = CreateBiTree();
    }
    return T;
}
//复制二叉树
BiTree * copybt(BiTree *t){
    BiTree *t2;
    if(t == NULL){
        return NULL;
    }else{
        t2=(BiTree *)malloc(sizeof(BiTree ));
        t2->data = t->data;
        t2->lchild=copybt(t->lchild);//递归复制左子树
        t2->rchild=copybt(t->rchild);//递归复制右子树
    }
    return t2;
}
//判断两棵树是否等价
int isequal(BiTree *t1,BiTree * t2){
    if(t1==NULL && t2==NULL){//两棵树为空
        return 1;
    }
    if(t1->data == t2->data
       && isequal(t2->lchild,t2->lchild)
       && isequal(t2->rchild, t2->rchild)){
        return 1;
    }
    return 0;
}
void pri(){
    printf("\n");
}
// 二叉树叶子节点个数（递归方法）
int leaf_num(BiTree * T){
    if (T == NULL)
        return 0;
    if (T->lchild == NULL && T->rchild == NULL)
        return 1;
    
    return (leaf_num(T->lchild) + leaf_num(T->rchild));
}

int main(){
    BiTree * T;
    printf("输入树(#代表空节点 AB#C##D##):");
    T=CreateBiTree();
    printf("前序遍历的结果是:");
    PreOrderTraverse (T);
    printf("\n中序遍历的结果是:");
    InOrderTraverse(T);
    printf("\n后序遍历的结果是:");
    PostOrderTraverse(T);
    pri();
    int num = leaf_num(T);
    printf("二叉树叶节点的个数为：%d\n", num);
    printf("复制二叉树t，e结果为\n");
    BiTree * t2=copybt(T);
    printf("前序遍历的结果是:");
    PreOrderTraverse (t2);
    printf("判断两棵树是否等价");
    int flag = isequal(T,t2);
    return 0;
}

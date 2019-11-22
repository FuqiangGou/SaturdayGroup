//
//  LinkList2.c
//  LinkList
//
//  Created by wby on 2019/11/21.
//  Copyright © 2019 wby. All rights reserved.
//单向循环链表
//约瑟夫问题，已知n个人，围坐在一个圆桌周围，编号为k的人从1开始报数，数到m的那个人出列，他的下一个人从1开始继续报数，疏导m的那个人出列，直到圆桌周围人全部出列

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100
#define ElementType int
typedef struct node{
    ElementType data;
    struct node *link;
}LNode,*LinkList;
void JOSEPHU(int n,int k,int m);
int main(){
    int n,k,m;
    printf("%\ninput n,k,m");
    //输入链结点总数n，报数的起始位置k和报数m
    scanf("%d%d%d",&n,&k,&m);
    JOSEPHU(n,k,m);
}
//约瑟夫函数
void JOSEPHU(int n,int k,int m){
    //建立一个无头结点的非循环链表
    LinkList p,r,list;
    list = NULL;//创建一个空链表
    ElementType a;
    for(int i=1;i<=n;i++){
        printf("请输入第%d个数据",i);
        scanf("%d",&a);
        p = (LinkList) malloc(sizeof(LinkList));//申请一个新的链结点
        p->data = a;
        p->link=NULL;
        if (list == NULL) {
            list = p;
        }else{
            r->link = p;//将新结点链接在链表尾部
        }
        r=p;
    }
    p->link=list;//循环链表
    //接下来
    p=list;
    for(int i=1;i<=k-1;i++){//找到第一个点
        r=p;//当k不等于1，m等于1时
        p=p->link;
        
    }
    while(p->link!=p){//反复寻找并删除结点
        for(int i=1;i<=m-1;i++){
            r=p;
            p=p->link;
        }
        r->link = p->link;
        printf("删除元素%3d",p->data);
        free(p);
        p=r->link;
    }
    printf("%3d",p->data);
}

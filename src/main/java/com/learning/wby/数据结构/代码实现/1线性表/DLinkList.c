//
//  LinkList2.c
//  LinkList
//
//  Created by wby on 2019/11/21.
//  Copyright © 2019 wby. All rights reserved.
// 双向循环链表
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100
#define ElemType int
ElemType A[MaxSize];

int n;

typedef struct node {
    ElemType data;
    struct node *llink,*rlink;
}DNode,*DLinkList;
DLinkList CREATE(int n);
void INSERTNODE(DLinkList list,DLinkList p);
void print(DLinkList list);
int INSERTD(DLinkList list,ElemType item,ElemType x);
int DELETE(DLinkList list,ElemType item);
int main(){
    DLinkList list = CREATE(5);
    print(list);
    printf("shanchu 3");
    DELETE(list,3);
    print(list);

}
DLinkList CREATE(int n){
    //建立一个无头结点的非循环链表
    DLinkList p,list;
    list = (DLinkList)malloc(sizeof(DLinkList));//创建一个空链表
    list->data = 0;
    list->rlink = list;
    list->llink = list;
    for(int i=0;i<n;i++){
        int a ;
        p=(DLinkList)malloc(sizeof(DLinkList));
        printf("请输入第%d个数据\n",i);
        scanf("%d",&a);
        //将指针为p的结点插入到头结点指针为list的双向循环链表中
        p->data = a;
        p->llink = NULL;
        p->rlink = NULL;
        INSERTNODE(list,p);
    }
    return list;
    
}
void INSERTNODE(DLinkList list,DLinkList p){
    list->llink->rlink = p;
    p->llink = list->llink;
    p->rlink = list;
    list->llink = p;
}
void print(DLinkList list){
    printf("打印双向循环列表中数据\n");
    DLinkList t;
    t=list->rlink;
    while(t->data>0){
        printf("%d\n",t->data);
        t=t->rlink;
    }
}
//带有头结点非空双向s循环链表，第一个数据域内容为x的链结点右边插入item新结点
int INSERTD(DLinkList list,ElemType item,ElemType x){
    DLinkList p,q;
    //寻找满足条件的结点
    q=list->rlink;//q初始指向头结点的下一个结点
    while(q!=list && q->data!=x){//寻找满足条件的链结点
        q=q->rlink;
    }
    if(q==list){
        return -1;//没有找到满足条件的结点
    }
    p=(DLinkList)malloc(sizeof(DNode));//申请一个新的结点
    p->data = item;
    p->llink = q;
    p->rlink = q->rlink;
    q->rlink ->rlink = p;
    q->rlink = p;
    return 1;//插入成功
}
//双向链表的删除
int DELETE(DLinkList list,ElemType item){
    DLinkList p,q;
    q=list->rlink;//q初始指向头结点的下一个结点
    while(q!=list && q->data!=item){//找满足条件的链结点
        q=q->rlink;
    }
    if(q==list){
        return -1;//没有找到满足条件的结点
    }
    q->llink->rlink = q->rlink;
    q->rlink->llink = q->llink;
    free(q);//释放被删除的结点的存储空间
    return 1;//删除成功
}

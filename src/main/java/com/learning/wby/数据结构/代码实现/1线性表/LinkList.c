//
//  LinkList.c
//  LinkList
//
//  Created by wby on 2019/11/20.
//  Copyright © 2019 wby. All rights reserved.
//  单线性链表
//

#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100
#define ElementType int
typedef struct node{
    ElementType data;
    struct node *link;
}LNode,*LinkList;
//求链表长度
int LENGTH(LinkList list);
//创建链表
LinkList CREATE(int n);
//输出链表
void print(LinkList list);
//插入item元素
void INSERTLINK1(ElementType item,LinkList list);
//指定位置插入元素item
void INSERTLINK3(LinkList list,int i,ElementType item);
int main(){
    LinkList list;
    ElementType item;
    printf("create linklist\n");
    list = CREATE(10);
    int length = LENGTH(list);
    printf("链表长度为%d\n",length);
    print(list);
    printf("请输入想插入到链表头的数据");
    scanf("%d",&item);
    INSERTLINK1(item,list);
    print(list);
    printf("在第2个结点后插入数据\n");
    INSERTLINK3(list,2,item);
    print(list);
    
}
//创建线性链表
LinkList CREATE(int n){
    LinkList p,r,list=NULL;
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
    
    
    return list;
}
//求线性链表长度，非递归算法
int LENGTH(LinkList list){
    LinkList p = list;
    int n=0;//链表长度置初值为0
    while(p!=NULL){
        p=p->link;
        n++;
    }
    return n;//返回链表长度
}
//打印链表中的数据
void print(LinkList list){
    LinkList p;
    p=list;
    printf("输出链表中的数据\n");
    while(p!=NULL){
        printf("%d\t",p->data);
        p=p->link;
    }
}
//第一个结点前插入数据项item的新结点
void INSERTLINK1(ElementType item,LinkList list){
    LinkList p;//list指向链表第一个链结点
    p=(LinkList)malloc(sizeof(LinkList));//s申请一个新结点
    p->data = item;//将item送新结点数据域
    p->link = list;//将list送新结点指针域
    list = p;//修改指针list指向
}
//在链结点q后面插入数据信息为item的链结点
void INSERTLINK2(LinkList list,LinkList q,ElementType item){
    LinkList p;
    p=(LinkList)malloc(sizeof(LinkList));//构造一个新结点
    p->data = item;//将item送新结点数据域
    if(list == NULL){//若原链表为空
        list = p;
        p->link = NULL;
    }else{//原链表不为空
        p->link = q->link;
        q->link = p;
    }
    
}
//在第i个结点后面插入一个数据信息为item的新结点
void INSERTLINK3(LinkList list,int i,ElementType item){
    LinkList p,q=list;
    for(int j=0;j<=i-1;j++){//存在第i个结点
        q=q->link;
        if(q == NULL){//不存在第i个结点
            break;
        }
    }
    p=(LinkList)malloc(sizeof(LinkList));//构造一个新结点
    p->data = item;//将item送入新结点数据域
    p->link = q->link;
    q->link = p;//将新结点插入到第i个结点之后
}
//从非空线性链表中删除q指的链结点，设q的直接前驱结点由r指出
void DELETELINK1(LinkList list,LinkList r,LinkList q){
    if(q == list){
        list = q->link;//删除链表的第一个链结点
    }else{
        r->link = q->link;//删除q指的链结点
       
    }
    free(q);//释放被删除的结点空间
}
//从非空链表中删除q指的链结点
void DELETELINK2(LinkList list,LinkList q){
    LinkList r;
    if(q == list){//当删除链表第一个结点
        list = list->link;
        free(q);//释放被删除结点的空间
    }else{
        //寻找q结点的直接前驱r
        r = list;
        while(r->link !=q && r->link!=NULL){//移向下一个链结点
            r = r->link;
        }
        if(r->link != NULL){
            r->link = q->link;
            free(q);
        }
    }
}
//查找list所指线性链表倒数第k个结点
LinkList SEARCHNODE(LinkList list ,int k){
    LinkList p,q;
    int i;
    if(list!=NULL && k>0){
        for(i=1;i<k;i++){//循环结束时，p指向链表的第k个结点
            p = p->link;
            if(p==NULL){
                printf("链表不存在倒数第k个结点");
            }
        }
    }
    q=list;
    while(p->link!=NULL){
        p=p->link;
        q=q->link;
    }//p指向链表最后那个结点，q指向倒数第k个结点
    return q;//给出链表倒数第k个结点（q指向的那个结点）的地址
}

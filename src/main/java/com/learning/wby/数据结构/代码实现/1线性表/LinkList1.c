//
//  LinkList1.c
//  LinkList
//
//  Created by wby on 2019/12/9.
//  Copyright © 2019 wby. All rights reserved.
//单向循环列表

#include <stdio.h>
#define MaxSize 100
#define ElementType int
typedef struct node{
    ElementType data;
    struct node *link;
}LNode,*LinkList;
void print(int k);
int main(){
    print(10);
}
//从第3个元素后开始顺序输出元素
void print(int k){
    LinkList list,p,r;
    int i,a;
    //建立循环链表
    list = (LinkList)malloc(sizeof(LNode));
    list->data = 0;
    r=list;
    for(int i=1;i<k;i++){
        printf("输入第%d个数",i);
        scanf("%d",&a);
        p=(LinkList)malloc(sizeof(LNode));
        p->data=a;
        r->link = p;
        r=p;
    }
    p->link = list;
    p=list;
    printf("从第3个数开始顺序输出\n");
    for(int j=0;j<3;j++){
        p=p->link;
    }
    r=p;
    do{
        printf("%d\t",p->data);
        p=p->link;
    }while(p!=r);
}

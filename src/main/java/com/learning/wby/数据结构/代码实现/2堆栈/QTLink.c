//
//  QTLink.c
//  duizhanduilie
//
//  Created by wby on 2019/12/11.
//  Copyright © 2019 wby. All rights reserved.
//  队列的链式存储结构

#include <stdio.h>
#include <stdlib.h>
#define M 10
#define QElemType int
typedef  struct node{
    QElemType data;
    struct node *link;
}QLinkNode;
typedef struct{
    QLinkNode* front;
    QLinkNode* rear;
}LinkQueue;
//初始化队列
void INIITALQ(LinkQueue* linkqueue);
//测试队列是否为空
int EMPTYQ(LinkQueue* linkqueue);
//插入元素
void ADDLINKQ(LinkQueue* linkqueue,QElemType item);
//删除一个元素
void DELLINKQ(LinkQueue* linkqueue);
//输出队列的值
void print(LinkQueue* linkqueue);
//取对头元素
int gethead(LinkQueue* linkqueue);
//清空队列
void clearqueue(LinkQueue* linkqueue);
int main(){
    LinkQueue* linkqueue;
    INIITALQ(linkqueue);
    printf("向队列中插入元素");
    for(int i=1;i<5;i++){
         ADDLINKQ(linkqueue,i);
    }
    print(linkqueue);
    printf("从队列中删除元素");
    for(int i=1;i<5;i++){
        DELLINKQ(linkqueue);
    }
    print(linkqueue);

}
//初始化队列
void INIITALQ(LinkQueue* linkqueue){
    LinkQueue* head = (LinkQueue* )malloc(sizeof(LinkQueue));
//    assert(head);
    linkqueue->front=linkqueue->rear=head;
    linkqueue->front->link = NULL;
}
//测试队列是否为空
int EMPTYQ(LinkQueue* linkqueue){
    if(linkqueue->front->link == NULL){
        return 1;
    }
    return 0;
}
//插入元素
void ADDLINKQ(LinkQueue* linkqueue,QElemType item){
    QLinkNode* p;
    p=(QLinkNode*)malloc(sizeof(QLinkNode));
//    assert(p);
    p->data = item;
    p->link= NULL;
    if(linkqueue->front == NULL){//插入空队情况
        linkqueue->front = p;
    }else{//插入非空队的情况
        linkqueue->rear ->link = p;
    }
    linkqueue->rear = p;
}
//删除一个元素
void DELLINKQ(LinkQueue* linkqueue){
    QElemType item;
    QLinkNode* p;
    if(EMPTYQ(linkqueue)){
        
    }else{
        p=linkqueue->front->link;
        linkqueue->front=p->link;
        item = p->data;
        if(linkqueue->rear = p){
            linkqueue->rear = linkqueue->front;
        }
        free(p);
    }
}
//输出队列的值
void print(LinkQueue* linkqueue){
    QLinkNode* p;
    p=linkqueue->front->link;
    while(p){
        printf("%d",p->data);
        p=p->link;
    }
}
//取对头元素
int gethead(LinkQueue* linkqueue){
    int item;
    if(EMPTYQ(linkqueue)){
        printf("queue is null\n");
    }
    QLinkNode* p;
    p=linkqueue->front->link;
    item = p->data;
    return item;
}
//清空队列
void clearqueue(LinkQueue* linkqueue){
    while(linkqueue->front!=NULL){
        linkqueue->rear = linkqueue->front->link;
        free(linkqueue->front);
        linkqueue->front=linkqueue->rear;
    }
}

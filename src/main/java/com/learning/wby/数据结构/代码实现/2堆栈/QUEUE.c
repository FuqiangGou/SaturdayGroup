//
//  QUEUE.c
//  duizhanduilie
//
//  Created by wby on 2019/12/11.
//  Copyright © 2019 wby. All rights reserved.
// 队列的顺序存储结构

#include <stdio.h>
#define M 100
#define QElemType int
//初始化队列
void INITIALQ(int front,int rear);
//测试队列是否为空
int EMPTYQ(int front,int rear);
//插入队列
int ADDQ(QElemType QUEUE[],int rear,QElemType item);
//删除队列算法
int POP(QElemType QUEUE[],int front,int rear,QElemType item);
void print(QElemType QUEUE[],int front,int rear);
int main(){
    QElemType queue[M];
    int front,rear;
    INITIALQ(front,rear);
    for(int i=1;i<=5;i++){
        rear = ADDQ(queue,rear,i);
    }
    printf("向queue中添加元素\n");
    print(queue,front,rear);
    printf("向queue中delete元素\n");
    for(int i=1;i<=5;i++){
         front = POP(queue,front,rear,i);
    }
    print(queue,front,rear);
}

//初始化队列
void INITIALQ(int front,int rear){
    front=-1;
    rear=-1;
}
//测试队列是否为空
int EMPTYQ(int front,int rear){
    return front==rear;
}
//插入队列
int ADDQ(QElemType QUEUE[],int rear,QElemType item){
    if(rear == M-1){//队满
        return 0;
    }else{
        QUEUE[rear++]=item;
        return rear;
    }
}
//删除队列算法
int POP(QElemType QUEUE[],int front,int rear,QElemType item){
    if(EMPTYQ(front,rear)){
        return 0;
    }else{
        item = QUEUE[++front];
        return front;
    }
}
void print(QElemType QUEUE[],int front,int rear){
    for(int i=front;i<=rear;i++){
        printf("%d\t",QUEUE[i]);
    }
}

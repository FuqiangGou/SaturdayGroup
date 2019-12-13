//
//  STLink.c
//  duizhanduilie
//
//  Created by wby on 2019/12/10.
//  Copyright © 2019 wby. All rights reserved.
//  堆栈的链式存储结构
#include <stdio.h>
#include <stdlib.h>

#define ElemType int
typedef struct node{
    ElemType data;
    struct node *link;
}STLink;
//初始化堆栈
STLink* INITIALS();
//测试堆栈是否为空
int EMPTYS(STLink* top);
//插入元素
STLink* pushlink(STLink* top,ElemType item);
STLink* createstack(STLink* top);
//删除元素
STLink* poplink(STLink* top);
void print(STLink* top);
int main(){
    STLink* top;
    top=INITIALS();
    top = createstack(top);
    printf("栈中元素\n");
    print(top);
    printf("insert element\n");
    top=pushlink(top,5);
    print(top);
    printf("删除后栈中元素都有：\n");
    for(int i=1;i<=5;i++){
        top = poplink(top);
    }
    print(top);
}
//初始化堆栈
STLink* INITIALS(){
    return NULL;
}
//测试堆栈是否为空
int EMPTYS(STLink* top){
    return top == NULL;
}

STLink* createstack(STLink* top){

    int x;
    STLink *p;
    printf("以输入-1为结束\n");
    scanf("%d",&x);
    while(x!=-1)
    {
        p=(STLink*)malloc(sizeof(STLink));
        p->data=x;
        p->link=top;
        top=p;
        scanf("%d",&x);
    }
    return top;

}
//插入元素
STLink* pushlink(STLink*top,ElemType item){
    STLink* p;
    if(!(p=(STLink* )malloc(sizeof(STLink)))){
        return NULL;
    }else{
        p->data = item;//将item送新结点数据域
        p->link = top;//将新结点插在链表最前面
        top=p;//修改栈顶指针指向
        return top;
    }
}
//删除元素
STLink* poplink(STLink* top){
    STLink* p;
    ElemType item;
    if(EMPTYS(top)){
        return NULL;//删除失败
    }else{
        p=top;//暂时保存栈顶结点地址
        item = top->data;//保存被删栈顶的数据信息
        top=top->link;//删除栈顶结点
        free(p);//释放被删除结点
        return  top;//删除成功
    }
}
void print(STLink* top){
    STLink* p=top;
    if(!top){
        printf("该链式栈是空的\n");
    }
    else{
        while(p){
            printf("%d  ",p->data);
            p=p->link;
        }
    }
}

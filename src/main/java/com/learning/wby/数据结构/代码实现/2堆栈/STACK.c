//
//  stack.c
//  duizhanduilie
//
//  Created by wby on 2019/12/10.
//  Copyright © 2019 wby. All rights reserved.
//  堆栈的顺序存储结构

#include <stdio.h>
#define M 5
#define SElemType int
//堆栈初始化
void INITIALS(int top);
//堆栈是否为空
int EMPTYS(int top);
//堆栈是否已满
int FULLS(int top);
//向堆栈栈顶插入元素
int push(SElemType stack[],int top,SElemType item);
//多堆栈插入操作
int pushtwostack(SElemType stack[],int top[],int i,SElemType item);
//多堆栈插入操作
int pushtwostack1(SElemType stack[],int top[],int i,SElemType item);
//删除操作
int poptwostack(SElemType stack[],int top[],int i,SElemType item);
//从堆栈栈顶删除元素
int pop(SElemType stack[],int top);
//打印栈中数据
void print(SElemType stack[],int top);
int main(){
    SElemType stack[M]={};
    int top;
    INITIALS(top);
    for(int i=1;i<=5;i++,top++){
        push(stack,top,i);
    }
    printf("向栈中添加元素\n");
    print(stack,top);
    for(int i=1;i<=5;i++,top--){
        pop(stack,top);
    }
    printf("删除后栈中元素都有：\n");
    print(stack,top);
}
//堆栈初始化
void INITIALS(int top){
    top=-1;
}
//堆栈是否为空
int EMPTYS(int top){
    return top ==-1;
}
//堆栈是否已满
int FULLS(int top){
    return top==M-1;
}
void print(SElemType stack[],int n){
    for(int i=0;i<n;i++){
        printf("%d\n",stack[i]);
    }
}
//向堆栈栈顶插入元素
int push(SElemType stack[],int top,SElemType item){
    if(FULLS(top)){
        return 0;
    }else{
        stack[++top]=item;
        return 1;
    }
    
}
//从堆栈栈顶删除元素
int pop(SElemType stack[],int top){
    SElemType item;
    if(EMPTYS(top)){
        return 0;
    }else{
        item=stack[top--];
        return 1;
    }
}
//多栈共享连续空间问题
//插入操作
int pushtwostack(SElemType stack[],int top[],int i,SElemType item){
    if(top[0]==top[1]){
        return 0;//栈满
        
    }else{
        if(i==1){//插入第一个栈
            stack[++top[0]]==item;
        }else{//插入第2个栈
            stack[++top[1]]==item;
        }
        return 1;
    }
}
//插入操作升级版
int pushtwostack1(SElemType stack[],int top[],int i,SElemType item){
    if(top[0]==top[1]){
        return 0;//栈满
    }else{
        if(i==1){
            top[0]++;//修改第一个栈顶指针
        }else{//修改第2个栈顶指针
            top[1]++;
        }
        stack[top[i-1]]==item;
        return 1;
    }
}
//删除操作
int poptwostack(SElemType stack[],int top[],int i,SElemType item){
    if(i==1){
        //对第一个栈进行操作
        if(top[0]==-1){
            return 0;//栈满
        }else{
            item=stack[top[0]--];
            return 1;
        }
    }else{
        //对第二个栈进行操作
        if(top[1]==M){
            return 0;//栈满
        }else{
            item=stack[top[1]++];
            return 1;
        }
    }
}

////
////  SORTREE.c
////  tree
////
////  Created by wby on 2019/12/18.
////  Copyright © 2019 wby. All rights reserved.
////  二叉排序树
//
//#include <stdio.h>
//#include <stdlib.h>
//#define maxsize 100
//#define datatype int
//
//typedef struct node{
//    datatype data;
//    struct node *lchild,*rchild;
//}BTREE;
//
//BTREE * INSERTBST(BTREE *t,datatype item);
////建立二叉排序树
//BTREE* SORTTREE(datatype k[],int n);
////查找某元素，存在返回位置，不存在返回null,非递归算法
//BTREE* SORTSEARCH1(BTREE* T,datatype key);
////查找某元素，存在返回位置，不存在返回null，递归算法
//BTREE* SORTSEARCH2(BTREE* T,datatype key);
////打印某结点祖先结点
//void printpre(BTREE* t,datatype item);
////判断是否为二叉排序树
//void testsorttree(BTREE* t);
//int main(){
//    BTREE* p=NULL,*t=NULL;
//    datatype k[]={50,35,70,40,50,65,20,80};
//    t=SORTTREE(k,8);
//    printpre(t,20);
//    //    p=SORTSEARCH1(t,35);
//    testsorttree(t);
//}
////插入元素，非递归算法
////将一个数据元素item插入到根指针为t的二叉排序树中
//BTREE * INSERTBST(BTREE *t,datatype item){
//    BTREE * p,*q;
//    //建立新结点
//    p=(BTREE *)malloc(sizeof(BTREE ));
//    p->data=item;
//    p->lchild=NULL;
//    p->rchild=NULL;
//    if(t==NULL){
//        t=p;
//    }else{
//        q=t;
//        while(1){
//            if(item<q->data){
//                if(q->lchild==NULL){
//                    //插入结点
//                    q->lchild=p;
//                    break;
//                }else{
//                    q=q->lchild;
//                }
//            }else{
//                if(q->rchild==NULL){
//                    //插入结点
//                    q->rchild=p;
//                    break;
//                }else{
//                    q=q->rchild;
//                }
//            }
//        }
//    }
//    return  t;
//}
////建立二叉排序树
//BTREE* SORTTREE(datatype k[],int n){
//    BTREE * t;
//    int i;
//    for(i=0;i<n;i++){
//        t=INSERTBST(t,k[i]);
//    }
//    return t;
//}
////查找某元素，存在返回位置，不存在返回null，非递归算法
//BTREE* SORTSEARCH1(BTREE* T,datatype key){
//    
//    BTREE *p=T;
//    while(p!=NULL){
//        if(p->data==key){
//            return p;//查找成功
//        }
//        if(p->data<key){
//            p=p->rchild;//将p移到右子树根结点
//        }else{
//            p=p->lchild;//将p移到左子树根结点
//        }
//    }
//    return NULL;//查找失败
//}
////查找算法，递归算法
//BTREE* SORTSEARCH2(BTREE* T,datatype key){
//    if(T!=NULL){
//        if(T->data == key){
//            return T;//查找成功
//        }
//        if(T->data <key){
//            return SORTSEARCH2(T->rchild, key);//查找t的右子树
//        }else{
//            return SORTSEARCH2(T->lchild,key);//查找t的左子树
//        }
//    }
//    return NULL;//查找失败
//}
////打印某结点祖先结点
//void printpre(BTREE* t,datatype item){
//    printf("%d的祖先结点为:",item);
//    BTREE* p = t;
//    while(p!=NULL){
//        if(item==p->data){//查找结束
//            break;
//        }
//        if(p->data<item){
//            printf("%d\t",p->data);
//            p=p->rchild;//将p移到右子树的根结点
//        }else{
//            printf("%d\t",p->data);
//            p=p->lchild;//将p移到左子树的根结点
//        }
//    }
//    
//}
////判断是否为二叉排序树
//void testsorttree(BTREE* t){
//    BTREE* stack[maxsize],*p=t;
//    int top=-1;
//    datatype last = 0;//最小值
//    if(t!=NULL){
//        do{
//            while(p!=NULL){
//                stack[++top]=p;
//                p=p->lchild;
//            }
//            p=stack[top--];
//            if(p->data<last){
//                printf("该树不是二叉排序树\n");
//            }
//            last=p->data;
//            p=p->rchild;
//        }while(!(p==NULL && top==-1));
//    }
//    printf("该树是二叉排序树");
//}
////删除某结点（感觉好难，不开心o(╯□╰)o ）------未做完
////void delete(BTREE* p){
////    if(p!=NULL){
////        BTREE* q,*s;
////        if(NULL == p->lchild && NULL !=p->rchild){
////            //无左孩子,有右孩子
////            q=p->rchild;
////            p->data=q->data;
////            p->rchild = q->rchild;
////            p->lchild = q->lchild;
////            free(q);
////        }else if(NULL == p->rchild && NULL !=p->lchild){
////            //无右孩子,有左孩子
////            q=p->lchild;
////            p->data=q->data;
////            p->rchild = q->rchild;
////            p->lchild = q->lchild;
////            free(q);
////        }else if(NULL != p->rchild && NULL != p->lchild){
////            //既有左孩子，又有右孩子
////            q=p;
////            s=p->rchild;
////            while(s->lchild){
////                q=s;
////                s=s->lchild;
////            }
////            p->data = s->data;
////            if(q!=p){
////                q->rchild = p->lchild;
////
////            }else{
////                q->lchild = s->lchild;
////            }
////            free(s);
////        }else{
////
////        }
////    }
////}

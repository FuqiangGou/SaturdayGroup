#include <stdio.h>
#define MaxSize 100
#define ElementType int
typedef struct {
    ElementType data[MaxSize];
    int length;
}Lineartable;
Lineartable* INITAL();
void INSERT(ElementType x,int i,Lineartable *lineartable);
int LOCATE(Lineartable *lineartable,int item);
int INSERTITEM(Lineartable *lineartable,int i,int item);
void print(Lineartable *lineartable);
int DELETE(Lineartable *lineartable,int i);
void INSERTSORT(Lineartable *lineartable,ElementType item);

int main()
{
    ElementType A[]={1,2,3};
    //定义一个线性表
    Lineartable *lineartable;
    //初始化一个线性表
    lineartable = INITAL();
    //插入法插入元素到线性表中
    for(int i=0;i<10;i++){
        INSERT(i,i,lineartable);
    }
    //查找元素所在线性表位置
    int result = LOCATE(lineartable,2);
    printf("元素2所在位置为：%d\n",result);
    //线性表中指定位置插入元素
    printf("在第3个位置上插入元素12后元素显示如下\n：");
    INSERTITEM(lineartable,3,12);
    print(lineartable);
    //删除指定位置线性表元素
    printf("删除第3个位置元素后显示如下\n");
    DELETE(lineartable,3);
    print(lineartable);
    //将新数据插入到有序的线性表中
    printf("将新数据7插入到有序的顺序表中,并输出元素\n");
    INSERTSORT(lineartable,7);
    print(lineartable);
};
//初始化线性表
Lineartable* INITAL(){
    Lineartable *lineartable;
    lineartable = (Lineartable *)malloc(sizeof(Lineartable));
    lineartable->length=0;
    return lineartable;
};
//insert插入法像线性表中插入元素
void INSERT(ElementType x,int i,Lineartable *lineartable){
    if(i<0||i>lineartable->length){
        //
        printf("插入位置不合理");
        return ;
    }else{
        for(int j=lineartable->length;j>=i-1;j--){
            lineartable->data[j+1]=lineartable->data[j];
        }
        lineartable->data[i-1]=x;
        lineartable->length++;
        return ;
    }
}
//查找元素所在顺序表中位置
int LOCATE(Lineartable *lineartable,int item){
    int n= lineartable->length;
    for(int i=0;i<n;i++){
        if (lineartable->data[i]==item){
            return i+1;//查找成功，返回所在表中位置
        }
    }
    return -1;//查找失败，返回-1
    
};
//插入元素,第i个位置上插入item
int INSERTITEM(Lineartable *lineartable,int i,int item){
    if(lineartable->length ==MaxSize|| i<1||i> (lineartable->length+1)){
        //测试空间是否满了
        return -1;//插入失败
    }else{
        for(int j= (lineartable->length -1);j>=i-1;j--){
            lineartable->data[j+1]=lineartable->data[j];//元素依次后移一个位置
        }
        lineartable->data[i-1]=item;//将item插入表的第i个位置
        lineartable->length ++;//线性表长度加1
        return 1;//插入成功
    }
};
//输出全部元素
void print(Lineartable *lineartable){
    for(int i=0;i< (lineartable->length);i++){
        printf("%d\t",lineartable->data[i]);
    }
}
//删除元素，删除第i个位置的元素
int DELETE(Lineartable *lineartable,int i){
    if(i<1||i>(lineartable->length)){//测试表空和位置合适与否
        return -1;//删除失败
    }
    for(int j=i;j<(lineartable->length);j++){
        lineartable->data[j-1]=lineartable->data[j];//元素依次前移一个位置
    }
    (lineartable->length)--;//线性表长度减1
    return 1;//删除成功
}
//插入元素到有序线性表中
void INSERTSORT(Lineartable *lineartable,ElementType item){
    int i,j;
    int n=lineartable->length;
    if(item >= lineartable->data[n-1]){
        //特殊情况，插入表尾部
         lineartable->data[n]=item;
    }else{
        i=0;
        while(item >= lineartable->data[i]){
            //寻找插入位置
           i++;
        }
        for(j=n-1;j>=i;j--){//将item插入表中
            lineartable->data[j+1]=lineartable->data[j];
        }
        lineartable->data[i]=item;
        lineartable->length ++;
    }
}

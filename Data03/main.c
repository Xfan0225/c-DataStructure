//
//  main.c
//  Data03
//
//  Created by 谢 on 2020/3/29.
//  Copyright © 2020 谢. All rights reserved.
//

#include <stdio.h>
void calDiag(int a[][1000],int n){
    int i,ans0=0,ans1=0;
    for (i=0; i<n; i++) {
        ans0+=a[i][i];//正对角线
        ans1+=a[i][n-i-1];//反对角线
    }
    printf("Diag0:%d\nDiag1:%d\n",ans0,ans1);
}

void addTuple(int a[][3],int b[][3],int n0, int n1){
    int i,count=0,j;//count为b元组的计数器
    for (i=0; i<n0; i++) {
        while (a[i][0]>b[count][0]) {//当第二个三元组的x比第一个大时
            for (j=n0-1; j>=i; j--) {//将第一个三元组从i整体后移1
                a[j+1][0]=a[j][0];
                a[j+1][1]=a[j][1];
                a[j+1][2]=a[j][2];
            }
            a[i][0]=b[count][0];//然后把b元组中的数插入到a中
            a[i][1]=b[count][1];
            a[i][2]=b[count][2];
            count++;//b元组位置指示器自加
            n0++;//a元组元素格个数自加
            i++;//a元组指示器自加
            if (count>=n1) {
                break;
            }
        }
        while (a[i][1]>b[count][1]&&a[i][0]>=b[count][0]) {//当第二个元组的y比第一个大时
            for (j=n0-1; j>=i; j--) {//处理方法同上
                a[j+1][0]=a[j][0];
                a[j+1][1]=a[j][1];
                a[j+1][2]=a[j][2];
            }
            a[i][0]=b[count][0];
            a[i][1]=b[count][1];
            a[i][2]=b[count][2];
            count++;
            n0++;
            i++;
            if (count>=n1) {
                break;
            }
        }
        if (a[i][0]==b[count][0]&&a[i][1]==b[count][1]) {//移动完之后假如出现相等情况
            a[i][2]+=b[count][2];//则进行相加
            count++;//并且让b元组的位置指示器自加
        }
        if (count>=n1) {
            break;
        }
    }
    if (count<n1) {//假如最后b元组中还未遍历完
        for (i=count; i<n1; i++) {//则直接接到a元组的末尾
            a[i+n0-count][0]=b[i][0];
            a[i+n0-count][1]=b[i][1];
            a[i+n0-count][2]=b[i][2];
            n0++;
        }
    }
    printf("Ans:\n");
    for (i=0; i<n0; i++) {
        printf("%d %d %d\n",a[i][0],a[i][1],a[i][2]);
    }
}

void foundTuple(int a[][1000],int n,int m){
    int max[1000][3];
    int i,j;
    for (i=0; i<n; i++) {
        for (j=0; j<m; j++) {
            if (a[i][j]>max[i][2]) {//如果比现存的最大值大
                max[i][2]=a[i][j];//记录最大值与其坐标
                max[i][0]=i;
                max[i][1]=j;
            }
        }
    }
    printf("Max:\n");
    for (i=0; i<n; i++) {
        printf("%d %d %d\n",max[i][0],max[i][1],max[i][2]);
    }
}

void Create(){
    int i,j,tube[4][4],count=1,val;
    for (i=0; i<4; i++) {
        for (j=0; j<4; j++) {
            tube[i][j]=count;
            count++;
        }
    }
    for (i=0; i<2; i++) {//利用对角线法交换对角线元素
        val=tube[i][i];
        tube[i][i]=tube[3-i][3-i];
        tube[3-i][3-i]=val;
        val=tube[i][3-i];
        tube[i][3-i]=tube[3-i][i];
        tube[3-i][i]=val;
    }
    for (i=0; i<4; i++) {
        for (j=0; j<4; j++) {
            printf("%d\t",tube[i][j]);
        }
        printf("\n");
    }
}

void calSad(int a[][1000],int m, int n){
    int max[1000][3],min[1000][3],flag=0;
    int i,j;
    for (i=0; i<m; i++) {//先找出每行的最小值，存入三元组
        min[i][2]=a[i][0];//先把初值设为每行的第一个
        min[i][0]=i;
        min[i][1]=0;
        for (j=0; j<n; j++) {
            if (a[i][j]<min[i][2]) {
                min[i][2]=a[i][j];
                min[i][0]=i;
                min[i][1]=j;
            }
        }
    }
    
    for (i=0; i<n; i++) {
        for (j=0; j<m; j++) {//再找出每列的最小值，存入三元组
            if (a[j][i]>max[i][2]) {
                max[i][2]=a[j][i];
                max[i][0]=j;
                max[i][1]=i;
            }
        }
    }
    printf("Ans:\n");
    for (i=0; i<m; i++) {//然后找出在三元组中重复出现的，即为鞍点
        for (j=0; j<n; j++) {
            if (max[i][0]==min[j][0]&&max[i][1]==min[j][1]) {
                printf("%d %d %d\n",max[i][0]+1,max[i][1]+1,max[i][2]);
                flag=1;
                break;
            }
        }
    }
    if (flag==0) {//如果没找到则输出no answer
        printf("No Answer\n");
    }
}


int main() {
    int n=10,i,j,n0,n1,m;
    int a[1000][1000],Tuple1[10][3],Tuple2[10][3];
    /*
    scanf("%d",&n0);
    for (i=0; i<n0; i++) {//手动输入两个三元组
        scanf("%d%d%d",&Tuple1[i][0],&Tuple1[i][1],&Tuple1[i][2]);
    }
    scanf("%d",&n1);
    for (i=0; i<n1; i++) {
        scanf("%d%d%d",&Tuple2[i][0],&Tuple2[i][1],&Tuple2[i][2]);
    }
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            a[i][j]=i+j;//创建一个数值为坐标和的二维数组
        }
    }
     */
    scanf("%d%d",&m,&n);
    for (i=0; i<m; i++) {
        for (j=0; j<n; j++) {
            scanf("%d",&a[i][j]);
        }
    }
//    calDiag(a, n);
//    addTuple(Tuple1, Tuple2, n0, n1);
//    foundTuple(a, n, n);
//    Create();
    calSad(a, n, n);
    return 0;
}



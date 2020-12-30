//
//  main.c
//  数据结构作业
//
//  Created by 谢 on 2020/3/3.
//  Copyright © 2020 谢. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    long double pv,f,t,c,r;
    int flag;
    long i;
    scanf("%d",&flag);
    if (flag) {
        r=0.0001;
        scanf("%Lf%Lf%Lf%Lf",&pv,&c,&t,&f);
        for (i=0; i<1000000; i++,r+=0.0001) {
            if(pv-((c/r)*(1-1/pow(1+r, t))+f/pow(1+r, t))>0){
                printf("YTM:%.2Lf%%\n",r*100);
                return 0;
            }
        }
    }
    else{
        scanf("%Lf%Lf%Lf%Lf",&f,&r,&c,&t);
        pv=((c/r)*(1-1/pow(1+r, t))+f/pow(1+r, t));
        printf("PV:%Lf\n",pv);
    }
    return 0;
}

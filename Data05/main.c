//
//  main.c
//  Data05
//
//  Created by 谢 on 2020/4/10.
//  Copyright © 2020 谢. All rights reserved.
//((a, b, (a, b, (c,(d,e))), (a,(a,(a,(a,a),b),c),d),e,f),f,g)
//((a,b,(a,b,(c,(d,e))),(a,(a,(a,(a,a),b),c),d),e,f),f,g)

#include <stdio.h>
#include <ctype.h>

int main() {
    char inp[100];
    int len,i,depth=0,lenth=1,nowdepth=0,flag=0;
    scanf("%s",&inp);
    len=strlen(inp);
    for (i=0; i<len; i++) {
        if (inp[i]=='(') {//假如是左括号的话
            nowdepth++;//说明当前深度增加了
            if (nowdepth>depth) {//假如当前的深度比最深深度要大
                depth=nowdepth;//那么当前深度就是最大深度
            }
        }
        else if (inp[i]==','&&nowdepth==1) {//假如在深度为1的情况下读到了逗号
            lenth++;//说明元素增加了1个
            flag=1;
        }
        else if (inp[i]==')') {
            nowdepth--;
        }
        else if (isalpha(inp[i])){
            flag=1;//假如说出现了字母，那么肯定不为空
        }
    }
    if (flag==0&&depth==1) {//假如字母一次没出现过，逗号也没出现过，深度还为0，那肯定是元素个数为0
        depth--;
    }
    printf("Depth:%d,Lenth:%d\n",depth,lenth);
    return 0;
}

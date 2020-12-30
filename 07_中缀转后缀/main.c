//
//  main.c
//  07_中缀转后缀
//
//  Created by 谢 on 2020/4/28.
//  Copyright © 2020 谢. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>

int main() {
    char stack[100],inp[100],val;
    int n=0,i,j=0;
    while (1) {//读入字符串，遇到’#‘停止
        val=getchar();
        if (val=='#') {
            break;
        }
        else{
            inp[n]=val;
            n++;
        }
    }
    for (i=0; i<n; i++) {//对字符串进行遍历
        if (isdigit(inp[i])) {//如果是数字的话直接输出
            printf("%c ",inp[i]);
        }
        else{//如果是符号的话
            if (inp[i]==')') {//如果是左括号，则到右括号之前，输出栈内的符号
                while (stack[j-1]!='('&&j>=0) {
                    printf("%c ",stack[j-1]);
                    j--;
                }
                j--;//并且左括号直接出栈，不输出
            }
            else if (inp[i]=='*'||inp[i]=='/'){///如果是乘除号，则输出由栈顶开始依次输出优先级大于等于乘除的符号
                while ((stack[j-1]=='*'||stack[j-1]=='/')&&j>=0) {
                    printf("%c ",stack[j-1]);
                    j--;
                }
                stack[j++]=inp[i];//然后该符号入栈
            }
            else if (inp[i]=='+'||inp[i]=='-'){//如果是加减号，则输出由栈顶开始依次输出优先级大于等于加减的符号
                while ((stack[j-1]=='*'||stack[j-1]=='/'||stack[j-1]=='+'||stack[j-1]=='-')&&j>=0) {
                    printf("%c ",stack[j-1]);
                    j--;
                }
                stack[j++]=inp[i];//然后符号入栈
            }
            else if (inp[i]=='('){//假如是左括号，则直接入栈（括号优先级最低）
                stack[j++]=inp[i];
            }
        }
    }
    for (i=j-1; i>=0; i--) {//最后输出栈内所有未输出的符号
        printf("%c ",stack[i]);
    }
    printf("\n");
}

//2*(9+6/3-5)+4#
//1+2+3*(4/5+6*(7+9)-8)/2#
//1+2+3*(4-(5+6))#

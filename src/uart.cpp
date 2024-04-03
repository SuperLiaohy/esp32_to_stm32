//
// Created by 24106 on 2024/3/27.
//

#include "uart.h"

void number(char* str,short &s,short &p){
    int num=0;
    int val_fu=0;
    for (int i = 0; str[i] != 'b' ; ++i) {
         if (str[i]<='9'&&'0'<=str[i]){
             if (val_fu)
                 num = num * 10 - (str[i] - '0');
             else
                num = num * 10 + (str[i] - '0');
         } else if (str[i]=='-'){
              val_fu = 1;
         } else{
             s = num;
             num = 0;
             val_fu = 0;
         }
    }
    p = num;
}
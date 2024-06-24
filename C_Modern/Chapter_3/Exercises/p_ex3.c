/**
 * @file p_ex3.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-06-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>

int main(void)
{
    int gsi,group_id,publisher_code,item_number,check_digit;
 printf("Enter ISBN:");
 scanf("%d%d%d%d%d",&gsi,&group_id,&publisher_code,&item_number,&check_digit);

 printf("GSI prefix: %d \n",gsi);
 printf("Group identifier: %d \n",group_id);
 printf("publisher code: %d \n",publisher_code);
 printf("item number: %d \n",item_number);
 printf("check digit:%d \n",check_digit);

 return 0;   
}
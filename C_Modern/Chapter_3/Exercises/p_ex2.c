/**
 * @file p_ex2.c
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
  float unit_price;
  int item_number,date;
  printf("Enter the item number:");
  scanf("%d",&item_number);
  printf("Enter the unit price:");
  scanf("%f",&unit_price);
  printf("Enter the date of purchase:");
  scanf("%d",&date);

  printf("item            Unit          Purchase \n");
  printf("               Price             date  \n");
  printf("%d               %.1f            %d",item_number,unit_price,date);
  
 return 0;



}
/**
 * @file p_ex6.c
 * @author your name (you@domain.com)
 * @brief Programa 5 modificado, com outra formula
 * @version 0.1
 * @date 2024-06-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#include <stdio.h>


int main(void)
{
  float x,y;
  printf("Enter a x value: ");
  scanf("%f",&x);

  y = ((((3*x + 2)*x - 5)*x - 1)*x + 7)*x - 6; 
  printf("The result of the eq. is: %.1f",y);
    return 0;
}
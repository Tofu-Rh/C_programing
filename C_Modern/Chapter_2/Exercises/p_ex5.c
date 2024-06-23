/**
 * @file p_ex5.c
 * @author your name (you@domain.com)
 * @brief Este programa aceita um valor x de entrada e 
 * resolve uma eq. polinomial
 * @version 0.1
 * @date 2024-06-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>


int main (void)
{
  float x,y;
  printf("Enter a x value: ");
  scanf("%f",&x);

  y = 3*x*x*x*x*x + 2*x*x*x*x - 5*x*x*x - x*x + 7*x -6; 
  printf("The result of the eq. is: %.1f",y);

return 0;
}
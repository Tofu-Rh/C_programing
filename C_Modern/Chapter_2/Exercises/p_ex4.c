/**
 * @file p_ex4.c
 * @author Rhomulo (you@domain.com)
 * @brief um programa que aumenta uma taxa de 5 por cento
 * do valor de entrada.
 * @version 0.1
 * @date 2024-06-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>

float tax = 0.05f;

int main(void)
{
  float amount,result;
  result = 0;
  printf("Enter the value of your amount:");
  scanf("%f",&amount);
  
  result = amount + tax * amount;

  printf("The value with a %f added is: ",tax);
  printf("%f",result);
  
  return 0;
}
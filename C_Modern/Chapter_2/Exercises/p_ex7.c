/**
 * @file p_ex7.c
 * @author your name (you@domain.com)
 * @brief  Um programa que permite o usuario entrar com a quantia
 * de grana que quer pagar, e orienta para o menor numero de 
 * cedulas necessarias para realizar o pagamento.
 * @version 0.1
 * @date 2024-06-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#include <stdio.h>

int main(void)
{
    int amount,calculate,bills20,bills10,bills5,bills1;
    printf("ENter a dollar amount: \n");
    scanf("%d",&amount);
    
    bills20 = amount/20;
    calculate = amount - 20*bills20;
    bills10 = calculate/10;
    calculate = calculate - 10*bills10;
    bills5 = calculate/5;
    calculate = calculate - 5*bills5;
    bills1 = calculate;


    printf("20 bills: %d \n",bills20);
    printf("10 bills: %d \n",bills10);
    printf("5 bills: %d \n",bills5);
    printf("1 bills: %d \n",bills1);
    return 0;
}
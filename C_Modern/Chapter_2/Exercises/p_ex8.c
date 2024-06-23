/**
 * @file p_ex8.c
 * @author your name (you@domain.com)
 * @brief Calcula a quantia necessária de pagamento restante apos
 * ser quitado a primeira parcela
 * @version 0.1
 * @date 2024-06-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>

int main(void)
{
    float amount,rate,month_rate,month_payment,result;
    printf("Enter amount of loan:");
    scanf("%f",&amount);
    printf("Enter interest rate:");
    scanf("%f",&rate);
    printf("Enter monthly payment:");
    scanf("%f",&month_payment);

    month_rate = 1 + rate/1200;

    result = amount*month_rate - month_payment;
    printf("Balance remaining after first payment: %.2f",result);

    result = result*month_rate - month_payment;
    printf("Balance remaining after first payment: %.2f",result);

    result = result*month_rate - month_payment;
    printf("Balance remaining after first payment: %.2f",result);

    return 0;
}
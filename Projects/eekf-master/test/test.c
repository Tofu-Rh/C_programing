#include <stdio.h>

int main(void){
    FILE *fp;
    fp  = fopen ("data.log", "w");

    size_t count = 10; // Example count value
    for (size_t i = 1; i <= count; i++) {
        fprintf(fp, "print this on line %lu\n", (unsigned long)i);  
    }

    fclose(fp); // Always close the file after finishing writing
    return 0;
}
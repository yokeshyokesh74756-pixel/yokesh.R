#include <stdio.h>
 
unsigned long checks = 0;
 
int prime_for(unsigned long n)
{
    checks = 0;
    if (n < 2) return 0;
    for (unsigned long i = 2; i <= n / i; i++) {
        checks++;
        if (n % i == 0) return 0;
    }
    return 1;
}
 
int prime_while(unsigned long n)
{
    checks = 0;
    if (n < 2) return 0;
    unsigned long i = 2;
    while (i <= n / i) {
        checks++;
        if (n % i == 0) return 0;
        i++;
    }
    return 1;
}
 
int prime_do_while(unsigned long n)
{
    checks = 0;
    if (n < 2) return 0;
    unsigned long i = 2;
    if (i > n / i) return 1;
    do {
        checks++;
        if (n % i == 0) return 0;
        i++;
    } while (i <= n / i);
    return 1;
}
 
int prime_basic(unsigned long n)
{
    checks = 0;
    if (n < 2) return 0;
    for (unsigned long i = 2; i < n; i++) {
        checks++;
        if (n % i == 0) return 0;
    }
    return 1;
}
 
int main(void)
{
    unsigned long tickets[] = {97, 100, 7919, 1000003};
    int n = sizeof tickets / sizeof tickets[0];
 
    printf("Improved for-loop:\\n");
    for (int k = 0; k < n; k++) {
        int p = prime_for(tickets[k]);
        printf("%8lu %-9s divisions = %lu\\n",
               tickets[k], p ? "prime" : "not prime", checks);
    }
 
    printf("\\nLoop versions for 97:\\n");
    prime_for(97); printf("for divisions = %lu\\n", checks);
    prime_while(97); printf("while divisions = %lu\\n", checks);
    prime_do_while(97); printf("do-while divisions = %lu\\n", checks);
 
    return 0;
}


#include <stdio.h>
 
unsigned long checks = 0;
 
int prime_original_sqrt(unsigned long n)
{
    checks = 0;
    if (n < 2) return 0;
    for (unsigned long i = 2; i <= n / i; i++) {
        checks++;
        if (n % i == 0) return 0;
    }
    return 1;
}
 
int prime_odd_only(unsigned long n)
{
    checks = 0;
    if (n < 2) return 0;
    if (n == 2) return 1;
    checks++;
    if (n % 2 == 0) return 0;
 
    for (unsigned long i = 3; i <= n / i; i += 2) {
        checks++;
        if (n % i == 0) return 0;
    }
    return 1;
}
 
int main(void)
{
    unsigned long values[] = {97, 100, 7919, 1000003};
    int n = sizeof values / sizeof values[0];
 
    printf("Number   Original checks   Redesigned checks\\n");
    for (int k = 0; k < n; k++) {
        unsigned long original, revised;
        prime_original_sqrt(values[k]);
        original = checks;
        prime_odd_only(values[k]);
        revised = checks;
        printf("%8lu %15lu %19lu\\n",
               values[k], original, revised);
    }
    return 0;
}

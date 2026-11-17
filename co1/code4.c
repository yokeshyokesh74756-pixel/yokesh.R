#define RUPEES_TO_PAISE(x) ((long long)(x) * 100LL) 
#include <stdio.h> 
  
#define SQUARE(x)     ((x) * (x)) 
#define BAD_SQUARE(x) (x * x)          /* no parentheses: unsafe */ 
#define MAX(a, b)     ((a) > (b) ? (a) : (b)) 
  
static inline long long max_ll(long long a, long long b) 
{ 
    return a > b ? a : b; 
} 
  
int main(void) 
{ 
    int a = 3; 
    printf("BAD_SQUARE(a+1)=%d SQUARE(a+1)=%d\n", BAD_SQUARE(a + 1), SQUARE(a + 1)); 
  
    int i = 5, j = 3; 
    int m = MAX(i++, j); 
    printf("MAX(i++,j)=%d i=%d\n", m, i); 
  
    i = 5; 
    long long k = max_ll(i++, j); 
    printf("max_ll(i++,j)=%lld i=%d\n", k, i); 
    return 0; 
} 
  
static inline long long square_ll(long long x) 
{ 
    return x * x; 
}

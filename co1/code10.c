#include <stdio.h> 
int main(void) 
{ 
long long counts[] = {4000, 60000, 800000}; 
for (int c = 0; c < 3; c++) { 
long long n = counts[c]; 
long long exact = n * 16250LL;   /* Rs 162.50 = 16250 paise */ 
float f = 0; 
double d = 0; 
for (long long i = 0; i < n; i++) { 
f += 162.50f; 
d += 162.50; 
} 
int ov = (int)exact;             
}
/* narrowing to 32-bit int */ 
printf("n=%lld exact paise=%lld float=%.2f double=%.2f int-cast=%d\n", 
n, exact, f, d, ov); 
} 
return 0; 

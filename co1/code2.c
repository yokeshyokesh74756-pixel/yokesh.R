#include <stdio.h> 
#include <limits.h> 
#include <float.h> 
typedef unsigned short meter_t; 
unsigned int consumption(meter_t previous, meter_t current) 
{ 
return (unsigned short)(current - previous); 
} 
int main(void) 
{ 
printf("short=%zu int=%zu long=%zu long long=%zu double=%zu\n", 
sizeof(short), sizeof(int), sizeof(long), 
sizeof(long long), sizeof(double)); 
printf("USHRT_MAX=%u INT_MAX=%d LONG_MAX=%ld LLONG_MAX=%lld\n", 
(unsigned)USHRT_MAX, INT_MAX, LONG_MAX, LLONG_MAX); 
printf("FLT_MAX=%g DBL_MAX=%g\n", (double)FLT_MAX, DBL_MAX); 
printf("sizeof(meter_t) = %zu bytes, maximum reading = %u\n", 
sizeof(meter_t), (unsigned)USHRT_MAX); 
printf("Consumption: %u units\n", consumption(1200, 1530)); 
printf("Consumption: %u units\n", consumption(65400, 120)); 
}
long long total_paise = 0; 
for (int i = 0; i < 4000; ++i) 
total_paise += 16250; /* Rs 162.50 in paise */ 
printf("Total paise = %lld (Rs %lld.%02lld)\n", 
total_paise, total_paise / 100, total_paise % 100); 
return 0; 

#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
typedef unsigned short meter_t; 
#define SLAB1_UNITS 100 
#define SLAB2_UNITS 200 
#define RATE1_PAISE 0L 
#define RATE2_PAISE 225L 
#define RATE3_PAISE 450L 
#define FIXED_CHARGE_PAISE 5000L 
unsigned int consumption(meter_t previous, meter_t current) 
{ 
return (unsigned short)(current - previous); 
} 
long long compute_bill(unsigned int units) 
{ 
long long energy = 0; 
if (units > SLAB2_UNITS) 
energy += (long long)(units - SLAB2_UNITS) * RATE3_PAISE; 
if (units > SLAB1_UNITS) { 
unsigned int middle = units < SLAB2_UNITS 
? units - SLAB1_UNITS 
                              : SLAB2_UNITS - SLAB1_UNITS; 
        energy += (long long)middle * RATE2_PAISE; 
    } 
    if (units <= SLAB1_UNITS) 
        energy += (long long)units * RATE1_PAISE; 
    return energy + FIXED_CHARGE_PAISE; 
} 
  
int main(void) 
{ 
    unsigned int previous, current, units; 
  
    printf("Enter previous and current meter readings: "); 
    if (scanf("%u %u", &previous, &current) != 2 || 
        previous > USHRT_MAX || current > USHRT_MAX) { 
        printf("Invalid meter input\n"); 
        return 1; 
    } 
  
    units = consumption((meter_t)previous, (meter_t)current); 
    if (current < previous && units > 10000) { 
        printf("Reading difference requires manual rollover validation\n"); 
        return 1; 
    } 
  
    long long total = compute_bill(units); 
    printf("Units: %u\n", units); 
    printf("Energy and fixed total: Rs %lld.%02lld\n", 
           total / 100, total % 100); 
    return 0; 
}

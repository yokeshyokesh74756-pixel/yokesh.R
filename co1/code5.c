/* billing.h */ 
#ifndef BILLING_H 
#define BILLING_H 
#define SLAB1_UNITS 100 
#define SLAB2_UNITS 200 
#define RATE1_PAISE 0 
#define RATE2_PAISE 225 
#define RATE3_PAISE 450 
#define FIXED_CHARGE_PAISE 5000L 
  
long compute_bill(int units); 
  
#endif 
  
/* debug macro */ 
#ifdef DEBUG 
#define DEBUG_PRINT(...) printf(__VA_ARGS__) 
#else 
#define DEBUG_PRINT(...) ((void)0) 
#endif 
  
/* inside the bill calculation: */ 
DEBUG_PRINT("units=%d paise=%ld\n", units, paise); 
  
/* build:  gcc -DDEBUG billing.c main.c -o billing */ 

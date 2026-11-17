#include <stdio.h> 
#include <limits.h> 
  
typedef unsigned short meter_t;          /* 16-bit meter counter */ 
typedef enum { DOMESTIC, COMMERCIAL, INDUSTRIAL } Category; 
  
#define SLAB1_UNITS        100 
#define SLAB2_UNITS        200 
#define RATE2_PAISE        225LL 
#define RATE3_PAISE        450LL 
#define FIXED_CHARGE_PAISE 5000LL 
  
typedef struct { 
    meter_t previous;          /* last meter value            */ 
    meter_t current;           /* latest meter value          */ 
    char household[11];        /* text: keeps leading zeroes  */ 
    Category category;         /* small fixed set of labels   */ 
    unsigned int units;        /* difference incl. rollover   */ 
    long long energy_paise;    /* slab charge                 */ 
    long long fixed_paise;     /* fixed charge                */ 
    long long total_paise;     /* energy + fixed              */ 
} Bill; 
  
static const char *cat_name[] = {"Domestic", "Commercial", "Industrial"}; 
  
long long energy_charge(unsigned int u) 
{ 
    long long e = 0; 
    if (u > SLAB2_UNITS) e += (long long)(u - SLAB2_UNITS) * RATE3_PAISE; 
    if (u > SLAB1_UNITS) 
        e += (long long)((u < SLAB2_UNITS ? u : SLAB2_UNITS) - SLAB1_UNITS) * 
RATE2_PAISE; 
    return e;                  /* first 100 units are free */ 
} 
  
void show(const Bill *b) 
{ 
    printf("Household number : %s\n", b->household); 
    printf("Category         : %s\n", cat_name[b->category]); 
    printf("Previous reading : %u\n", (unsigned)b->previous); 
    printf("Current reading  : %u\n", (unsigned)b->current); 
    printf("Units consumed   : %u\n", b->units); 
    printf("Energy charge    : Rs %lld.%02lld\n", b->energy_paise / 100, b
>energy_paise % 100); 
    printf("Fixed charge     : Rs %lld.%02lld\n", b->fixed_paise / 100, b->fixed_paise 
% 100); 
    printf("Total            : Rs %lld.%02lld\n", b->total_paise / 100, b->total_paise 
% 100); 
} 
  
int main(void) 
{ 
    printf("---- Data items, types and ranges ----\n"); 
    printf("%-18s %-20s %zu byte(s)  range 0..%u\n", "Previous/Current", "unsigned 
short", sizeof(meter_t), (unsigned)USHRT_MAX); 
    printf("%-18s %-20s %zu byte(s)  range 0..%u\n", "Units consumed", "unsigned int", 
sizeof(unsigned int), UINT_MAX); 
    printf("%-18s %-20s %zu byte(s)  (text, 10 chars + NUL)\n", "Household number", 
"char[11]", sizeof(char[11])); 
    printf("%-18s %-20s %zu byte(s)  values 0..2\n", "Category", "enum", 
sizeof(Category)); 
    printf("%-18s %-20s %zu byte(s)  max %lld\n\n", "Money (paise)", "long long", 
sizeof(long long), LLONG_MAX);

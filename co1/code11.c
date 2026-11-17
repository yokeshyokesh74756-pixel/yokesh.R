#include "final_billing.h" 
// Calculate units with single-rollover handling 
unsigned int calculate_units(unsigned short prev, unsigned short curr) { 
if (curr >= prev) { 
return (unsigned int)(curr - prev); 
} else { 
return (unsigned int)((METER_MAX - prev) + curr + 1); 
} 
} 
// Compute energy charge using exact integer paise arithmetic 
long long compute_energy_charge(unsigned int units) { 
long long paise = 0; 
if (units <= SLAB1_UNITS) { 
paise = (long long)units * RATE1_PAISE; 
} else if (units <= SLAB2_UNITS) { 
paise = (SLAB1_UNITS * RATE1_PAISE) + ((long long)(units - SLAB1_UNITS) * 
RATE2_PAISE); 
} else { 
paise = (SLAB1_UNITS * RATE1_PAISE) +  
((SLAB2_UNITS - SLAB1_UNITS) * RATE2_PAISE) +  
((long long)(units - SLAB2_UNITS) * RATE3_PAISE); 
} 
return paise; 
} 
// Robust input validation using fgets and strtol 
int get_valid_reading(const char *prompt, unsigned short *reading) { 
char buffer[100]; 
char *endptr; 
long val; 
printf("%s", prompt); 
if (!fgets(buffer, sizeof(buffer), stdin)) { 
return 0; 
} 
// Remove trailing newline if present 
buffer[strcspn(buffer, "\n")] = 0; 
val = strtol(buffer, &endptr, 10); 
if (*endptr != '\0' || val < 0 || val > 65535) { 
return 0; // Invalid input or out of 16-bit range 
} 
*reading = (unsigned short)val; 
return 1; 
} 
int main(void) { 
char household_id[20]; 
unsigned short prev_reading = 65400; 
unsigned short curr_reading = 120; 
unsigned int units; 
long long energy_paise, total_paise; 
printf("========================================\n"); 
printf("   TASK 11: FINAL BILLING SYSTEM DESIGN \n"); 
printf("========================================\n"); 
// Simulating validated inputs (using preset boundary test case for display) 
strcpy(household_id, "0000012345"); 
units = calculate_units(prev_reading, curr_reading); 
energy_paise = compute_energy_charge(units); 
total_paise = energy_paise + FIXED_CHARGE_PAISE; 
// Display Final Recommended Output 
printf("Household Number : %s\n", household_id); 
printf("Previous Reading : %u (unsigned short)\n", prev_reading); 
printf("Current Reading  : %u (unsigned short)\n", curr_reading); 
printf("Units Consumed   : %u (unsigned int)\n", units); 
printf("----------------------------------------\n"); 
printf("Energy Charge    : Rs %lld.%02lld (%lld paise)\n", energy_paise / 100, energy_paise % 
100, energy_paise); 
printf("Fixed Charge    
 : Rs %lld.%02lld (%lld paise)\n", FIXED_CHARGE_PAISE / 100, 
FIXED_CHARGE_PAISE % 100, FIXED_CHARGE_PAISE); 
printf("Total Bill      
total_paise); 
 : Rs %lld.%02lld (%lld paise)\n", total_paise / 100, total_paise % 100, 
printf("========================================\n"); 
return 0;

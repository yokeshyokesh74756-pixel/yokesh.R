#include <stdio.h> 
  
typedef unsigned long long energy_t; 
typedef long long money_t; 
  
typedef struct { 
    money_t base_rate_paise_per_kwh; 
    money_t fixed_charge_paise; 
} Tariff; 
  
money_t charge_for_wh(energy_t wh, money_t rate_paise_per_kwh) 
{ 
    /* paise = Wh * paise/kWh / 1000; nearest-paise rounding */ 
    return (money_t)((wh * (energy_t)rate_paise_per_kwh + 500) / 1000); 
} 
  
int main(void) 
{ 
    Tariff tariff; 
    energy_t peak_wh, offpeak_wh; 
    money_t peak_rate, offpeak_charge, peak_charge, total; 
  
    printf("Enter base rate (paise/kWh) and fixed charge (paise): "); 
    if (scanf("%lld %lld", &tariff.base_rate_paise_per_kwh, 
              &tariff.fixed_charge_paise) != 2 || 
        tariff.base_rate_paise_per_kwh < 0 || 
        tariff.fixed_charge_paise < 0) { 
        printf("Invalid tariff\n"); 
        return 1; 
    } 
  
    printf("Enter peak Wh and off-peak Wh: "); 
    if (scanf("%llu %llu", &peak_wh, &offpeak_wh) != 2) { 
        printf("Invalid energy input\n"); 
        return 1; 
    } 
  
    peak_rate = (tariff.base_rate_paise_per_kwh * 120 + 50) / 100; 
    peak_charge = charge_for_wh(peak_wh, peak_rate); 
    offpeak_charge = charge_for_wh(offpeak_wh, tariff.base_rate_paise_per_kwh); 
    total = peak_charge + offpeak_charge + tariff.fixed_charge_paise; 
  
    printf("Peak charge: Rs %lld.%02lld\n", peak_charge / 100, peak_charge % 100); 
    printf("Off-peak charge: Rs %lld.%02lld\n", offpeak_charge / 100, offpeak_charge % 
100); 
    printf("Total: Rs %lld.%02lld\n", total / 100, total % 100); 
    return 0; 
}

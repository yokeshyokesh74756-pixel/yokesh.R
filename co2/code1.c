#include <stdio.h>
 
int main(void)
{
    double price, gross, discount, taxable, tax, total, net;
    int qty, senior;
 
    printf("Enter price, quantity and senior status (1/0): ");
    if (scanf("%lf %d %d", &price, &qty, &senior) != 3 ||
        price < 0 || qty < 0 || (senior != 0 && senior != 1)) {
        printf("Invalid input\n");
        return 1;
    }
 
    gross = price * qty;
    discount = senior ? gross * 15.0 / 100.0 : 0.0;
    taxable = gross - discount;
    tax = taxable * 5.0 / 100.0;
    total = taxable + tax;
    net = total > 1000.0 ? total - 50.0 : total;
 
    printf("Gross = %.2f\n", gross);
    printf("Discount = %.2f\n", discount);
    printf("GST = %.2f\n", tax);
    printf("Total = %.2f\n", total);
    printf("Net = %.2f\n", net);
 
    return 0;
}

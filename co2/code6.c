#include <stdio.h>
 
#define MAX_MONTHS 360
#define EPSILON 0.005
 
int main(void)
{
    double principal, rate, repayment;
    double balance, total_interest = 0.0;
    int month = 0, completed = 0;
 
    printf("Enter principal, monthly interest rate and repayment: ");
    if (scanf("%lf %lf %lf", &principal, &rate, &repayment) != 3 ||
        principal <= 0 || rate < 0 || repayment <= 0) {
        printf("Invalid loan details.\\n");
        return 1;
    }
 
    balance = principal;
    printf("\\nMonth  Interest  Payment  Balance\\n");
 
    while (balance > EPSILON) {
        double interest, due, payment;
 
        if (month >= MAX_MONTHS) {
            printf("Safety limit reached. Loan is not fully repaid.\\n");
            break;
        }
 
        interest = balance * rate / 100.0;
        if (repayment <= interest + EPSILON) {
            printf("Repayment is not greater than monthly interest.\\n");
            break;
        }
 
        due = balance + interest;
        payment = repayment < due ? repayment : due;
        balance = due - payment;
        if (balance < EPSILON) balance = 0.0;
 
        total_interest += interest;
        month++;
 
        printf("%5d  %8.2f  %7.2f  %8.2f\\n",
               month, interest, payment, balance);
 
        if (balance == 0.0) {
            completed = 1;
            break;
        }
    }
 
    if (completed) {
        printf("\\nLoan repaid in %d months.\\n", month);
        printf("Total interest = Rs %.2f\\n", total_interest);
    } else {
        printf("\\nLoan not fully repaid. Months processed = %d\\n", month);
        printf("Interest accumulated = Rs %.2f\\n", total_interest);
    }
    return 0;
}


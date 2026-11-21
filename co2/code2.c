#include <stdio.h>
 
int calls = 0;
 
int slow_check(int card_valid)
{
    calls++;
    return card_valid;
}
 
int main(void)
{
    int result;
 
    calls = 0;
    result = 0 && slow_check(1);
    printf("False && check: result=%d calls=%d\n", result, calls);
 
    calls = 0;
    result = 1 || slow_check(1);
    printf("True || check: result=%d calls=%d\n", result, calls);
 
    /* 1,000 sample passengers:
       200 senior, 600 eligible class, 100 disability-card holders.
       For this demonstration the data are represented by counts. */
    {
        int cheap_false_first_calls = 0;
        int slow_first_calls = 1000;
        int passengers = 1000;
        int eligible_and_senior = 120;
        int disability_checks = 880;
 
        /* Example order: senior && eligible, then disability.
           Assume the senior check is the cheap first condition.
           Server checks are needed only for passengers not already qualified. */
        cheap_false_first_calls = disability_checks;
        printf("Passengers = %d\n", passengers);
        printf("Example cheap-first server calls = %d\n",
               cheap_false_first_calls);
        printf("Slow-first server calls = %d\n", slow_first_calls);
        printf("Qualified by senior and class = %d\n",
               eligible_and_senior);
    }
 
    calls = 0;
    result = 0 & slow_check(1);
    printf("False & check: result=%d calls=%d\n", result, calls);
 
    return 0;
}

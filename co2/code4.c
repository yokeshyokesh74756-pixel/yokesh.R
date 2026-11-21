#include <stdio.h>
 
char grade_ladder(int marks)
{
    if (marks < 0 || marks > 100) return '?';
    if (marks >= 90) return 'S';
    else if (marks >= 80) return 'A';
    else if (marks >= 70) return 'B';
    else if (marks >= 60) return 'C';
    else if (marks >= 50) return 'D';
    else return 'F';
}
 
char grade_switch(int marks)
{
    if (marks < 0 || marks > 100) return '?';
 
    switch (marks / 10) {
        case 10:
        case 9: return 'S';
        case 8: return 'A';
        case 7: return 'B';
        case 6: return 'C';
        case 5: return 'D';
        default: return 'F';
    }
}
 
int main(void)
{
    int tests[] = {100, 90, 89, 80, 79, 70, 69,
                   60, 59, 50, 49, 0, -1, 101};
    int n = sizeof tests / sizeof tests[0];
 
    printf("Marks Ladder Switch\n");
    for (int i = 0; i < n; i++)
        printf("%5d %6c %6c\n", tests[i],
               grade_ladder(tests[i]), grade_switch(tests[i]));
    return 0;
}

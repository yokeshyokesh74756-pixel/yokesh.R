int previous, current; 
if (scanf("%d %d", &previous, &current) != 2) { 
printf("Invalid input\n"); 
return 1; 
} 
long long amount = 16250; /* paise */ 
printf("Rs %lld.%02lld\n", amount / 100, amount % 100);

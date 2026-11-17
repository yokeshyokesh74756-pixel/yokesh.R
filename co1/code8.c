gcc -E billing.c -o billing.i 
gcc -S billing.i -o billing.s 
gcc -c billing.c -o billing.o 
gcc billing.o -o billing 
gcc -Wall -Wextra billing.c -o billing 

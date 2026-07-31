#include <stdio.h>
#include <math.h>

int main() {
    printf("Evaluating Order of Growth for increasing 'n'...\n\n");
    printf("%-5s | %-12s | %-12s | %-12s | %-12s | %-12s\n", 
           "n", "log2(n)", "12*sqrt(n)", "50*n^0.5", "n^0.51", "n*log2(n)");
    printf("-----------------------------------------------------------------------\n");

    
    for (double n = 10; n <= 50; n += 10) {
        double f_log2n = log2(n);
        double f_12sqrt = 12.0 * sqrt(n);
        double f_50sqrt = 50.0 * pow(n, 0.5);
        double f_n051 = pow(n, 0.51);
        double f_nlog2n = n * log2(n);
        
        printf("%-5.0f | %-12.2f | %-12.2f | %-12.2f | %-12.2f | %-12.2f\n", 
               n, f_log2n, f_12sqrt, f_50sqrt, f_n051, f_nlog2n);
    }

    printf("\n");
    printf("%-5s | %-15s | %-15s | %-15s | %-15s | %-15s\n", 
           "n", "100n^2 + 6n", "n^2 - 324", "2n^3", "n^log2(n)", "3^n");
    printf("----------------------------------------------------------------------------------------\n");

    for (double n = 10; n <= 50; n += 10) {
        double f_100n2 = 100.0 * n * n + 6.0 * n;
        double f_n2_324 = (n * n) - 324.0;
        double f_2n3 = 2.0 * n * n * n;
        double f_nlogn = pow(n, log2(n));
        double f_3n = pow(3.0, n);
        
       
        printf("%-5.0f | %-15.0f | %-15.0f | %-15.0f | %-15.2e | %-15.2e\n", 
               n, f_100n2, f_n2_324, f_2n3, f_nlogn, f_3n);
    }
    printf("\nNote: 2^32 * n scales linearly but starts huge.\n");
    for (double n = 10; n <= 30; n += 10) {
        printf("For n=%.0f, 2^32 * n = %.0f\n", n, 4294967296.0 * n);
    }

    return 0;
}

#include <stdio.h>
#include <math.h>
void towerOfHanoi(int n, char source, char destination, char auxiliary, long long *move_count) {
    if (n == 1) {
        printf("Step %lld: Move disk 1 from %c to %c\n", ++(*move_count), source, destination);
        return;
    }
    

    towerOfHanoi(n - 1, source, auxiliary, destination, move_count);
    
    
    printf("Step %lld: Move disk %d from %c to %c\n", ++(*move_count), n, source, destination);
    

    towerOfHanoi(n - 1, auxiliary, destination, source, move_count);
}

int main() {
    int test_disks = 3;
    long long actual_moves = 0;
    
    printf("====================================================\n");
    printf(" 1. ALGORITHM EXECUTION (Step-by-Step for n = %d)\n", test_disks);
    printf("====================================================\n");
    
    towerOfHanoi(test_disks, 'A', 'C', 'B', &actual_moves);
    printf("\nTotal moves taken to solve %d disks: %lld\n\n", test_disks, actual_moves);
    
    
    printf("====================================================\n");
    printf(" 2. EXPONENTIAL GROWTH ANALYSIS ( O(2^n) )\n");
    printf("====================================================\n");
    printf("%-10s | %-20s\n", "Disks (n)", "Total Moves (2^n - 1)");
    printf("-----------------------------------\n");
    

    for (int i = 3; i <= 20; i++) {
        long long total_moves = (1LL << i) - 1; 
        printf("%-10d | %-20lld\n", i, total_moves);
    }
    
    return 0;
}

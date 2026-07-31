#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int trials = 10000;
    

    int fair_heads = 0;
    int fair_tails = 0;
    
    int biased_heads = 0;
    int biased_tails = 0;
    int bias_threshold = 75; 

    printf("Simulating %d coin tosses...\n\n", trials);

    for (int i = 0; i < trials; i++) {

        if (rand() % 2 == 0) {
            fair_heads++;
        } else {
            fair_tails++;
        }
        

        if ((rand() % 100) < bias_threshold) {
            biased_heads++;
        } else {
            biased_tails++;
        }
    }

    printf("--- FAIR COIN RESULTS (Expected 50%%) ---\n");
    printf("Heads: %d\n", fair_heads);
    printf("Tails: %d\n", fair_tails);
    printf("Probability of Heads: %.2f%%\n\n", ((float)fair_heads / trials) * 100);

    printf("--- BIASED COIN RESULTS (Expected %d%%) ---\n", bias_threshold);
    printf("Heads: %d\n", biased_heads);
    printf("Tails: %d\n", biased_tails);
    printf("Probability of Heads: %.2f%%\n", ((float)biased_heads / trials) * 100);

    return 0;
}

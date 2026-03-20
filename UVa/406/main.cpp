#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
int prime_count[MAXN];
vector<int> primes;

void preprocess() {
    for (int i = 1; i < MAXN; i++) {
        prime_count[i] = 1;
    }

    prime_count[0] = 0;
    primes.push_back(1);

    for (int i = 2; i < MAXN; i++) {
        if (prime_count[i] == 1) {
            primes.push_back(i);

            for (int j = i + i; j < MAXN; j += i) {
                prime_count[j] = 0;
            }
        }

        prime_count[i] += prime_count[i - 1];
    }
}

int main() {
    int n, c;
    preprocess();

    while (scanf("%d %d", &n, &c) == 2) {
        int num_of_primes = prime_count[n];
        int primes_to_print = (num_of_primes % 2) == 0 ? 2 * c : 2 * c - 1;

        printf("%d %d:", n, c);

        if (primes_to_print >= num_of_primes) {
            for (int i = 0; i < num_of_primes; i++) {
                printf(" %d", primes[i]);
            }
        } else {
            int i = (num_of_primes - primes_to_print) / 2;
            int j = num_of_primes - i;

            for (int k = i; k < j; k++) {
                printf(" %d", primes[k]);
            }
        }

        printf("\n\n");
    }

    return 0;
}

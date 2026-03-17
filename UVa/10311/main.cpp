#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e8 + 1;
bool p[MAX];
vector<int> primes;

void preprocess() {
    memset(p, true, sizeof(p));

    p[0] = p[1] = false;

    for (int i = 3; i * i <= MAX; i += 2) {
        if (p[i]) {
            for (int j = i * i; j < MAX; j += 2 * i) {
                p[j] = false;
            }
        }
    }

    primes.push_back(2);

    for (int i = 3; i < MAX; i += 2) {
        if (p[i]) {
            primes.push_back(i);
        }
    }
}

int main() {
    preprocess();
    int n;

    while (scanf("%d", &n) != EOF) {
        if (n & 1) {
            if (p[n - 2] && (2 != (n - 2))) {
                printf("%d is the sum of %d and %d.\n", n, 2, n - 2);
            } else {
                printf("%d is not the sum of two primes!\n", n);
            }
        } else {
            int i = upper_bound(primes.begin(), primes.end(), n / 2) - primes.begin();
            i--;
            bool ok = false;

            for (int j = i; j >= 0; j--) {
                int a = primes[j];
                int b = n - primes[j];

                if (a != b && (b & 1) && p[b]) {
                    ok = true;
                    printf("%d is the sum of %d and %d.\n", n, primes[j], n - primes[j]);
                    break;
                }
            }

            if (!ok) {
                printf("%d is not the sum of two primes!\n", n);
            }
        }
    }

    return 0;
}
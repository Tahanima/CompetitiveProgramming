#include <bits/stdc++.h>
using namespace std;

const int MAX = 1300000;
bool p[MAX];
vector<int> primes;

void preprocess() {
    memset(p, true, sizeof(p));

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
        if (n == 0) {
            break;
        }

        int i = lower_bound(primes.begin(), primes.end(), n) - primes.begin();

        if (n == primes[i]) {
            printf("0\n");
        } else {
            printf("%d\n", primes[i] - primes[i - 1]);
        }
    }

    return 0;
}
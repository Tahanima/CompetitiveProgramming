#include <bits/stdc++.h>
using namespace std;

const int MAX = 32005;
bool p[MAX];
vector<int> primes;
vector<int> diff_count;

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

    int n = primes.size();
    diff_count = vector<int>(primes.size(), 0);

    for (int i = 0; i < n - 1; ) {
        int dc = 1;
        int diff = primes[i + 1] - primes[i];
        for (int j = i + 2; j < n && (primes[j] - primes[j - 1]) == diff; dc++, j++);

        if (dc >= 2) {
            diff_count[i] = dc;
        }

        i += dc;
    }
}

int main() {
    preprocess();
    int x, y;

    while (scanf("%d %d", &x, &y) == 2) {
        if (x == 0 && y == 0) {
            break;
        }

        if (x > y) {
            swap(x, y);
        }

        int i = lower_bound(primes.begin(), primes.end(), x) - primes.begin();
        int j = upper_bound(primes.begin(), primes.end(), y) - primes.begin();

        for (int k = i; k < j; ) {
            if (diff_count[k] >= 2) {
                if (k + diff_count[k] < j) {
                    for (int l = k; l <= k + diff_count[k]; l++) {
                        if (l > k) {
                            printf(" ");
                        }

                        printf("%d", primes[l]);
                    }

                    printf("\n");
                }

                k += diff_count[k];
            } else {
                k++;
            }
        }
    }

    return 0;
}
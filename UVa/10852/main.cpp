#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10001;
bool prime[MAXN];
int answer[MAXN];
vector<int> primes;

void preprocess() {
    memset(prime, true, sizeof(prime));
    memset(answer, -1, sizeof(answer));
    primes.push_back(2);

    for (int i = 3; i * i < MAXN; i += 2) {
        if (prime[i] == true) {
            for (int j = i * i; j < MAXN; j += i + i) {
                prime[j] = false;
            }
        }
    }

    for (int i = 3; i < MAXN; i += 2) {
        if (prime[i] == true) {
            primes.push_back(i);
        }
    }

    const int prime_len = primes.size();

    for (int n = 2; n < MAXN; n++) {
        for (int i = 0; i < prime_len; i++) {
            int p = primes[i];

            if (p > n) {
                break;
            }

            int val = n - (p * (n / p));

            if (answer[n] == -1) {
                answer[n] = p;
            } else {
                if (val > (n - (answer[n] * (n / answer[n])))) {
                    answer[n] = p;
                }
            }
        }
    }
}

int main() {
    int t, n;

    preprocess();
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);
        printf("%d\n", answer[n]);
    }
    return 0;
}

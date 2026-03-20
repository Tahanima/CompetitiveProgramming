#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e7;
bool p[MAX];
int power_of_10[9];
vector<int> primes;
vector<int> a_primes;

void preprocess() {
    memset(p, true, sizeof(p));
    p[0] = p[1] = false;
    primes.push_back(2);
    power_of_10[0] = 1;

    for (int i = 1; i < 9; i++) {
        power_of_10[i] = power_of_10[i - 1] * 10;
    }

    for (int i = 3; i * i <= MAX; i += 2) {
        if (p[i]) {
            for (int j = i * i; j < MAX; j += 2 * i) {
                p[j] = false;
            }
        }
    }

    for (int i = 3; i < MAX; i += 2) {
        if (p[i]) {
            primes.push_back(i);
        }
    }

    int sz = primes.size();

    for (int i = 0; i < sz; i++) {
        string s = to_string(primes[i]);
        sort(s.begin(), s.end());
        bool is_prime = true;

        do {
            int n = stoi(s);

            if (n % 2 == 0 || !p[n]) {
                is_prime = false;
                break;
            }
        } while (next_permutation(s.begin(), s.end()));

        if (is_prime || primes[i] == 2) {
            a_primes.push_back(primes[i]);
        }
    }
}

int main() {
    preprocess();
    int n;

    while (scanf("%d", &n) != EOF && n != 0) {
        int l = upper_bound(a_primes.begin(), a_primes.end(), n) - a_primes.begin();
        int next = upper_bound(power_of_10, power_of_10 + 9, n) - power_of_10;

        if (a_primes.size() == l) {
            printf("0\n");
        } else if (a_primes[l] < power_of_10[next]) {
            printf("%d\n", a_primes[l]);
        } else {
            printf("0\n");
        }
    }
    return 0;
}

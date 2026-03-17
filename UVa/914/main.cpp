#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6  + 1;
bool p[MAX];
vector<int> primes;

void preprocess() {
    memset(p, true, sizeof(p));
    primes.push_back(2);

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
}

void solve(int l, int u) {
    int i = (lower_bound(primes.begin(), primes.end(), l) - primes.begin()) + 1;
    map<int, int> m;

    for (; i < primes.size(); i++) {
        if (primes[i] > u) {
            break;
        }

        m[primes[i] - primes[i - 1]]++;
    }

    if (m.size() == 0) {
        printf("No jumping champion\n");
        return;
    }

    int max_diff = 0;
    int max_diff_count = 0;
    bool first = false;

    for (auto it = m.begin(); it != m.end(); it++) {
        if (max_diff_count < it->second) {
            max_diff = it->first;
            max_diff_count = it->second;
        }
    }

    for (auto it = m.begin(); it != m.end(); it++) {
        if (max_diff_count == it->second) {
            if (first) {
                printf("No jumping champion\n");
                return;
            } else {
                first = true;
            }
        }
    }

    printf("The jumping champion is %d\n", max_diff);
}

int main() {
    preprocess();

    int t, l, u;
    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &l, &u);
        solve(l, u);
    }

    return 0;
}
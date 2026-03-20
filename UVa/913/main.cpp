#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;

    while (scanf("%lld", &n) != EOF) {
        n = ((n - 1) / 2) - 1;
        printf("%lld\n", 15 + 6 * (n * n + 4 * n));
    }

    return 0;
}

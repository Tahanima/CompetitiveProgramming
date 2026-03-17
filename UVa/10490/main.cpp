#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n) {
    if (n < 2 || (n % 2) == 0) {
        return false;
    }

    if (n == 2) {
        return true;
    }

    for (int i = 3;  i * i <= n; i+= 2) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

bool is_perfect(int n) {
    static const unordered_set<int> valid = {
        2, 3, 5, 7, 13, 17, 19, 31
    };

    return valid.count(n);
}

int main() {
    int n;

    while (scanf("%d", &n) != EOF) {
        if (n == 0) {
            break;
        }

        if (is_perfect(n)) {
            printf("Perfect: %lld!\n", (2ll << (n - 2)) * ((2ll << (n - 1)) - 1ll));
        } else if (is_prime(n)) {
            printf("Given number is prime. But, NO perfect number is available.\n");
        } else {
            printf("Given number is NOT prime! NO perfect number is available.\n");
        }
    }

    return 0;
}
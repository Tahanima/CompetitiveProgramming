#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    long long a, b;
    scanf("%d", &t);

    while(t--) {
        scanf("%lld %lld", &a, &b);
        printf("%s\n", a > b ? ">" : (a == b ? "=" : "<"));
    }

    return 0;
}
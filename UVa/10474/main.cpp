#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, q, tc = 0;

    while (scanf("%d %d", &n, &q) == 2 && (n + q)) {
        int nums[n];
        for (int i = 0; i < n; scanf("%d", &nums[i]), i++);
        sort(nums, nums + n);

        tc++;
        printf("CASE# %d:\n", tc);

        for (int i = 0; i < q; i++) {
            scanf("%d", &m);

            int j = lower_bound(nums, nums + n, m) - nums;

            if (j >= 0 && j < n && nums[j] == m) {
                printf("%d found at %d\n", m, j + 1);
            } else {
                printf("%d not found\n", m);
            }
        }
    }
    return 0;
}

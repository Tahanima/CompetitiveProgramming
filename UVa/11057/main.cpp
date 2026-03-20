#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;

    while (scanf("%d", &n) == 1) {
        int nums[n];

        for (int i = 0; i < n; scanf("%d", &nums[i]), i++);
        sort(nums, nums + n);

        scanf("%d", &m);
        int x, y, diff = -1;

        for (int i = 0; i < n; i++) {
            bool found = binary_search(nums + i + 1, nums + n, m - nums[i]);

            if (found) {
                if (diff == -1) {
                    x = nums[i];
                    y = m - x;
                    diff = y - x;
                } else {
                    if (m - 2 * nums[i] < diff) {
                        x = nums[i];
                        y = m - x;
                        diff = y - x;
                    }
                }
            }
        }

        printf("Peter should buy books whose prices are %d and %d.\n\n", x, y);
    }

    return 0;
}

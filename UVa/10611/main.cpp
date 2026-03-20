#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, q, x, y;

    scanf("%d", &n);
    int nums[n];

    for (int i = 0; i < n; scanf("%d", &nums[i]), i++);

    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &m);

        x = (lower_bound(nums, nums + n, m) - nums) - 1;
        y = upper_bound(nums, nums + n, m) - nums;

        printf("%s %s\n", ((x < 0) || (x >= n)) ? "X" : to_string(nums[x]).c_str(),
               ((y < 0) || (y >= n)) ? "X" : to_string(nums[y]).c_str());
    }
    return 0;
}

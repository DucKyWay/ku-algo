#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int max(int a, int b) {
    if (a > b) return a;
    return b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;

    vector<long long> p(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];

    long long NEG = LLONG_MIN / 4; // - infinity

    long long dp0 = 0; // max past not warp
    long long dp1 = NEG; // max past warp
    long long prev = 0; // p[i-1]

    for (int i = 1; i <= n; i++) {
        long long new0, new1;

        if (i == 1) {
            new0 = dp0 + p[i];
        } else {
            long long candA = dp0 + p[i];
            long long candB = dp1 + prev * p[i];
            new0 = max(candA, candB);
        }

        // i ได้ 0
        new1 = max(dp0, dp1);

        dp0 = new0;
        dp1 = new1;
        prev = p[i];
    }

    cout << max(dp0, dp1);
    return 0;
}

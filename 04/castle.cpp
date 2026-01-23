#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b) {
    if (a > b) return a;
    return b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];

    int NEG = -1000000000;

    int dp0 = 0; // max past not warp
    int dp1 = NEG; // max past warp
    int prev = 0; // p[i-1]

    for (int i = 1; i <= n; i++) {
        int new0, new1;

        if (i == 1) {
            new0 = dp0 + p[i];
        } else {
            int candA = dp0 + p[i];
            int candB = dp1 + prev * p[i];
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

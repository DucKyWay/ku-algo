#include <iostream>
#include <vector>
using namespace std;

int min(int a, int b) {
    if(a < b) return a;
    return b;
}

int max(int a, int b) {
    if (a > b) return a;
    return b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<int>> memories;
    int p, x, z; // ความทรงจำ, ตำแหน่งในสมอง? หรอ
    while(cin >> p >> x >> z) memories.push_back({p, x, z});

    int n = memories.size();
    int m = 3;
    vector<vector<int>> dp(n, vector<int>(m));

    // base
    dp[n-1][m-1] = max(1, 1-memories[n-1][m-1]);
    // last col
    for(int i = n-2; i >= 0; i--) {
        dp[i][m-1] = max(1, dp[i+1][m-1] - memories[i][m-1]);
    }
    // last row
    for(int j = m-2; j >= 0; j--) {
        dp[n-1][j] = max(1, dp[n-1][j+1] - memories[n-1][j]);
    }

    for(int i = n-2; i >= 0; i--) {
        for(int j = m-2; j >= 0; j--) {
            int need = min(dp[i+1][j], dp[i][j+1]);
            dp[i][j] = max(1, need - memories[i][j]);
        }
    }

    cout<<dp[0][0]<<endl;
    return 0;
}
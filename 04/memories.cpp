#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<int>> memories;
    int p, x, z; // ความทางจำ, ตำแหน่งในสมอง?
    while(cin >> p >> x >> z) memories.push_back({p, x, z});

    return 0;
}
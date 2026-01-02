#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

    vector<string> s;
    vector<int> k;
    int n = 0;

    string ss;
    int kk;
    while(getline(cin, ss)) {
        n++;
        if (ss.empty()) continue;
        kk = stoi(ss.substr(ss.rfind(' ') + 1));
        k.push_back(kk);
        ss = ss.substr(0, ss.rfind(' '));
        s.push_back(ss);
    }

    // support units
    vector<int> support(n, 1);

    // Left to right
    for (int i = 1; i < n; i++) {
        if (k[i] > k[i - 1]) {
            support[i] = support[i - 1] + 1;
        }
    }

    // Right to left
    for (int i = n - 2; i >= 0; i--) {
        if (k[i] > k[i + 1]) {
            support[i] = max(support[i], support[i + 1] + 1);
        }
    }

    // total, max
    int total = 0;
    int x = 0;
    for (int i = 0; i < n; i++) {
        total += support[i];
        if (support[i] > x) {
            x = support[i];
        }
    }

    if (n > 1) {
        cout << "Minimum of " << total << " support units required." << endl;
    } else {
        cout << "Minimum of " << total << " support unit required." << endl;
    }

    bool first = true;
    for (int i = 0; i < n; i++) {
        if (support[i] == x) {
            if (!first) cout << " and ";
            cout << s[i];
            first = false;
        }
    }
    cout << " - " << x << endl;

    return 0;
}

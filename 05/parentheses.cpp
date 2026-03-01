#include <iostream>
#include <string>
#include <set>

using namespace std;

set<string> results;

void backtrack(string s, int i, int l_rem, int r_rem, int balance, string path) {

    if (balance < 0) return;

    if (i == s.size()) {
        if (l_rem == 0 && r_rem == 0 && balance == 0) {
            results.insert(path);
        }
        return;
    }

    char c = s[i];
    if (c == '(') {
        if (l_rem > 0) {
            backtrack(s, i + 1, l_rem - 1, r_rem, balance, path);
        }
        backtrack(s, i + 1, l_rem, r_rem, balance + 1, path + c);
    } else if (c == ')') {
        if (r_rem > 0) {
            backtrack(s, i + 1, l_rem, r_rem - 1, balance, path);
        }
        if (balance > 0) {
            backtrack(s, i + 1, l_rem, r_rem, balance - 1, path + c);
        }
    } else {
        backtrack(s, i + 1, l_rem, r_rem, balance, path + c);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >> s;

    int l_rem = 0, right_rem = 0;

    for (char c : s) {
        if (c == '(') {
            l_rem++;
        } else if (c == ')') {
            if (l_rem > 0)
                l_rem--;
            else
                right_rem++;
        }
    }

    backtrack(s, 0, l_rem, right_rem, 0, "");

    for (auto &ans : results)
        cout << ans << endl;

    return 0;
}

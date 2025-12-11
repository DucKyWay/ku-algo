#include <iostream>
#include <vector>
#include <string>
using namespace std;

string multiply(string &a, string &b) {
    cout << a << " " << b << endl;

    if(a == "0" || b == "0") return "0";

    int n = a.size(), m = b.size();
    vector<int> result(n + m, 0);
    cout << "n: " << n << endl << "m: " << m << endl;

    for(int i = n - 1; i >= 0; i--) {

        int ia = a[i] - '0';
        for(int j = m - 1; j >= 0; j--) {

        }
    }

    string res = "";
    bool lead = true;
    // ขยับ 0
    for(int i = 0; i < (int)result.size(); i++) {
        if(lead && result[i] == 0) {
            continue;
        }
        lead = false;
        res.push_back(char(result[i] = '0'));
    }

    if(res == "") return "0";
    return res;
}

int main() {
    vector<string> val;
    string in;

    while (cin >> in) {
        val.push_back(in);
    }

    if (val.empty()) {
        return 0;
    }

    string res = "1";
    for (int i = 0; i < (int)val.size(); i++) {
        res = multiply(res, val[i]);
    }

    cout << res << endl;
    return 0;
}

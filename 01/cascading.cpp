#include <iostream>
#include <vector>
#include <string>
using namespace std;

string multiply(const string &a, const string &b) {
    if (a == "0" || b == "0") return "0";

    int n = a.size(), m = b.size();
    vector<int> result(n + m, 0);

    for (int i = n - 1; i >= 0; --i) {
        int da = a[i] - '0';
        for (int j = m - 1; j >= 0; --j) {
            int db = b[j] - '0';

            int posLow = i + j + 1;
            int posHigh = i + j;

            int sum = result[posLow] + da * db; // + ทด
            result[posLow] = sum % 10; // หน่วย
            result[posHigh] += sum / 10; // ทดไป
        }
    }

    // ขยับ 0
    string res;
    int k = 0;
    while (k < (int)result.size() && result[k] == 0) {
        k++;
    }
    for (; k < (int)result.size(); ++k) {
        res.push_back(char('0' + result[k]));
    }

    if (res.empty()) {
        return "0";
    } else {
        return res;
    }
}

int main() {
    vector<string> val;
    string in;

    while (cin >> in) {
        val.push_back(in);
    }
    if (val.empty()) return 0;

    string res = "1";
    for (int i = 0; i < (int)val.size(); i++) {
        res = multiply(res, val[i]);
    }

    cout << res << "\n";
    return 0;
}

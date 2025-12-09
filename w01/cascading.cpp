#include <iostream>
#include <string>
#include <vector>
using namespace std;

void multiply(string &a, string &b) {
    cout << a << " * " << b << endl;
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
        multiply(res, val[i]);
    }

    cout << res << endl;
    return 0;
}

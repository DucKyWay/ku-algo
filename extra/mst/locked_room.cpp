#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {

    vector<vector<int>> password;
    string line;
    while(getline(cin, line)) {
        stringstream ss(line);
        vector<int> row;
        int x;
        while(ss >> x) 
            row.push_back(x);
        password.push_back(row);
    }

    for(int i = 0; i < password.size(); i++) {
        for(int j = 0; j < password[i].size(); j++) {
            cout<<password[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
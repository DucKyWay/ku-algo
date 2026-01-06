#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int v, e;
    vector<vector<int, int>> path;
    vector<int> res = {0, 0, 0, 0, 0};
    cin >> v >> e;
    for(int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        path.push_back({a, b});
    }

    

    return 0; 
}
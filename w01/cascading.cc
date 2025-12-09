#include <iostream>
#include <string>
#include <vector>
using namespace std;

void multiply(string res, vector<string> val) {

}

int main() {

    vector<string> val;
    
    string in, res = 0;
    while(cin>>in && in != EOF) {
      val.add(in);
    }

    multiply(res, val);

    return 0;
}

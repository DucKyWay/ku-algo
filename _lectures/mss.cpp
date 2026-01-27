#include <bits/stdc++.h>
using namespace std;

int main() {
    
    vector<int> lists;
    int x;
    while(cin>>x) lists.push_back(x);
    if (lists.empty()) return 0;
    
    vector<int> B(lists.size());
    B[0] = lists[0];
    
    int maxSum = B[0];
    int start = 0, end = 0, temp = 0;
    
    for(int i = 0; i < lists.size() - 1; i++) {
        if(B[i] > 0) {
            B[i+1] = B[i] + lists[i+1];
        } else {
            B[i+1] = lists[i+1];
            temp = i + 1;
        }
        
        if(B[i+1] > maxSum) {
            maxSum = B[i+1];
            start = temp;
            end = i + 1;
        }
    }
    
    cout<<"mss: "<<maxSum<<endl;
    cout<<"subsequence: ";
    for(int i = start; i <= end; i++) {
        cout<<lists[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}

/*
input: 
1 -5 2 -1 3

output: 
mss: 4
subsequence: 2 -1 3
=============================
input: 
-2 1 -3 4 -1 2 1 -5 4

output: 
mss: 6
subsequence: 4 -1 2 
=============================
input:
-2 -3 4 -1 -2 1 5 -3

output: 
mss: 7
subsequence: 4 -1 -2 1 5 
*/
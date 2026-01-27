#include<bits/stdc++.h>
using namespace std;
bool sub_set_sum(vector<int> vec, int b){
    vector<vector<bool>> temp(vec.size());
    for(int i = 0 ;  i< vec.size();i++){
        for(int j = 0 ; j<=b;j++){
            if(j == 0  || vec[i] == j){
                temp[i].push_back(true);
            }else{
                temp[i].push_back(false);
            }
        }
    }    
    for(int i  = 1 ;i<vec.size();i++){
        for(int j = 0 ; j<=b;j++){
            if(temp[i][j]== true)continue;
            if(temp[i-1][j] == true || (j-vec[i]>0 && temp[i-1][j-vec[i]] == true)){
                temp[i][j]=true;
            }
            else{
                temp[i][j]=false;
            }
        }
    }
    for(auto  i :temp){
        for(auto j :i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

}


int main(){
    int n,c,b;
    cin>>n>>b;
    vector<int> vec;
    for(int i = 0 ; i<n;i++){
        cin>>c;
        vec.push_back(c);
    }
    sub_set_sum(vec,b);
}
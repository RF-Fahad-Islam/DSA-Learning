#include<bits/stdc++.h>
using namespace std;
int main(){
    list<int> l;
    int v;
    while(cin >> v && v != -1){
        l.push_back(v);
    }
    l.sort();
    l.unique();
    return 0;
}
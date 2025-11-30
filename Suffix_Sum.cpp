#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> b(n);
    b[n-1] = a[n-1];
    for (int i = n-2; i >=0; i--)
    {
        b[i] = b[i+1] + a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
    
    
    return 0;
}
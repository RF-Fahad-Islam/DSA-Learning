#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin >> n >> q;
    vector<long long int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<long long int> pre(n);
    pre[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i-1]+a[i];
    }
    
    for (int i = 0; i < q; i++)
    {
        int l,r;
        cin >> l>>r;
        long long int sum;
        l--,r--;
        if(l==0) sum = pre[r];
        else sum = pre[r] - pre[l-1];
        cout << sum << endl;
        
    }
    
    
    return 0;
}
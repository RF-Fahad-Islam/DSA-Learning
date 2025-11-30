#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int l=0,r=n-1;
    int mid = (l+r)/2;
    while(l<=r){
        if(q<mid){
            r = mid-1;
        } else if(q>mid) {
            l = mid+1;
        } else break;
        mid = l+r/2;
    }
    cout <<mid;
    
    return 0;
}
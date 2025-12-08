#include<bits/stdc++.h>
using namespace std;

int main()
{
    list<int> l;
    int q;
    cin>>q;
    while(q--){
        int x,v;
        cin >> x>> v;
        if(x==0) l.push_front(v);
        else if(x==1) l.push_back(v);
        else if(x==2){
            if(v<l.size()) l.erase(next(l.begin(),v));
        }
        cout << "L -> ";
        for(int v:l){
            cout<< v << " ";
        }
        cout << endl;
        cout << "R -> ";
        if(!l.empty()){
            list<int> l2(l);
            l2.reverse();
            for(int v:l2){
                cout<< v << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

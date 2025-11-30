#include <bits/stdc++.h>
using namespace std;
class Student
{
public:
    string name;
    int roll;
    int marks;
};

bool cmp(Student i, Student j)
{
    return (i.marks == j.marks) ? i.roll < j.roll : i.marks > j.marks;
}

int main()
{
    int n;
    cin >> n;
    Student a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].name >> a[i].roll >> a[i].marks;
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++)
    {
        cout << a[i].name << " " << a[i].roll << " " << a[i].marks << endl;
    }
    
    return 0;
}
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> a = {3, 1, 5, 6, 7, 2, 4};

    auto itr1 = a.begin();  // aの先頭を表すイテレータ
    itr1 = itr1 + 2;        // a[2]を表すイテレータ
    auto itr2 = itr1 + 4;   // 末尾の要素(a[6])を表すイテレータ

    //cout << *itr1 << endl;
    //cout << *itr2 << endl;

    for(auto itr=a.begin(); itr != a.end(); itr++){
        cout << *itr << endl;
    }
}
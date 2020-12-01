#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    queue<int> q;
    q.push(10);
    q.push(8);
    q.push(2);
    q.push(5);

    // 空でない間繰り返す
    while(!q.empty()){
        cout << q.front() << endl;
        cout << q.size() << endl;
        q.pop();    // 先頭を削除する
    }
    if(q.empty()){
        cout << "q become empty" << endl;
    }
}
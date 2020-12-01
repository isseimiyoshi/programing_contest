#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int> pq;
    pq.push(8);
    pq.push(10);
    pq.push(3);
    pq.push(5);
    while(!pq.empty()){
        cout << pq.top() << endl;
        cout << "size: " << pq.size() << endl;
        pq.pop();
    }
    cout << "------------------" << endl;

    // 小さい順に取り出される優先度付きキュー
    priority_queue<int, vector<int>, greater<int>> pq2;
    pq2.push(10);
    pq2.push(3);
    pq2.push(6);
    pq2.push(1);
    while(!pq2.empty()){
        cout << pq2.top() << endl;
        pq2.pop();
    }

    return 0;
}
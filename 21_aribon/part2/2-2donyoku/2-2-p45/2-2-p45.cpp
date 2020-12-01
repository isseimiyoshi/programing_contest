#include<iostream>
#include <bits/stdc++.h>
using namespace std;

/*
input

6
ACDBCB
*/

int main()
{
    int n;
    string S;
    cin >> n >> S;
    vector<char> T(n);
    deque<char> deq_S;
    for(int i=0; i<n; i++){
        char moji = S[i];
        deq_S.push_back(moji);
    }
    for(int i=0; i<n; i++){
        if(deq_S.front() < deq_S.back()){
            T[i] = deq_S.front();
            deq_S.pop_front();
        }else if(deq_S.front() < deq_S.back()){
            T[i] = deq_S.back();
            deq_S.pop_back();
        }else{
            auto deq_copy = deq_S;
            deq_copy.pop_front(); deq_copy.pop_back();
            if(deq_copy.front() < deq_copy.back()){
                T[i] = deq_S.front();
                deq_S.pop_front();
            }
        }
    }
    for(int i=0; i<n; i++) cout << T[i];
    cout << endl;
}
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector <tuple<int, int>> bi_ai;
    int ai, bi;
    for(int i=0; i<N; i++){
        cin >> ai >> bi;
        bi_ai.push_back(make_tuple(bi, ai));
    }
    sort(bi_ai.begin(), bi_ai.end());
    for(int i=0; i<N; i++){
        tie(bi, ai) = bi_ai[i];
        cout << ai << " " << bi << endl;
    }
    return 0;
}
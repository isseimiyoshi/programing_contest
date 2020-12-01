#include<iostream>
#include <bits/stdc++.h>
using namespace std;

/*
10
3
2
6
7
*/

int main()
{
    int L, n;
    cin >> L >> n;
    vector<int> ants(n);
    for(int i=0; i<n; i++){
        cin >> ants[i];
    }
    int maxT = 0;
    int minT = 0;
    for(int i=0; i<n; i++){
        int ant = ants[i];
        int i_maxT = max(ant, abs(L - ant));
        int i_minT = min(ant, abs(L - ant));
        if(maxT < i_maxT) maxT = i_maxT;
        if(minT < i_minT) minT = i_minT;
    }
    cout << maxT << endl;
    cout << minT << endl;
}
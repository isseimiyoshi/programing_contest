#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, K;
    cin >> N >> K;
    vector <int> A(N);
    for(int i=0; i<N; i++){
        cin >> A[i];
    }

    bool ans = false;

    // 全ての選び方を試して、総和がKになるものがあるかどうか調べる
    for(int tmp=0; tmp<(1 << 20); tmp++){
        bitset<20> s(tmp);  // 最大20個なので20ビットのビット列として扱う

        // ビット列の1ビットに対応する整数を選んだとみなして総和を求める
        int sum = 0;
        for(int i=0; i<N; i++){
            if(s.test(i)){
                sum += A.at(i);
            }
        }
        if(sum == K){
            ans = true;
        }
    }

    if(ans) cout << "YES" << endl;
    else cout << "NO" << endl;
    bitset<6> s(15);
    cout << s << endl;
    cout << s.to_ullong() << endl;
    uint32_t x = 0b10010101;
    cout << x << endl;
    cout << (x | 0b10000010) << endl;
}
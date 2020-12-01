#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // カードの枚数
    int N;
    cin >> N;
    // 各カードの番号を格納する配列変数
    vector <int> cards(N);
    for(int i=0; i<N; i++){
        cin >> cards[i];
    }
    int sumA=0;
    int sumB=0;
    // cardsをソートする
    sort(cards.begin(), cards.end());
    // 逆順ソートにする
    reverse(cards.begin(), cards.end());
    for(int i=0; i<N; i++){
        if(i % 2 == 0){
            sumA += cards[i];
        }else{
            sumB += cards[i];
        }
    }
    cout << sumA - sumB << endl;
}
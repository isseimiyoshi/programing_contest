#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/* 大文字を小文字に変換 */
char tolower(char c) {return (c + 0x20);}
/* 小文字を大文字に変換 */
char toupr(char c) {return (c - 0x20);}

// if('A'<=s[i] && s[i]<='Z') s[i] += 'a'-'A';

/*
string s = "abcdefg"
s.substr(4) "efg"
s.substr(0,3) "abc"
s.substr(2,4) "cdef"
*/

void bubbleSort(vector<pair<int, char>> &A, int N){
    int flag = 1;   // 逆の隣接要素が存在する
    while(flag){
        flag = 0;
        for(int i=N-1; i>=0; i--){
            if(A[i].first < A[i-1].first){
                swap(A[i], A[i-1]);
                flag = 1;
            }
        }
    }
}

void selectionSort(vector<pair<int, char>> &A, int N){
    for(int i=0; i<N; i++){
        int minj = i;
        for(int j=i+1; j<N; j++){
            if(A[j].first < A[minj].first) minj = j;
        }
        swap(A[i], A[minj]);
    }
}

int main()
{
    int N; cin >> N;
    vector<pair<int, char>> cards(N);
    vector<vector<char>> mark_record(9);
    vector<vector<char>> mark_record2(9);
    vector<vector<char>> mark_record3(9);
    for(int i=0; i<N; i++){
        string card; cin >> card;
        int num = card[1] - '0'; char mark = card[0];
        cards[i] = make_pair(num, mark);
        mark_record[num-1].push_back(mark);
    }
    auto cards2 = cards;
    bubbleSort(cards, N);
    for(int i=0; i<N; i++){
        mark_record2[cards[i].first-1].push_back(cards[i].second);
        cout << cards[i].second << cards[i].first;
        if(i != N-1) cout << " ";
    }
    cout << endl;
    if(mark_record == mark_record2) cout << "Stable" << endl;
    else cout << "Not stable" << endl;
    selectionSort(cards2, N);
    for(int i=0; i<N; i++){
        mark_record3[cards2[i].first-1].push_back(cards2[i].second);
        cout << cards2[i].second << cards2[i].first;
        if(i != N-1) cout << " ";
    }
    cout << endl;
    if(mark_record == mark_record3) cout << "Stable" << endl;
    else cout << "Not stable" << endl;
}
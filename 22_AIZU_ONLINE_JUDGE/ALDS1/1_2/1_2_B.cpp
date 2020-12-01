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

int bubbleSort(vector<int> &A, int N){
    int flag = 1;   // 逆の隣接要素が存在する
    int count = 0;  // 本来不要
    while(flag){
        flag = 0;
        for(int i=N-1; i>=0; i--){
            if(A[i] < A[i-1]){
                swap(A[i], A[i-1]);
                flag = 1;
                count += 1; // 本来不要
            }
        }
    }
    return count;   // 本来不要
}

int selectionSort(vector<int> &A, int N){
    int count = 0;  // 本来不要
    for(int i=0; i<N; i++){
        int minj = i;
        for(int j=i+1; j<N; j++){
            if(A[j] < A[minj]) minj = j;
        }
        if(i != minj) count += 1;   // 本来不要
        swap(A[i], A[minj]);
    }
    return count;   // 本来不要
}

int main()
{
    int N; cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++){
        int Ai; cin >> Ai;
        A[i] = Ai;
    }
    int count = selectionSort(A, N);
    for(int i=0; i<N; i++){
        cout << A[i];
        if(i != N-1) cout << " ";
    }
    cout << endl;
    cout << count << endl;
}   
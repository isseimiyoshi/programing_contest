#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector <int> bb(N);
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        bb[i] = num;
    }
    // 2で割り切れた回数をカウントする変数
    int count = 0;
    int isEven = 1;
    while(true){
        for(int i=0; i<N; i++){
            // もし2で割り切れたら
            if(bb[i] % 2 == 0){
                bb[i] = bb[i] / 2;
            }else{
                isEven = 0;
                break;
            }
        }
        if(isEven == 0){
            break;
        }else{
            count += 1;
        }
    }
    cout << count << endl;
}
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

struct dice {
    int men1, men2, men3, men4, men5, men6;
    // コンストラクタ：構造体をオブジェクト化する時に引数をとった場合される処理
    dice(){
        men1 = 0; men2 = 0; men3 = 0;
        men4 = 0; men5 = 0; men6 = 0;
    }

    dice(int men1_, int men2_, int men3_, int men4_, int men5_, int men6_){
        men1 = men1_; men2 = men2_; men3 = men3_;
        men4 = men4_; men5 = men5_; men6 = men6_;
    }

    void roll(char di){
        int ori_men1 = men1; int ori_men2 = men2;
        int ori_men3 = men3; int ori_men4 = men4;
        int ori_men5 = men5; int ori_men6 = men6;
        if(di == 'N'){
            men1 = ori_men2; men5 = ori_men1;
            men6 = ori_men5; men2 = ori_men6;
        }else if(di == 'E'){
            men1 = ori_men4; men3 = ori_men1;
            men6 = ori_men3; men4 = ori_men6;
        }else if(di == 'S'){
            men1 = ori_men5; men5 = ori_men6;
            men6 = ori_men2; men2 = ori_men1;
        }else if(di == 'W'){
            men1 = ori_men3; men3 = ori_men6;
            men6 = ori_men4; men4 = ori_men1;
        }
    }

    int display_up(){ return men1; }
    int display_front(){ return men2; }
    int display_right(){ return men3; }
    int display_left(){ return men4; }
    int display_back(){ return men5; }
    int display_down(){ return men6; }
};

bool diceSame(dice dice1, dice dice2){
    string s1 = "NNNNENNNN";
    string s2 = "WWWW";
    bool isSame = false;
    for(int i=0; i<s1.size(); i++){
        char com = s1[i];
        dice1.roll(com);
        if(dice1.display_front() == dice2.display_front()){
            for(int k=0; k<s2.size(); k++){
                com = s2[k];
                dice1.roll(com);
                if(dice1.display_up() == dice2.display_up()){
                    if(dice1.display_right() == dice2.display_right() && dice1.display_left() == dice2.display_left() && dice1.display_back() == dice2.display_back() && dice1.display_down() == dice2.display_down()){
                        isSame = true;
                        break;
                    }
                }
            }
        }
        if(isSame) break;
    }
    return isSame;
}

int main()
{
    int n; cin >> n;
    // ベクトルで型指定　→　次元数を確定した場合デフォルトで引数を指定しなかった場合の型変数が格納される
    vector<dice> dice_box(n);
    for(int i=0; i<n; i++){
        int n1, n2, n3, n4, n5, n6;
        cin >> n1 >> n2 >> n3 >> n4 >> n5 >> n6;
        dice dice1(n1, n2, n3, n4, n5, n6);
        // dice_box.push_back(dice1);
        dice_box[i] = dice1;
    }
    bool re = true;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            // if(i == j) continue;
            if(diceSame(dice_box[i], dice_box[j])) re = false;
        }
    }
    if(re) cout << "Yes" << endl;
    else cout << "No" << endl;
    /*
    string s1 = "NNNNENNNN";
    string s2 = "WWWW";
    bool isSame = false;
    for(int i=0; i<s1.size(); i++){
        char com = s1[i];
        dice1.roll(com);
        if(dice1.display_front() == dice2.display_front()){
            for(int k=0; k<s2.size(); k++){
                com = s2[k];
                dice1.roll(com);
                if(dice1.display_up() == dice2.display_up()){
                    if(dice1.display_right() == dice2.display_right() && dice1.display_left() == dice2.display_left() && dice1.display_back() == dice2.display_back() && dice1.display_down() == dice2.display_down()){
                        isSame = true;
                        break;
                    }
                }
            }
        }
        if(isSame) break;
    }
    

    if(diceSame(dice1, dice2)) cout << "Yes" << endl;
    else cout << "No" << endl;
    */
}
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<string, int> score; // 名前　→　成績
    // 氏名の方をKey、点数の方をValueという
    score["Alice"] = 100;
    score["Bob"] = 50;
    score["Charlie"] =78;
    score.erase("Charlie");
    for(pair<string, int> sc: score){
        string name = sc.first;
        int sco = sc.second;
        cout << name << " " << sco << endl;
    }
    //cout << score.at("Alice") << endl;
    //cout << score.at("Bob") << endl;
    //cout << score.at("Charlie") << endl;   
}
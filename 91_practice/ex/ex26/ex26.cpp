#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// グローバル変数にしちゃう
// 命令intで宣言された数を格納する辞書変数
map<char, int> int_nums;
// 命令vecで宣言された数を格納する辞書変数
map<char, vector<int>> vec_nums;

void my_int(string command){
    command = command.erase(0, 4);
    char moji = (char)command[0];
    command = command.erase(0, 4);
    int num = 0;
    int roop_num = (command.size() + 1) / 4;
    char ori_op = '+';
    for(int j=0; j<roop_num; j++){
        string s_num = command.substr(0,1);
        int i_num = stoi(s_num);
        if(ori_op == '+'){
            num += i_num;
        }else{
            num -= i_num;
        }
        command = command.erase(0, 2);
        ori_op = (char)command[0];
        command = command.erase(0, 2);
    }
    int_nums[moji] = num;
}

void my_vec(char moji, vector<int> vec){
    command = command.erase(0, 4);
    char moji = (char)command[0];
    command = command.erase(0, 4);



    vec_nums[moji] = vec;
}

void print_int(string command){
    int print_num = 0;
    command = command.erase(0, 10);
    int roop_num = (command.size() + 1) / 4;
    char ori_op = '+';
    for(int j=0; j<roop_num; j++){
        if(isdigit((char)command[0])){
            if(ori_op == '+'){
                print_num += (int)command[0];
            }else{
                print_num -= (int)command[0];
            }
        }else{
            if(ori_op == '+'){
                print_num += int_nums.at((char)command[0]);
            }else{
                print_num -= int_nums.at((char)command[0]);
            }
        }
        command = command.erase(0, 2);
        ori_op = (char)command[0];
        command = command.erase(0, 2);
    }
    cout << print_num << endl;
}


void print_vec(string command){
    // 命令部分の文字列を削除
    command = command.erase(0, 10);
    auto start_ind = command.find("[");
    auto end_ind = command.find("]");
    // ベクトル列数の決定
    int row_num = end_ind / 4;
    // 最終的にプリントアウトするベクトル
    vector<int> final_vec(row_num);
    // プリントするベクトルの初期化
    for(int i; i<row_num; i++){
        final_vec[i] = 0;
    }
    // 演算子
    char ori_op = '+';
    while(ori_op != ';'){
        auto start_ind = command.find("[");
        auto end_ind = command.find("]");
        string vec = command.substr(start_ind, end_ind+1);
        for(int i=0; i<row_num; i++){
            if(i == 0){
                vec = vec.erase(0,2);
            }
            int i_num = vec[0] - '0';
            if(ori_op == '+'){
                final_vec[i] += i_num;
            }else if(ori_op == '-'){
                final_vec[i] -= i_num;
            }else{
                cout << "正しい入力ではありません" << endl;
            }
            vec = vec.erase(0, 4);
        }
        // command文字列の削除
        command = command.erase(start_ind, end_ind+1);
        ori_op = command[1];
        command = command.erase(0,3);
    }
    cout << "[ ";
    for (int i = 0; i < final_vec.size(); i++) {
        cout << final_vec.at(i) << " ";
    }
    cout << "]" << endl;
}

/*
// 問題文の形式でvec値を出力
void print_vec(vector<int> vec) {
  cout << "[ ";
  for (int i = 0; i < vec.size(); i++) {
    cout << vec.at(i) << " ";
  }
  cout << "]" << endl;
}
*/


/*
input1

1
print_int 1 - 2 ;

*/

/*
input2

2
int x = 1 + 2 ;
print_int x ;

*/

/*
input3

2
print_int 1 - 2 ;
print_vec [ 1 , 2 , 3 ] - [ 3 , 2 , 1 ] ;

*/

/*
input4

6
int x = 1 + 2 ;
print_int x + 3 ;
vec a = [ 1 , 2 ] ;
vec b = a + [ 3 , 4 ] ;
vec c = a - [ 5 , 6 ] ;
print_vec c + [ 4 , 5 , 6 ] ;
*/

int main()
{
    // N:命令数
    int N;
    cin >> N; cin.ignore();
    vector <string> commands(N);
    string command;
    for(int i=0; i<N; i++){
        getline(cin, commands[i]);
    }

    for(int i=0; i<N; i++){
        string command = commands[i];
        if(command.substr(0, 3) == "int"){
            my_int(command);
        }else if(command.substr(0, 3) == "vec"){
            command = command.erase(0, 4);
            continue;
        }else if(command.substr(0, 9) == "print_int"){
            print_int(command);
        }else if(command.substr(0, 9) == "print_vec"){
            print_vec(command);
        }else{
            cout << "正しい入力ではありません。" << endl;
            break;
        }
    }


}
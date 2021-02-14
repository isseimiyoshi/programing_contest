#include <string>
#include <iostream>
#include "Account.h"

using namespace std;

// コンストラクタ
Account::Account(string name, string num, long amnt){
  full_name = name;
  number = num;
  crnt_balance = amnt;
}

void Account::deposit(long amnt){
  crnt_balance += amnt;
}

void Account::withdraw(long amnt){
  crnt_balance -= amnt;
}

int main() {
  Account suzuki("suzuki","123456",100000);
  Account miyoshi("miyoshi","987654", 200000000000);
  suzuki.deposit(100);
  miyoshi.withdraw(500000000);
  
  cout << miyoshi.balance() << endl;
  return 0;
}
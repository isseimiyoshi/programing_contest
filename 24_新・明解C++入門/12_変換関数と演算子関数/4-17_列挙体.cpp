#include <iostream>

using namespace std;

int main(){
  enum animal { Dog, Cat, Monkey, Invalid };
  int type;

  do{
    cout << "0...犬　1...猫　2...猿　3...終了 : ";
    cin >> type;
  }while(type < Dog || Invalid < type);

  if(type != Invalid){
    animal selected = static_cast<animal>(type);
    switch (selected)
    {
      case Dog: cout << "bowbow" << endl; break;
      case Cat: cout << "myaao" << endl; break;
      case Monkey: cout << "keekee" << endl; break;
    }
  }
}
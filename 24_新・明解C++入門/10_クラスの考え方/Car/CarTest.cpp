#include <iostream>
#include "Car.h"

using namespace std;

int main(){
  string name; int width, length, height;
  double gas;
  cout << "Enter your car information, please." << "\n";
  cout << "What's your car's name?" << "\n"; cin >> name;
  cout << "width?" << "\n"; cin >> width;
  cout << "length?" << "\n"; cin >> length;
  cout << "height?" << "\n"; cin >> height;
  cout << "How much gas does your car have?" << "\n"; cin >> gas;

  Car myCar(name, width, length, height, gas);
  myCar.print_spec();

  printf("%.6f %.6f\n", myCar.x(), myCar.y());
}
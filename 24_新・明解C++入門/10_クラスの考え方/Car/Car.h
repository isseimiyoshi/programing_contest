// 自動車クラス

#include <cmath>
#include <string>
#include <iostream>

class Car {
  std::string name;
  int width, length, height;
  double xp,yp;
  double fuel_level;

public:
  Car(std::string n, int w, int l, int h, double f){
    name = n; width = w; length = l; height = h; fuel_level = f;
    xp = yp = 0.0;
  }

  double x() { return xp; }
  double y() { return yp; }
  double fuel(){ return fuel_level; }
  void print_spec(){
    std::cout << "name: " << name << "\n";
    std::cout << "width: " << width << "\n";
    std::cout << "length: " << length << "\n";
    std::cout << "height: " << height << "\n";
  }
  bool move(double dx, double dy){
    double dist = sqrt(dx*dx + dy*dy);
    if(dist>fuel_level) return false;
    else{
      fuel_level -= dist;
      xp += dx; yp += dy;
      return true;
    }
  }
};
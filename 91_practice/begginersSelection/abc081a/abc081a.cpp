#include<iostream>
using namespace std;
int main()
{
    string mas;
    cin >> mas;
    int count = 0;
    for(int i=0; i<mas.size(); i++){
        char pmas;
        pmas = mas.at(i);
        if(pmas == '1'){
            count += 1;
        }
    }
    cout << count << endl;
}
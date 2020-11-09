#include <iostream>
using namespace std;
class Szulo
{};
class Gyerek: public Szulo{
public: void kiir(){
cout<<"gyerek"<<endl;
}
};
int main()
{
Szulo* sz= new Gyerek();
cout << sz->kiir() <<endl;
}
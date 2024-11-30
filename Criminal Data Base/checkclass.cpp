#include <iostream>
using namespace std;
class A
{
    protected:
    void printName();
};
class B : public A
{

};
void B :: printName()
{
    cout << "Asad Shah ";
}
int main()
{
    B obj;
    obj.printName();
    return 0;
}

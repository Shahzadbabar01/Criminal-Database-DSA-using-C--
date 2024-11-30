#include <iostream>
#include <Criminals.h>
#include "Robbery.h"
#include "Security.h"
#include "WrongActs.h"
#include "Murder.h"
using namespace std;
int main()
{
    Criminals obj;
    obj.setRecoveryPassword();
    if(obj.setLoginDetails())
    {
       obj.mainMenu();
    }
    else
    {
        cout << "Your login Id / Password is Wrong " << endl;
    }
    return 0;
}

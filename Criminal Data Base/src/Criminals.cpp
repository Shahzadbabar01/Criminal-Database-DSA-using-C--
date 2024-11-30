#include <Criminals.h>
#include "Robbery.h"
#include "Murder.h"
#include "WrongActs.h"
#include "Security.h"
#include <iostream>
#include <fstream>

using namespace std;
Criminals :: Criminals()
{
}

void Criminals :: mainMenu()
{

    char again;
    do
    {
        int select;
        cout << " Welcome To CRIMINAL RECORD MANAGEMENT SYSTEM " << endl << endl;
        cout << "1) Robbery Criminals " << endl;
        cout << "2) Murder Criminals " << endl;
        cout << "3) Wrong Act Criminals " << endl;
        cout << "4) Change Security Details " << endl;
        cout << endl << "Select Your Choice ";
        cin >> select;
        switch (select)
        {
        case 1:
            {
                Robbery obj1;
                obj1.menu();
                break;
            }
        case 2:
            {
                Murder obj2;
                obj2.menu();
                break;
            }
        case 3:
            {
                WrongActs obj3;
                obj3.menu();
                break;
            }
        case 4:
            {
                Security obj4;
                obj4.menu();
                break;
            }
        default:
            {
                cout << "Wrong entry try again " << endl;
            }
        }
        cout << "Enter Y/y to perform functions again ";
        cin >> again;
    }while(again == 'y' || again == 'Y');
}


 void Criminals :: setRecoveryPassword()
 {
      ifstream File("RecoveryPassword.txt");
      if(!File.is_open())
      {
          Security obj;
          obj.pukCode();
      }
 }

bool Criminals :: setLoginDetails()
 {
       Security obj;
       ifstream File("Login.txt");
      if(!File.is_open())
      {
          obj.menu();
      }
      else
      {
    obj.readData();
    string loginId;
    string loginPassword;
    cout << "Enter Login Id       ";
    cin >> loginId;
    cout << "Enter Login Password ";
    cin >> loginPassword;
    if(obj.login(loginId, loginPassword))
    {
        return true;
    }
    else
    {
        return  false;
    }
      }
 }


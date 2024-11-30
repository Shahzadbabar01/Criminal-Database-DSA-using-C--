#include <iostream>
#include "Security.h"
#include <fstream>
using namespace std;
Security::Security()
{
   head = NULL;
   tail = NULL;
}

void Security :: menu()
{
    int pukCodePass;
                cout << "Enter Puk Code to Add another User ";
                cin >> pukCodePass;
                if(readPukCode(pukCodePass))
                {
                      char again;
    do
    {
        cout << "1) Add another User " << endl;
        cout << "2) Delete Any User ID " << endl;
        cout << "3) Display Security Details ( User ID's )" << endl;
        int check;
        switch (check)
        {
        case 1:
            {
                loginDetails();
                break;
            }
        case 2:
            {
                deleteLoginId();
                break;
            }
        case 3:
            {
                displayData();
                break;
            }
        }
        cout << "Enter y/y to Perform functions again ";
        cin >> again;
    }while(again == 'y' || again == 'Y');
                }
  else
  {
      cout << "Wrong Id Or Password, Try Again " << endl;
  }
}

bool Security :: readPukCode(int pukCode1)
{
    ifstream File("RecoveryPassword.txt");
    string asd;
    while(getline(File, asd))
    {
      if(stoi(asd) == pukCode1)
      {
          return true;
      }
    }
    File.close();
    return false;
}
 void Security :: addData(string loginId1,int loginPassword1)
        {
            SecurityNode *temp = new SecurityNode;
            temp -> loginId = loginId1;
            temp -> loginPassword = loginPassword1;
           if(head == NULL)
            {
                head = temp;
                tail = temp;
                temp -> next = NULL;
            }
            else
            {
                temp -> next = head;
                head = temp;
            }
        }


bool Security :: login(string loginId1, int loginPassword1)
{
    SecurityNode *temp;
    temp = head;
    while(temp != NULL)
    {
        if(temp -> loginId == loginId1)
        {
            if(temp -> loginPassword == loginPassword1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        temp = temp -> next;
    }
}

void Security :: loginDetails()
{
    if(countFileLines() >= 10)
    {
        cout << "You can not Add Another user as number of users are exceeding " << endl;
        cout << "If you want to add, delete to reduce the number of users " << endl;
    }
    else
    {
    string loginId;
    int loginPassword;
    cout << "Welcome To User Login Details, You Can Add User to Login " << endl;
    cout << "Enter Login Id       ";
    cin >> loginId;
    cout << "Enter Login Password ";
    cin >> loginPassword;
    addData(loginId, loginPassword);
    }
}

void Security :: pukCode()
{
    int pukCode;
    ofstream File("RecoveryPassword.txt");
    cout << "Enter Puk Code ";
    cin >> pukCode;
    File << pukCode;
    File.close();
}

void Security :: clearSecurityFile()
{
    ofstream File("Login.txt", ios::trunc);
}

void Security :: readData()
{
    ifstream File("Login.txt");
    string asd;
    int size = countFileLines()/2;
    string id[size];
    int password[size];
    int i = 0;
    int j = 1;
    while(getline(File, asd))
    {
     if(j == 1)
     {
         id[i] = asd;
     }
     if(j == 2)
     {
         password[i] = stoi(asd);
         j = 0;
         i++;
     }

     j++;
    }
    for(int k = 0; k < size; k++)
    {
        addData(id[k], password[k]);
    }
}

int Security :: countFileLines()
{
    ifstream File("Login.txt");
    string asd;
    int lines = 0;
    while(getline(File, asd))
    {
        lines++;
    }
    File.close();
    return lines;
}

void Security :: saveData()
{
    SecurityNode *temp;
    ofstream File("Login.txt");
    temp = head;
    while(temp != NULL)
    {
        File << temp -> loginId << endl;
        File << temp -> loginPassword << endl;
        temp = temp -> next;
    }
}

void Security :: deleteLoginId()
{

    string deleteId;
    displayData();
    cout << "Enter Id you want to Delete ";
    cin >> deleteId;
     if(head -> loginId == deleteId)
        {
        SecurityNode *temp;
        temp = head;
        head = head -> next;
        delete temp;
        }
        else if(tail -> loginId == deleteId)
        {
        SecurityNode *previous;
        SecurityNode *current;
        current = head;
        while(current -> next != NULL)
        {
            previous = current;
            current = current -> next;
        }
        tail = previous;
        previous -> next = NULL;
        delete current;
        }
        else
        {
            SecurityNode *temp1;
            temp1 = head;
            int checkNode = 1;
            while(temp1 != NULL)
            {
                if(temp1 -> loginId == deleteId)
                {
                   break;
                }
                    checkNode++;
                    temp1 = temp1 -> next;
           }
        SecurityNode *previous;
        SecurityNode *current;
        current = head;
        for(int i = 1; i < checkNode; i++)
        {
            previous = current;
            current = current -> next;
        }

       previous -> next = current -> next;
       delete current;
        }
    }

void Security :: displayData()
{
    SecurityNode *temp;
    temp = head;
    while(temp != NULL)
    {
        cout << temp -> loginId << endl;
        cout << temp -> loginPassword << endl;
        temp = temp -> next;
    }
}

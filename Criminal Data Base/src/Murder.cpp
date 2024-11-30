#include "Murder.h"
#include <Criminals.h>
#include <fstream>
Murder::Murder()
{
    head = NULL;
    tail = NULL;
}


int Murder :: deleteData(string deleteId)
{
    if(!isEmpty())
    {
     if(head -> id == deleteId)
        {
        MurderNode *temp;
        temp = head;
        head = head -> next;
        delete temp;
        }
        else if(tail -> id == deleteId)
        {
        MurderNode *previous;
        MurderNode *current;
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
        else if(head -> id != deleteId && tail -> id != deleteId)
        {
            MurderNode *temp1;
            temp1 = head;
            int checkNode = 1;
            while(temp1 != NULL)
            {
                if(temp1 -> id == deleteId)
                {
                   break;
                }
                    checkNode++;
                    temp1 = temp1 -> next;
                    if(temp1 -> next == NULL)
                    {
                        cout << "No Data Found " << endl;
                        return 0;
                    }
           }
        MurderNode *previous;
        MurderNode *current;
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
    else
    {
        cout << "No Data available to Delete " << endl;
    }

}
void Murder :: displayData()
{
    if(!isEmpty())
    {
         MurderNode *temp;
           temp = head;
           while(temp != NULL)
           {
               cout << "Id              " << temp -> id << endl;
               cout << "Date            " << temp -> date << "\n";
               cout << "Name            " << temp -> name << endl;
               cout << "Phone Number    " << temp -> phone_no << endl;
               cout << "Address         " << temp -> address << endl;
               cout << "Crime           " << temp -> crime << endl;
               cout << "Charges         " << temp -> charges << endl;
               cout << "Additional Info " << temp -> criminalDetails << endl << endl;

               temp = temp -> next;
           }
    }
    else
    {
        cout << "No Data available to Display " << endl;
    }

}
void Murder :: addData(string id1, string date1, string name1, string phone_no1, string address1, string crime1, string charges1, string criminalDetails1)
{
            MurderNode *temp = new MurderNode;
            temp -> id = id1;
            temp -> date = date1;
            temp -> name = name1;
            temp -> phone_no = phone_no1;
            temp -> address = address1;
            temp -> crime = crime1;
            temp -> charges = charges1;
            temp -> criminalDetails = criminalDetails1;
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

void Murder :: saveData()
{
      ofstream myFile("MurderCriminals.txt" , ios::app);
           MurderNode *temp;
           temp = head;
           while(temp != NULL)
           {
               myFile << temp -> id << endl;
               myFile << temp -> date << endl;
               myFile << temp -> name << endl;
               myFile << temp -> phone_no << endl;
               myFile << temp -> address << endl;
               myFile << temp -> crime << endl;
               myFile << temp -> charges << endl;
               myFile << temp -> criminalDetails<< endl;
               temp = temp -> next;
           }

}
int Murder :: countFileLines()
{
    string asd;
    int countLines = 0;
    ifstream myFile("MurderCriminals.txt");
    if(myFile.is_open())
    {
        while(getline(myFile , asd))
        {
            countLines++;
        }
    }
         myFile.close();
         return countLines;
}

void Murder :: clearFile()
{
    ofstream File("MurderCriminals.txt", ios::trunc);
    File.close();
}

bool Murder :: searchData(string key)
{
     if(!isEmpty())
    {
        MurderNode *temp;
        temp = head;
           while(temp != NULL)
           {
               if(temp -> id == key){
               cout << endl << "Id              " << temp -> id << endl;
               cout << "Date            " << temp -> date << "\n";
               cout << "Name            " << temp -> name << endl;
               cout << "Phone Number    " << temp -> phone_no << endl;
               cout << "Address         " << temp -> address << endl;
               cout << "Crime           " << temp -> crime << endl;
               cout << "Charges         " << temp -> charges << endl;
               char check;
               cout << "Additional Info " << temp -> criminalDetails << endl;
               cout << endl << "Do you want to update this data ";
               cin >> check;
               if(check == 'y' || check == 'Y')
               {
                   updateData(temp -> id);
               }
               return true;
               }
            temp = temp -> next;
           }
           cout << "No previous data available " << endl;
           return false;
    }
    else
    {
       cout << "No Previous Data available to Search " << endl;
    }
}

void Murder :: getData()
{
   char again;
   time_t now = time(0);
    char* date = ctime(&now);
    do
        {
       string idPass;
        string datePass;
        string namePass;
        string phone_noPass;
        string addressPass;
        string crimePass = "WrongActs";
        string chargesPass;
        string criminalDetailsPass;
    cout << "ID              ";
    cin >> idPass;
        if(searchData(idPass))
        {
            cout << endl << "This id also has previous record " << endl;
        }
        else
        {
            for(int i = 0; i < 11; i++)
        {
             datePass += date[i];
        }
        datePass += " 2023";
        cout << "Name            ";
        cin >>namePass;
        cout << "Phone No        ";
        cin >> phone_noPass;
        cout << "Address         ";
        cin >> addressPass;
        cout << "Charges         ";
        cin >> chargesPass;
        cout << "Additional Info ";
        cin >> criminalDetailsPass;
        addData(idPass ,datePass , namePass , phone_noPass , addressPass , crimePass , chargesPass , criminalDetailsPass);
        }

        cout << "Enter Y/y to ADD another data ";
        cin >> again;
}while(again == 'y' || again == 'Y');
}

void Murder :: readFile()
{
    ifstream File("MurderCriminals.txt");
    if(File.is_open())
    {
         int i = 0;
    int j = 1;
    int size = countFileLines()/8;
    string arrId[size];
    string arrDate[size];
    string arrName[size];
    string arrPhone_No[size];
    string arrAddress[size];
    string arrCrime[size];
    string arrCharges[size];
    string arrCriminalDetails[size];
    string asd;
        while(getline(File , asd))
        {

            if(j == 1)
            {
                arrId[i] = asd;
            }
            else if(j == 2)
            {
               arrDate[i] = asd;
            }
            else if(j == 3)
            {
               arrName[i] = asd;
            }
            else if(j == 4)
            {
               arrPhone_No[i] = asd;
            }
            else if(j == 5)
            {
               arrAddress[i] = asd;
            }
            else if(j == 6)
            {
               arrCrime[i] = asd;
            }
            else if(j == 7)
            {
               arrCharges[i] = asd;

            }
            else if(j == 8)
            {
               arrCriminalDetails[i] = asd;
               j = 0;
               i++;
            }
            j++;
        }
        for(int k = 0; k < size; k++)
        {
            addData(arrId[k], arrDate[k], arrName[k], arrPhone_No[k], arrAddress[k],  arrCrime[k], arrCharges[k], arrCriminalDetails[k]);
        }
    }
   File.close();
}

void Murder :: updateData(string upDateId)
{
     if(!isEmpty())
    {
    MurderNode *temp;
    temp = head;
    while(temp != NULL)
    {
        if(temp -> id == upDateId)
        {
           char again;
           do
           {
            int choice;
            cout << "Enter which part of data you want to Update " << endl;
            cout << "1) Name " << endl;
            cout << "2) Phone Number " << endl;
            cout << "3) Address " << endl;
            cout << "4) Charges " << endl;
            cout << "5) Criminal Details " << endl;
            cout << "Select Your Choice  ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                {
                    cout << "Updated Name             ";
                    cin >> temp -> name;
                    break;
                }
            case 2:
                {
                    cout << "Updated Phone Number     ";
                    cin >> temp -> phone_no;
                    break;
                }
            case 3:
                {
                    cout << "Updated Address          ";
                    cin >> temp -> address;
                    break;
                }
            case 4:
                {
                    cout << "Updated Charges          ";
                    cin >> temp -> charges;
                    break;
                }
            case 5:
                {
                    cout << "Updated Criminal Details ";
                    cin >> temp -> criminalDetails;
                    break;
                }
            default:
                {
                    cout << "Wrong Entry, Try Again " << endl;
                }
            }
            cout << "Enter y/y if you want to Update Criminal Data Again ";
            cin >> again;
           }while (again == 'y' || again == 'Y');
            break;
        }
       temp = temp -> next;
    }
    }
    else
    {
         cout << "No Data available to Update " << endl;
    }

}
void Murder :: menu()
{
    deleteNodeData();
    readFile();
    char again;
    do
    {
        int select;
        cout <<  endl << "Welcome to the Menu of Robbery Criminals " << endl;
        cout << "1) Add Data " << endl;
        cout << "2) Delete Data " << endl;
        cout << "3) Search Data " << endl;
        cout << "4) Update Data " << endl;
        cout << "5) Display Data " << endl;
        cout << endl << "Select your choice ";
        cin >> select;
        switch (select)
        {
        case 1:
            {
                getData();
                break;
            }
            case 2:
                {
                    string deleteId1;
                    cout << "Enter Id you want to Delete the Data ";
                    cin >> deleteId1;
                    deleteData(deleteId1);
                    break;
                }
                case 3:
                {
                     string searchId;
                     cout << "Enter ID to find the Robbery Criminal Data ";
                     cin >> searchId;
                    searchData(searchId);
                    break;
                }
                case 4:
                    {
                        string upDateId1;
                        cout << "Enter Id to Update Data ";
                        cin >> upDateId1;
                        updateData(upDateId1);
                        break;
                    }
                case 5:
                    {
                        displayData();
                        break;
                    }
                default:
                    {
                        cout << "Wrong Entry Try Again " << endl;
                    }
        }

        cout << "Enter Y/y to perform functions again ";
        cin >> again;
    }while(again == 'y' || again == 'Y');
    clearFile();
    saveData();
}
bool Murder :: isEmpty()
{
    if(head == NULL)
    {
       return true;
    }
    else
    {
        return false;
    }
}

void Murder :: deleteNodeData()
{
    MurderNode *temp;
    temp = head;
    while(temp != NULL)
    {
        MurderNode *temp1;
        temp1 = temp;
        temp = temp -> next;
        delete temp1;
    }
}


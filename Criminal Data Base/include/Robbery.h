#ifndef ROBBERY_H
#define ROBBERY_H
#include "Robbery.h"
#include <Criminals.h>
using namespace std;
struct RobberyNode
{
        string id;
        string date;
        string name;
        string phone_no;
        string address;
        string crime;
        string charges;
        string criminalDetails;
        RobberyNode *next;
};

class Robbery :  public Criminals
{
private:
    RobberyNode *head;
    RobberyNode *tail;
        public:
            Robbery();
            void menu();
            void getData();
            void displayData();
            void addData(string id1, string date1, string name1, string phone_no1, string address1, string crime1, string charges1, string criminalDetails1);
            int deleteData(string deleteId1);
            void updateData(string updateId);
            void saveData();
            int countFileLines();
            void readFile();
            void clearFile();
            bool searchData(string searchId);
            bool isEmpty();
            void deleteNodeData();

};

#endif // ROBBERY_H

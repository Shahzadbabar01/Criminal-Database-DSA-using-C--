#ifndef WRONGACTS_H
#define WRONGACTS_H

#include <Criminals.h>

using namespace std;
struct WrongActNode
{
        string id;
        string date;
        string name;
        string phone_no;
        string address;
        string crime;
        string charges;
        string criminalDetails;
        WrongActNode *next;
};
class WrongActs : public Criminals
{
    public:
        WrongActs();
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

    private:
          WrongActNode *head;
          WrongActNode *tail;
};

#endif // WRONGACTS_H

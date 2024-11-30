#ifndef SECURITY_H
#define SECURITY_H
#include <Criminals.h>
#include <fstream>
using namespace std;
struct SecurityNode
{
   string loginId;
   string loginPassword;
   SecurityNode *next;
};

class Security : public Criminals
{
    public:
    Security();
    void menu();
    bool login(string loginId1, string loginPassword1);
    void loginDetails();
    void pukCode();
    void clearSecurityFile();
    int deleteLoginId();
    void readData();
    int countFileLines();
    bool readPukCode(string pukCode1);
    void saveData();
    void addData(string loginId1,string loginPassword1);
    void displayData();
    bool isEmpty();
    void deleteNodeData();

    private:
        SecurityNode *head;
        SecurityNode *tail;
};

#endif // SECURITY_H

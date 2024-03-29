#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#include <string>
using namespace std;

class User
{
    int id;
    string login;
    string password;
    string name;
    string surname;
public:
    void setId(int newId);
    void setLogin(string newLogin);
    void setPassword(string newPassword);
    void setName(string newName);
    void setSurname(string newSurname);
    int getId();
    string getLogin();
    string getPassword();
    string getName();
    string getSurname();
};


#endif // USER_H_INCLUDED

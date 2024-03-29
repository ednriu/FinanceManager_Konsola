#include "userfile.h"

void UserFile::saveXmlFromVector(vector<User> users, string FileName)
{
    CMarkup xml;

    xml.AddElem( "USERS" );
    xml.IntoElem();
    for(vector <User> :: iterator it = users.begin(); it != users.end(); ++it)
    {
        xml.AddElem("USER");
        xml.IntoElem();
        xml.AddElem("ID",to_string((*it).getId()));
        xml.AddElem( "LOGIN", (*it).getLogin());
        xml.AddElem( "PASSWORD", (*it).getPassword());
        xml.AddElem( "NAME", (*it).getName());
        xml.AddElem( "SURNAME", (*it).getSurname());
        xml.OutOfElem();
    }
    xml.OutOfElem();
    xml.Save(FileName);
    //"E:\\NaukaCPP\\FinanceManager\\" +
};

vector<User> UserFile::loadXmlToVector(string FileName)
{
    CMarkup xml;
    User individualUserRecord;
    vector<User> users;

    xml.Load(FileName);
    //"E:\\NaukaCPP\\FinanceManager\\" +

    xml.ResetPos(); // top of document
    xml.FindElem(); // ORDER element is root
    xml.IntoElem(); // inside ORDER

    while ( xml.FindElem("USER") )
    {
        xml.IntoElem();

        xml.FindElem("ID");
        individualUserRecord.setId(atoi(MCD_2PCSZ(xml.GetData())));

        xml.FindElem( "LOGIN" );
        individualUserRecord.setLogin(xml.GetData());

        xml.FindElem( "PASSWORD" );
        individualUserRecord.setPassword(xml.GetData());

        xml.FindElem( "NAME" );
        individualUserRecord.setName(xml.GetData());

        xml.FindElem( "SURNAME" );
        individualUserRecord.setSurname(xml.GetData());

        xml.OutOfElem();
        users.push_back(individualUserRecord);
    }
    return users;
};



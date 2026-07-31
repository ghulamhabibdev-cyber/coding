#ifndef H_node
#define H_node
#include <iostream>
using namespace std;
class node
{
private:
    int tokenNo;
    string name;
    string serviceTyep;
    node *next;

public:
    node()
    {
        tokenNo = 0;
        name = "";
        serviceTyep = "";
        next = NULL;
    }
    void setToken(int no)
    {
        this->tokenNo = no;
    }
    int getTokenNO()
    {
        return tokenNo;
    }
    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return name;
    }
    void setService(string sev)
    {
        this->serviceTyep = sev;
    }
    string getServic()
    {
       return serviceTyep;
    }
    void setNext(node *next)
    {
        this->next=next;
    }
    node * getNext()
    {
        return next;
    }
};
#endif

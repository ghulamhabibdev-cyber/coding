#ifndef H_LinkListTypes
#define H_LinkListTypes
#include <bits/stdc++.h>
#include "ImplementGenericLinkList.h"
using namespace std;
template <class Type>
class UnorderedLinkList : public LinkList<Type>
{
public:
    bool search(const Type &item);
    void insertFirst(const Type &item);
    void insertLast(const Type &item);
    void deleteNode(const Type &delItem);
    // const LinkList<Type> &operator=(const LinkList<Type> &otherList);
};
// Implementing unorederedLink List
template<class Type>
void UnorderedLinkList<Type>::insertLast(const Type &item)
{
    node<Type>*newNode=new node<Type>(item);
    if(this->first==NULL)
    {
        this->first=newNode;
        this->last=newNode;
        
    }
    else{
        this->last->link=newNode;
        this->last=newNode;
    }
    this->count++;
}
template <class Type>
void UnorderedLinkList<Type>::deleteNode(const Type &item)
{
    node<Type> *current;
    node<Type> *prev;
    bool found = false;
    if (this->first == NULL)
    {
        cout << "CanNot Delete From Empty List\n";
    }
    else
    {
        // if delte node is first node 
        if (this->first->info == item)
        {
            current = this->first;
            this->first = this->first->link;
            
            if (this->first == NULL)
            {
                this->last = NULL;
            }
            delete current;
            this->count--;
        }
        else
        {
            found = false;
            prev = this->first;
            current = this->first->link;
            while (current != NULL && !found)
            {
                if (current->info != item)
                {
                    prev = current;
                    current = current->link;
                }
                else
                {
                    found = true;
                }
            }
            if(found)
            {
                prev->link=current->link;
                this->count--;
                if(this->last==current)
                {
                    this->last=prev;
                }
                delete current;
            }
            else{
                cout<<"Not in List\n";
            }
        }
    }
}
template <class Type>
void UnorderedLinkList<Type>::insertFirst(const Type &item)
{
    node<Type> *newNode = new node<Type>(item);
    newNode->link = this->first;
    this->first = newNode;
    if (this->last == NULL)
    {
        this->last = newNode;
    }
    this->count++;
}
template <class Type>
bool UnorderedLinkList<Type>::search(const Type &searhItem)
{
    bool found = false;
    node<Type> *temp;
    temp = this->first;
    while (temp != NULL && !found)
    {
        if (temp->info == searhItem)
        {
            found = true;
        }
        else
        {
            temp = temp->link;
        }
        /* code */
    }
    return found;
}

#endif
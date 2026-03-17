#ifndef H_arrayList
#define H_arrayList

#define NDEBUG
#include <bits/stdc++.h>
#include <cassert>
#include <iostream>
using namespace std;
// decalartion
template <class elemType>
class arrayListType
{
protected:
    elemType *list;
    int length;
    int maxSize;

public:
    arrayListType(int n = 100);
    arrayListType(arrayListType<elemType> &otherObj);
public:
    ~arrayListType();
public:
    arrayListType<elemType> &operator=(arrayListType<elemType> &otherObjec);
public:
    bool isEmpty();
    bool isFull();
    int listSize();
    int getMaxSize();
    void print();
    bool isItemAtEqual(int loc, const elemType &item);
    void insertAt(int loc, const elemType&item);
    void insertEnd(const elemType &item);
    void removeAt(int loc);
    void retreiveAt(int , elemType& item);
    void replaceAt(int ,const elemType &item);
    void clearList();
    int seqSearch(const elemType&);
    void insert(const elemType &);
    void remove(const elemType &);
};
// definations
template<class elemType>
void arrayListType<elemType>::remove(const elemType &item)
{
    int loc;
    if(length==0)
    {
        cerr<<"CantNot Delete From the Empry List \n";
    }
    else
    {
        loc=seqSearch(item);
        if(loc!=-1)
        {
            removeAt(loc);
        }
        else{
            cout<<"The Item Tobe Deleted Is Not Present In List\n";
        }
    }
}
template<class elemType>
void arrayListType<elemType>::insert(const elemType &item)
{
    int loc;
    if(length==0)
    {
        list[length++]=item;
    }
    else if(length>=maxSize)
    {
        cerr<<"List is Already Full\n";
    }
    else{
        loc=seqSearch(item);
        if(loc==-1)
        {
            list[length++]=item;
        }
        else{
            cerr<<"Item is Already Present \n";
        }
    }
}
template<class elemType>
int arrayListType<elemType>::seqSearch(const elemType &item)
{
    int loc;
    bool found;
    for(loc=0;loc<length;loc++)
    {
        if(list[loc]==item)
        {
            found=true;
            break;
        }
    }
    if(found)
    {
        return loc;
    }
    return -1;

}
template<class elemType>
void arrayListType<elemType>::clearList()
{
    length=0;
}
template<class elemType>
void arrayListType<elemType>::replaceAt(int loc,const elemType &item)
{
    if(loc<0||loc>=length)
    {
        cerr<<"Index is Out Of Range \n";
    }
    else{
        list[loc]=item;
    }
}
template<class elemType>
void arrayListType<elemType>::retreiveAt(int loc, elemType &item)
{
    if(loc<0||loc>=length)
    {
        cerr<<"Index is Out of Range \n";
    }
    else{
        item=list[loc];
    }
}
template <class elemType>
void arrayListType<elemType>::insertEnd(const elemType &item)
{
    if(length>=maxSize)
    {
        cerr<<"List is Full \n";
    }
    else{
        list[length++]=item;
    }
}
template <class elemType>
void arrayListType<elemType>::removeAt(int location)
{
    if(location<0||location>=length)
    {
        cerr<<"The Invalid Index to Remove\n";
    }
    else{
        for(int i=location;i<length-1;i++)
        {
            list[i]=list[i+1];
        }
        length--;
    }
}
template <class elemType>
void arrayListType<elemType>::insertAt(int location,const elemType& item)
{
    if(location<0||location>=maxSize)
    {
        cerr<<"Thse Position is Out of Range \n";
    }
    else{
        if(length>=maxSize)
        {
            cerr<<"The lis Is Full \n";
        }
        else{
            for(int i=length;i>location;i--)
            {
                list[i]=list[i+1];
            }
            list[location]=item;
            length++;
            
        }
    }
}
template <class elemType>
bool arrayListType<elemType>::isItemAtEqual(int location, const elemType &other)
{
    assert(location>=0 &&location<length);
    return (list[location] == other);
}

template <class elemType>
void arrayListType<elemType>::print()
{
    for (int i = 0; i < length; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
}
template <class elemType>
int arrayListType<elemType>::getMaxSize()
{
    return maxSize;
}
template <class elemType>
int arrayListType<elemType>::listSize()
{
    return length;
}
template <class elemType>
bool arrayListType<elemType>::isEmpty()
{
    return (length == 0);
}
template <class elemType>
bool arrayListType<elemType>::isFull()
{
    return (length == maxSize);
}

template <class elemtype>
arrayListType<elemtype>::arrayListType(int size)
{
    if (size < 0)
    {
        cerr << "The Array Size Must be Positve .\nCreating Array of Size 100";
        maxSize = 100;
    }
    else
    {
        maxSize = size;
    }
    length = 0;
    list = new elemtype[maxSize];
    assert(list != NULL);
}
template <class elemType>
arrayListType<elemType>::~arrayListType()
{
    delete[] list;
}
template <class elemType>
arrayListType<elemType>::arrayListType(arrayListType<elemType> &otherObjec)
{
    // creating objects using copy constructor
    maxSize = otherObjec.maxSize;
    length = otherObjec.length;
    list = new elemType[maxSize];
    assert(this != NULL);
    for (int i = 0; i < length; i++)
    {
        list[i] = otherObjec.list[i];
    }
}
template <class elemType>
arrayListType<elemType> &arrayListType<elemType>::operator=(arrayListType<elemType> &otherObjec)
{
    if (this != &otherObjec)
    {
        delete[] list;
        maxSize = otherObjec.maxSize;
        length = otherObjec.length;
        list = new elemType[maxSize];
        assert(this != NULL);
        for (int i = 0; i < length; i++)
        {
            list[i] = otherObjec.list[i];
        }
    }
    return *this;
}
#endif

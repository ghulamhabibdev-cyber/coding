#ifndef H_testList
#define H_testList
#include <bits/stdc++.h>
#define NDEBUG
#include <cassert>
#include <iostream>
using namespace std;
template <class elemType>
class arrayList
{
protected:
    int length;
    int maxsize;
    int *list;
public:
    arrayList(int size = 100);
    arrayList(arrayList<elemType> &otherObject);

public:
    arrayList<elemType> &operator=(arrayList<elemType> &otherObjec);
public:
    ~arrayList();
public:
    bool isEmpty();
    bool isFull();
    int listSize();
    int maxSize();
    void print();
    bool isItemAtEqual(int, const elemType &);
    void inserAt(int loc, const elemType &);
    void insertEnd(const &elemType &);
    void removeAt(int loc);
    void retrieveAt(int loc, const elemType &);
    void replaceAt(int loc, const elemType &);
    void clearList();
    int seqSearch(const elemType &);
    void insert(cosnt elemType &);
    void remove(const elemType);
};
// definations 
// impleentRemove at
// implement insertAt push item forward then insert at loc
template<class elemType>
void arrayList<elemType>::inserAt(int loc,const elemType &item)
{
    if(loc<0||loc>=maxsize)
    {
        cout<<"Index Out Of range \n";
    }
    else{
        if(length>=maxsize)
        {
            cout<<"List is already Full\n";
        }
        else{
            for(int i=length;i>loc;i--)
            {
                list[i]=list[i-1];
            }
            length++;
        }
    }
}
// implemting the print methode
template<class elemType>
bool arrayList<elemType>::isItemAtEqual(int loc,const elemType&item)
{
    return (list[loce]==elemType);
}
template<class elemType>
void arrayList<elemType>::print()
{
    for(int i=0;i<length;i++)
    {
        cout<<list[i];
    }
}
// implementing sizeList give currnt lenght of lsit
template<class elemType>
int arrayList<elemType>::listSize()
{
    return length;
}
template<class elemType>
int arrayList<elemType>::maxSize()
{
    return maxsize;
}
// implement isEmpty return bool if empty or not
template<class elemType>
bool arrayList<elemType>::isFull()
{
    return (length==maxsize);
}
template<class elemType>
bool arrayList<elemType>::isEmpty()
{
    return (length==0);
}

// implementing destror
template<class elemType>
arrayList<elemType>::~arrayList()
{
    delete[] list;
}
template<class elemType>
arrayList<elemType>& arrayList<elemType>::operator=(arrayList<elemType>&otherObj)
{
    if(this!=ohterObj)
    {
        delete [] list;
        maxsize=otherObj.maxsize;
        length=otherObj.length;
        list=new elemType[maxsize];
    }
}
template<class elemType>
arrayList<elemType>::arrayList(arrayList<elemType>&other)
{
    maxsize=other.maxsize;
    length=other.length;
    list=new elemType[maxsize];
    assert(list!=NULL);
    for(int i=0;i<length;i++)
    {
        list[i]=other.list[i];
    }

}
template<class elemType>
arrayList<elemType>::arrayList(int size)
{
    if(size<0)
    {
        cout<<"size can be negative so ";
        cout<<"Array of length 100 is inilized\n";
        maxsize=100;
    }
    else{
        maxsize=size;
        
    }
    length=0;
    list=new elemType[maxSize];
}

#endif

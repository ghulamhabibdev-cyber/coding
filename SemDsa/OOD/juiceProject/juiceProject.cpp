#include <bits/stdc++.h>
using namespace std;
class cashRegister
{
private:
    int cashOnHand;

public:
    int getCurrentBalance();
    void acceptAmount(int amount);
    cashRegister();
    cashRegister(int amount);
};
class dispenserType
{
private:
    int noOfItems;
    int cost;

public:
    int getNoItems();
    int getCost();
    void makeSale();
    dispenserType();
    dispenserType(int noOfItems, int cost);
};
dispenserType::dispenserType()
{
    noOfItems = 50;
    cost = 50;
}
dispenserType::dispenserType(int noOfItem, int cost)
{
    this->noOfItems = noOfItem;
    this->cost = cost;
}
int dispenserType::getNoItems()
{
    return noOfItems;
}
int dispenserType::getCost()
{
    return cost;
}
void dispenserType::makeSale()
{
    if (noOfItems >= 0)
        noOfItems--;
}
cashRegister::cashRegister()
{
    cashOnHand = 500;
}
int cashRegister::getCurrentBalance()
{
    return cashOnHand;
}
void cashRegister::acceptAmount(int amount)
{
    if (amount >= 0)
        cashOnHand += amount;
}
cashRegister::cashRegister(int amount)
{
    if (amount >= 0)
    {
        this->cashOnHand = amount;
    }
    else
    {
        cashOnHand = 500;
    }
}
void sellProduct(dispenserType product, cashRegister pCounter)
{
    int amount1;
    int amount2;
    if(product.getNoItems()>0)
    {
        cout<<"Please Make Deposite \n";
        cin>>amount1;
        if(amount1<product.getCost())
        {
            cout<<"Enter more More Money  : "<<product.getCost()-amount1<<endl;
            cout<<"Please Enter Amount equal to this \n";
            cin>>amount2;
            amount1+=amount2;
        }
        if(amount1>=product.getCost())
        {
            pCounter.acceptAmount(amount1);
            product.makeSale();
            cout<<"Please Collect Your Produt\n";
        }
        else{
            cout<<"Amount is not Suffiecint \n";
        }
    }
    else{
        cout<<"This procut is Sold \n";
    }
}
void showSelection()
{
    cout << "=============================== X Juice Corner =============================\n";
    cout << "To Get Item Enter Right No \n";
    cout << "1 For Apple Juice \n";
    cout << "2 For Orange Juice \n";
    cout << "3 For Mango Juice\n";
    cout << "4 For Fruit Punch \n";
    cout << "9 For -> EXIT\n";
}
int main()
{
    cashRegister counter;
    dispenserType applceJuice(100, 50);
    dispenserType OrangeJucie(100, 50);
    dispenserType mangoJuice(100, 50);
    dispenserType fruitPunch(100, 50);
    // dispenserType applceJuice(100,50);
    int choice;
    showSelection();
    cin >> choice;
    while (choice != 9)
    {
        switch (choice)
        {
        case 1:
            sellProduct(applceJuice, counter);
            cout<<"\nThanks for Visite\n";
            showSelection();
            break;
        case 2:
            sellProduct(OrangeJucie, counter);
            cout<<"\nThanks for Visite\n";
            showSelection();
            break;
        case 3:
            sellProduct(applceJuice, counter);
            cout<<"\nThanks for Visite\n";
            showSelection();
            break;
        case 4:
            sellProduct(mangoJuice, counter);
            cout<<"\nThanks for Visite\n";
            showSelection();
            break;
        case 9:
            sellProduct(fruitPunch, counter);
            cout<<"\nThanks for Visite\n";
            showSelection();
            break;
        default:
            cout<<"Invalid Selction\n";
            break;
        }
    }

    return 0;
}

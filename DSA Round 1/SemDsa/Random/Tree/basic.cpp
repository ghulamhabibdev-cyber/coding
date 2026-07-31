#include <iostream>
using namespace std;
class node
{
    int data;
    node * left;
    node * right;
    node(int data);
    ~node();
};
node::node(int data)
{
    this->data=data;
    left=NULL;
    right=NULL;
}
// ste

int main() {

    return 0;
}

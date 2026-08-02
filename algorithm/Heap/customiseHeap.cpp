#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

// Your custom comparator
struct cmp
{
    bool operator()(const pair<int, string> &a, const pair<int, string> &b)
    {
        if (a.first != b.first)
        {
            return a.first > b.first; // Reverses default max-heap behavior for the 1st element
        }
        return a.second > b.second; // Reverses default max-heap behavior for the 2nd element
    }
};

int main()
{
    // Declaring the priority queue with your custom struct
    priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;

    // 1. Example data pushing out-of-order pairs
    pq.push({1, "banana"});
    pq.push({5, "apppe"});
    pq.push({5, "apple"});
    pq.push({2, "date"});
    pq.push({10, "apple"});

    // 2. Displaying how data is retrieved (Popping from top)
    cout << "Elements popped from the priority_queue:\n";
    while (!pq.empty())
    {
        auto current = pq.top();
        cout << "(" << current.first << ", " << current.second << ")\n";
        pq.pop();
    }

    return 0;
}

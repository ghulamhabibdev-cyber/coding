#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
    vector<int> heap;

    void heapifyUp(int index) {
        while(index > 0) {
            int parent = (index - 1) / 2;

            if(heap[parent] < heap[index]) {
                swap(heap[parent], heap[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        while(true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if(left < size && heap[left] > heap[largest]) {
                largest = left;
            }
            if(right < size && heap[right] > heap[largest]) {
                largest = right;
            }

            if(largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int extractMax() {
        if(heap.empty()) return -1;

        int maxVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        heapifyDown(0);
        return maxVal;
    }

    void print() {
        for(int x : heap) cout << x << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap h;
    h.insert(10);
    h.insert(40);
    h.insert(20);
    h.insert(50);
    h.insert(30);

    h.print(); // max on top (index 0)

    cout << "Extract: " << h.extractMax() << endl;
    h.print();
}

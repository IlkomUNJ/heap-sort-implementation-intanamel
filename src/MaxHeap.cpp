#include <iostream>
using namespace std;

class MaxHeap {
private:
    int* heap;
    int size;
    int capacity;

    void maxHeapify(int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && heap[left] > heap[largest])
            largest = left;

        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            maxHeapify(largest);
        }
    }

public:
    MaxHeap(int cap) {
        size = 0;
        capacity = cap;
        heap = new int[cap];
    }

    void insert(int value) {
        if (size == capacity) {
            cout << "Heap sudah penuh!" << endl;
            return;
        }

        int i = size;
        heap[size++] = value;

        while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void printHeap() {
        cout << "Heap saat ini: ";
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }

    void printSortedHeap() {
        int* tempHeap = new int[size];
        for (int i = 0; i < size; i++)
            tempHeap[i] = heap[i];

        int tempSize = size;
        cout << "Heap Terurut : ";
        while (tempSize > 0) {
            cout << tempHeap[0] << " ";
            tempHeap[0] = tempHeap[tempSize - 1];
            tempSize--;
            int i = 0;

            while (true) {
                int left = 2 * i + 1;
                int right = 2 * i + 2;
                int largest = i;

                if (left < tempSize && tempHeap[left] > tempHeap[largest])
                    largest = left;
                if (right < tempSize && tempHeap[right] > tempHeap[largest])
                    largest = right;

                if (largest != i) {
                    swap(tempHeap[i], tempHeap[largest]);
                    i = largest;
                } else break;
            }
        }
        cout << endl;
        delete[] tempHeap;
    }

    ~MaxHeap() {
        delete[] heap;
    }
};

int main() {
    MaxHeap h(10);

    h.insert(20);
    h.insert(15);
    h.insert(30);
    h.insert(40);
    h.insert(50);

    cout << "=== Sebelum Penghapusan ===" << endl;
    h.printHeap();
    h.printSortedHeap();

    return 0;
}

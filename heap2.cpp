#include <iostream>
#include <vector>

using namespace std;

// A class to represent a Max-Heap
class MaxHeap {
private:
    vector<int> heap;

    // Returns the index of the parent
    int parent(int i) { return (i - 1) / 2; }

    // Returns the index of the left child
    int left(int i) { return (2 * i + 1); }

    // Returns the index of the right child
    int right(int i) { return (2 * i + 2); }

    // Heapify-down: maintains the heap property
    void heapifyDown(int i) {
        int l = left(i);
        int r = right(i);
        int largest = i;

        if (l < heap.size() && heap[l] > heap[largest])
            largest = l;

        if (r < heap.size() && heap[r] > heap[largest])
            largest = r;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

    // Heapify-up: maintains the heap property
    void heapifyUp(int i) {
        if (i && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            heapifyUp(parent(i));
        }
    }

public:
    // Insert a new key into the heap
    void insert(int key) {
        heap.push_back(key);
        //int ind = heap.size() - 1;
        heapifyUp(heap.size() - 1);
    }

    // Remove the maximum element (root of the heap)
    void extractMax() {
        if(heap.size() == 0){
            cout<<-1;
            return;
        }
        
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        
    }

    // Return the maximum element (root of the heap)
    int getMax() {
        if (heap.size() == 0) {
            cout << "Heap is empty\n";
            return -1;
        }
        return heap.front();
    }

    // Display the heap
    void printHeap() {
        for (int i : heap)
            cout << i << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap h;

    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(6);
    h.insert(1);
    h.insert(8);
    h.insert(9);

    cout << "Max-Heap array: ";
    h.printHeap();

    cout << "Max element: " << h.getMax() << endl;

    h.extractMax();
    cout << "After extracting max: ";
    h.printHeap();

    return 0;
}

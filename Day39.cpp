#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
    vector<int> heap;

    void heapifyUp(int i) {
        while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void heapifyDown(int i) {
        int n = heap.size();
        while (true) {
            int left = 2*i + 1;
            int right = 2*i + 2;
            int smallest = i;

            if (left < n && heap[left] < heap[smallest])
                smallest = left;

            if (right < n && heap[right] < heap[smallest])
                smallest = right;

            if (smallest == i) break;

            swap(heap[i], heap[smallest]);
            i = smallest;
        }
    }

public:
    void insert(int x) {
        heap.push_back(x);
        heapifyUp(heap.size() - 1);
    }

    int extractMin() {
        if (heap.empty()) return -1;

        int minVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty())
            heapifyDown(0);

        return minVal;
    }

    int peek() {
        if (heap.empty()) return -1;
        return heap[0];
    }
};

int main() {
    int N;
    cin >> N;

    MinHeap h;

    for (int i = 0; i < N; i++) {
        string op;
        cin >> op;

        if (op == "insert") {
            int x;
            cin >> x;
            h.insert(x);
        }
        else if (op == "extractMin") {
            cout << h.extractMin() << endl;
        }
        else if (op == "peek") {
            cout << h.peek() << endl;
        }
    }

    return 0;
}

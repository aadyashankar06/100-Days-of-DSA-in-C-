#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main() {

    deque<int> dq;

    // push operations
    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(5);
    dq.push_front(1);

    cout << "Deque after push operations: ";
    for(int x : dq)
        cout << x << " ";
    cout << endl;

    // pop operations
    dq.pop_front();
    dq.pop_back();

    cout << "Deque after pop operations: ";
    for(int x : dq)
        cout << x << " ";
    cout << endl;

    // front and back
    cout << "Front element: " << dq.front() << endl;
    cout << "Back element: " << dq.back() << endl;

    // size
    cout << "Size of deque: " << dq.size() << endl;

    // reverse
    reverse(dq.begin(), dq.end());

    cout << "Deque after reverse: ";
    for(int x : dq)
        cout << x << " ";
    cout << endl;

    // sort
    sort(dq.begin(), dq.end());

    cout << "Deque after sorting: ";
    for(int x : dq)
        cout << x << " ";
    cout << endl;

    // clear
    dq.clear();

    cout << "Deque empty? " << dq.empty() << endl;

    return 0;
}

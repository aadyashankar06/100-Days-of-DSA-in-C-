/*
Problem Statement:
Implement a hash table using quadratic probing with formula:

h(k, i) = (h(k) + i*i) % m

Input Format:
- First line: m (size of hash table)
- Second line: n (number of operations)
- Next n lines:
    INSERT x
    SEARCH x

Output Format:
- For SEARCH: print FOUND or NOT FOUND

Sample Input:
7
4
INSERT 49
INSERT 56
SEARCH 49
SEARCH 15

Sample Output:
FOUND
NOT FOUND
*/

#include <iostream>
#include <vector>
using namespace std;

class HashTable {
    vector<int> table;
    int m;

public:
    HashTable(int size) {
        m = size;
        table.assign(m, -1); // -1 means empty
    }

    int hashFunc(int key) {
        return key % m;
    }

    void insert(int key) {
        int h = hashFunc(key);

        for (int i = 0; i < m; i++) {
            int idx = (h + i * i) % m;

            if (table[idx] == -1) {
                table[idx] = key;
                return;
            }
        }
        // table full → ignore insert
    }

    bool search(int key) {
        int h = hashFunc(key);

        for (int i = 0; i < m; i++) {
            int idx = (h + i * i) % m;

            if (table[idx] == key)
                return true;

            if (table[idx] == -1)
                return false; // stop early
        }

        return false;
    }
};

int main() {
    int m, n;
    cin >> m >> n;

    HashTable ht(m);

    while (n--) {
        string op;
        int x;
        cin >> op >> x;

        if (op == "INSERT") {
            ht.insert(x);
        }
        else if (op == "SEARCH") {
            if (ht.search(x))
                cout << "FOUND\n";
            else
                cout << "NOT FOUND\n";
        }
    }

    return 0;
}

/*Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.

Input:
- First line: integer n
- Second line: n space-separated integers (the array)
- Third line: integer pos (1-based position)
- Fourth line: integer x (element to insert)*/


#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[100];
    for(int i = 0;i < n;i++){
        cin>>arr[i];
    }
    int pos, x;
    cin>>pos>> x;

    for(int i = n;i >= pos;i--){
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = x;

    for(int i = 0;i <= n;i++){
        cout<<arr[i]<< " ";
    }
    return 0;
}


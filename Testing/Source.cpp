#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void swapInt(int& n1, int& n2) {
    int temp = n1;
    n1 = n2;
    n2 = temp;
}

void printArray(int* nums, int len) {
    cout << "[ ";
    for (int i = 0; i < len; i++) {
        cout << nums[i] << " ";
    }
    cout << "]\n";
}

void miniSort(int* nums, int length) {
    int* result = new int[length];
    for (int i = 0; i < length; i++) {
        result[i] = nums[i];
    }
    printArray(result, length);
    int end = 0;
    int iterator = 0;
    while (end != length - 1)
    {
        end = 0;
        int i = 0;
        while (i != length - 1) {
            if (result[i] > result[i + 1]) {
                swap(result[i], result[i + 1]);
                i++;
            }
            else {
                i++;
                end++;
            }
            iterator++;
        }
        
    }
    printArray(result, length);
    cout << "Number of iterator: " << iterator << endl;
}



int main() {
    int count = 0, size = 0;
    cout << "Nhap so array: ";
    cin >> count;
    int** nums = new int*[count];
    cout << "Nhap kich thuoc array: ";
    cin >> size;
    for (int i = 0; i < count; i++) {
        nums[i] = new int[size];
    }
    cout << "Nhap du lieu array:\n";
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < size; j++) {
            cin >> nums[i][j];
        }
    }
    for (int i = 0; i < count; i++) {
        miniSort(nums[i], size), size;
    }
}
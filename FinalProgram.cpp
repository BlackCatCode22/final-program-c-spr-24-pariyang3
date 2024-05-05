#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

// Linear search function with iteration count
int linearSearch(const vector<int>& arr, int target) {
    int iterations = 0;
    for (int i = 0; i < arr.size(); ++i) {
        iterations++;
        if (arr[i] == target) {
            cout << "Linear Search Iterations: " << iterations << endl;
            return i; // Return index of target if found
        }
    }
    cout << "Linear Search Iterations: " << iterations << endl;
    return -1; // Return -1 if target not found
}

// Recursive binary search function with iteration count
int recursiveBinarySearch(const vector<int>& arr, int target, int low, int high, int& iterations) {
    iterations++;
    if (low > high) {
        cout << "Binary Search Iterations: " << iterations << endl;
        return -1; // Return -1 if target not found
    }
    
    int mid = low + (high - low) / 2;
    if (arr[mid] == target) {
        cout << "Binary Search Iterations: " << iterations << endl;
        return mid; // Return index of target if found
    } else if (arr[mid] < target) {
        return recursiveBinarySearch(arr, target, mid + 1, high, iterations);
    } else {
        return recursiveBinarySearch(arr, target, low, mid - 1, iterations);
    }
}

int main() {
    try {
        // Example array
        vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int target = 6;
        
        // Linear search
        int linearIndex = linearSearch(arr, target);
        if (linearIndex != -1) {
            cout << "Linear Search: Element found at index " << linearIndex << endl;
        } else {
            cout << "Linear Search: Element not found" << endl;
        }
        
        // Binary search
        int low = 0;
        int high = arr.size() - 1;
        int iterations = 0;
        int binaryIndex = recursiveBinarySearch(arr, target, low, high, iterations);
        if (binaryIndex != -1) {
            cout << "Recursive Binary Search: Element found at index " << binaryIndex << endl;
        } else {
            cout << "Recursive Binary Search: Element not found" << endl;
        }
        
        // Performance comparison
        auto start = chrono::high_resolution_clock::now();
        linearIndex = linearSearch(arr, target);
        auto linear_end = chrono::high_resolution_clock::now();
        auto linear_duration = chrono::duration_cast<chrono::microseconds>(linear_end - start);
        cout << "Linear Search Time: " << linear_duration.count() << " microseconds" << endl;

        start = chrono::high_resolution_clock::now();
        binaryIndex = recursiveBinarySearch(arr, target, low, high, iterations);
        auto binary_end = chrono::high_resolution_clock::now();
        auto binary_duration = chrono::duration_cast<chrono::microseconds>(binary_end - start);
        cout << "Recursive Binary Search Time: " << binary_duration.count() << " microseconds" << endl;

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}

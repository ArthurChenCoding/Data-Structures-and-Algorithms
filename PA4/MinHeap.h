#ifndef MIN_HEAP_H
#define MIN_HEAP_H

using namespace std;       

class MinHeap
{
  private:

    int *arr; // pointer to array of elements in heap 
    int capacity; // maximum possible size of min heap 
    int heap_size; // Current number of elements in min heap

  public:

    // Constructor for the MinHeap
    MinHeap(int cap) {
        heap_size = 0; 
        capacity = cap; 
        arr = new int[cap]; 
    }

    // to ge the index of parent of node at index i
    inline int parent(int i) { return (i-1)/2; } 
  
    // to get index of left child of node at index i 
    inline int left(int i) { return (2*i + 1); } 
  
    // to get index of right child of node at index i 
    inline int right(int i) { return (2*i + 2); } 

    // Returns the minimum key (key at root) from min heap 
    inline int getMin() {  return arr[0]; } 

    // Inserts a new key 'k' 
    void insertKey(int k) {
        // Remove below line after your implementation
        return;
    }

    // Extract the root which is the minimum element 
    int extractMin() {
        // Remove below line after your implementation
        return arr[0];
    }
  
    // Decreases key value of key at index i to newVal 
    void decreaseKey(int i, int newVal) {
        // Remove below line after your implementation
        return;
    }
  
    // Deletes a key stored at index i 
    void deleteKey(int i) {
        // Remove below line after your implementation
        return;
    }
};

#endif

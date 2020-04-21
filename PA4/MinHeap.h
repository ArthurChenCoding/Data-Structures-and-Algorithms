#ifndef MIN_HEAP_H
#define MIN_HEAP_H

using namespace std;       
void swap(int* x, int* y){
	int holder = *x;
	*x=*y;
	*y=holder;
}
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
        if(heap_size == capacity){
			cout << "Cannot insert key" << endl;
			return;
		}
		++heap_size;
		int i = heap_size-1;
		arr[i] = k;
		while(i !=0 && arr[parent(i)] > arr[i]){
			swap(&arr[i],&arr[parent(i)]);
			i = parent(i);
		}	
    }
	void Heapify(int i) {
		int lindex = left(i);
		int rindex = right(i);
		int min = i;
		if(arr[lindex] < arr[i] && lindex < heap_size){
			min = lindex;
		}
		if(arr[rindex] < arr[min] && rindex < heap_size){
			min = rindex;
		}
		if(min != i){
			swap(&arr[i],&arr[min]);
			Heapify(min);		
		}    
	}
    // Extract the root which is the minimum element 
    int extractMin() {
        if (heap_size <=0){
			cout << "cannot extract min" << endl;
		}
		if (heap_size ==1){
			heap_size-1;
			return arr[0];
		}
		int root = arr[0];
		arr[0] = arr[heap_size-1];
		heap_size--;
		Heapify(0);
        return root;
    }
  
    // Decreases key value of key at index i to newVal 
    void decreaseKey(int i, int newVal) {
        arr[i] = newVal;
		while(arr[parent(i)] > arr[i] && i != 0){
			swap(&arr[i],&arr[parent(i)]);
			i = parent(i);
		}
    }
  
    // Deletes a key stored at index i 
    void deleteKey(int i) {
		decreaseKey(i, 0);
		extractMin();
	}
    
};

#endif

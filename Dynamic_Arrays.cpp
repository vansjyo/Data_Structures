#include <bits/stdc++.h>

using namespace std;

template <class T>
class customDynamicArray {
private:
    T *var; // initializing a pointer to type T, will eventually be a pointer to a memory in heap 
    int size;
    int growthFactor = 2;
    int capacity = 5;


public:
    // constructor
    customDynamicArray() {
        var = new T[capacity]; // allocating memory to heap for an array, returns the pointer to the head of the contigous heap memory and asssigns to var
        size = 0; // initally setting size od array as 0 
    }

    void append(T val) {
        if(size==capacity) {
            resize();
        }
        var[size] = val; // element in that array can accesses using var[index]
        size++;
    }

    void resize() {
        capacity*=growthFactor;
        T *copyVar = new T[capacity]; // initializes copyVar to point to head of: created another array on heap of capacity 
        copy(copyVar);
        delete []var; // deletes the entire block of memory ([] is important) that var is pointing to
        var = nullptr; // this also happens implcitly when you do `delete []var`
        var = copyVar; // assigns the lcoation pointed to by copyvar to var
    }

    // you ideally shouldn't return an array from a function call because you can only return a pointer to an array 
    void copy(T *copyVar) {
        // no need to pass by reference since we are passing a pointer here
        for(int i = 0; i<size; i++) {
            copyVar[i] = var[i];
        }
    }

    T get(int pos) {
        if(pos >= size || pos < 0) {
            throw out_of_range("Invalid Index for access");
        }
        return var[pos];
    }

    void removeAt(int pos) {
        if(pos >= size || pos < 0) {
            throw out_of_range("Invalid index for deletion");
        }
        for(int i = pos; i<size; i++) {
            var[i] = var[i+1];
        }
        // no need to handle nullifying var[size] since no method allows accessing that element
        size--;
    }

    void insertAt(int pos, T val) {
        if(pos > size || pos < 0) {
            throw out_of_range("Invalid Index for insert");
        }
        if(pos==size) {
            append(val);
            return;
        }
        // unneseccary complexity to reduce O(2*n) to O(n)
        if(size==capacity) {
            capacity*=growthFactor;
            T *copyVar = new T[capacity];
            for(int i = 0, k = 0; i<=size; i++) {
                if(i==pos) {
                    copyVar[i] = val;
                    continue;
                }
               copyVar[i] = var[k];
               k++;
            }
            // deletes the memory block pointed to by the var pointer, so this pointer is now a null/invalid ptr
            delete []var;
            var = nullptr;
            var = copyVar;
        }
        else {
            // if there is sufficient memory, first shift all elements after pos by a step forward and then set var[pos] to val 
            for(int i = size, k = size; i>pos; i--, k--) {
                var[i] = var[k-1];
            }
            var[pos] = val;
        }
        size++;
    }

    void replaceAt(int pos, T val) {
        if(pos >= size || pos < 0) {
            throw out_of_range("Invalid index for Replacing");
        }
        var[pos] = val;
    }

    void print() {
        for(int i = 0; i<size; i++) {
            cout << var[i] << " ";
        }
        cout << endl;
    }

    int getSize() {
        return size;
    }

    // destructor - not needed since we arent really doing any custom behaviour here
    // if you get a use case of defining your own destructor, then you must also define your custom copy constructor and assignment operators
    // i.e. either define all 3, or else in almost all cases, the default copy constructor and destructor should be sufficient
    ~customDynamicArray() {
        delete var;
    }
};

int main() {
    customDynamicArray<int> v;
    v.append(3);
    v.append(5);
    v.append(6);
    v.append(2);
    v.append(8);
    v.insertAt(2, 9);
    v.print();
    cout << v.getSize() << endl;
    v.insertAt(5, 8);
    v.removeAt(3);
    v.print();
    cout << v.get(3) << endl;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

template <class T>
class Node {
public:
    T val;
    Node <T> *next;

    Node() {
        val = 0;
        next = nullptr;
    }

    Node(T value) {
        val = value;
        next = nullptr;
    }
    
};

template <class T>
class customLinkedList {
private:
    Node <T> *head;
    Node <T> *tail;
    int size;

public:
    // constructor
    customLinkedList() {
        size = 0; // initally setting size of array as 0 
    }

    void append(T val) {
        Node <T> *newNode = new Node <T>(val);
        if(size==0) {
            head = newNode;
            tail = head;
        }
        tail->next = newNode;
        tail = newNode;
        size++;
    }

    Node <T> *getPointerTo(int pos) {
        if(pos >= size || pos < 0) {
            return nullptr;
        }
        Node <T> *temp = head;
        for(int i = 0; i<pos; i++) {
            temp = temp->next;
        }
        return temp;
    }

    T getVal(int pos) {
        if(pos >= size || pos < 0) {
            throw out_of_range("Invalid Index for access");
        }
        Node <T> *temp = getPointerTo(pos);
        return temp->val;
    }

    void removeAt(int pos) {
        if(pos >= size || pos < 0) {
            throw out_of_range("Invalid index for deletion");
        }
        Node <T> *temp = getPointerTo(pos-1);
        Node <T> *toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        size--;
    }

    void insertAt(int pos, T val) {
        if(pos > size || pos < 0) {
            throw out_of_range("Invalid Index for insert");
        }
        Node <T> *temp = getPointerTo(pos-1);
        Node <T> *newNode = new Node <T>(val);
        newNode->next = temp->next;
        temp->next = newNode;
        if(size==0) {
            head = newNode;
            tail = head;
        }
        size++;
    }

    void replaceAt(int pos, T val) {
        if(pos >= size || pos < 0) {
            throw out_of_range("Invalid index for Replacing");
        }
        Node <T> *temp = getPointerTo(pos);
        temp->val = val;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return (size==0);
    }

    void print() {
        Node <T> *temp = head;
        while(temp!=NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    customLinkedList<int> v;
    v.append(3);
    v.append(5);
    v.append(6);
    v.append(2);
    v.insertAt(2, 9);
    v.print();
    cout << v.getSize() << endl;
    v.insertAt(5, 8);
    v.removeAt(3);
    v.print();
    cout << v.getSize() << endl;
    cout << v.getVal(3) << endl;

    return 0;
}
#include <iostream>
#include "board.h"
#define SIZE 5
using namespace std;

class BoardArray : public Board {
    Entry* array;
    int index;

    public:
        BoardArray() {
            array = new Entry[SIZE];
            index = 0;
        }

 ~BoardArray() {
        delete[] array; 
    }

    void add(Entry* entry) override {
        int pos = 0;
        while (pos < index && array[pos].getPriority() >= entry->getPriority()) {
            pos++;
        }
        if (index < SIZE) {
            for (int i = index; i > pos; i--) {
                array[i] = array[i - 1]; 
            }
            array[pos] = *entry; 
            index++;
        } else {
            cout << "Board is full. Cannot add more entries." << endl;
        }
    }

    void print() override { 
        for (int i = 0; i < index; i++) {
            cout << i + 1 << ". ";
            array[i].print(); 
        }
    }
};
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

    void add(Entry* entry) override {
    int pos = index; 
    for (int i = 0; i < index; i++) {
        Entry* current = array + i; 
        if (entry->compare(current)) { 
            pos = i;
            break;
        }
    }

    if (index < SIZE) {
       
        for (int j = index; j > pos; j--) {
            array[j] = array[j - 1];
        }
        array[pos] = *entry;
        index++;
    } else {
        if (pos < SIZE) {
            for (int j = SIZE - 1; j > pos; j--) {
                array[j] = array[j - 1];
            }
            array[pos] = *entry;
        } else {
            cout << entry->name << "'s score is too low to be added!\n";
        }
    }
}

    void print() override {
        for (int i = 0; i < index; i++) {
            cout << i + 1 << ". ";
            array[i].print();
        }
    }
};
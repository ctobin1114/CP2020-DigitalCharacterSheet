// CP 2020 Digital Character Sheet
// Inventory Declarations
// By ctobin1114

#ifndef INVENTORY_H 
#define INVENTORY_H

#include <string>

struct Item { // linked list item node
    std::string item; // item's name
    int count; // item count
    Item* next; // pointer to the next skill node
};

class Inventory { // Implementation of a linked list.
    public:
        Inventory();
        ~Inventory();
        void insertAtFront(std::string s, int m);
        bool removeFromFront();
        bool removeItem(std::string s);
        bool isEmpty();
        int size();
        void clear();
        Item* searchForItem(std::string s);
        bool setItemQuantity(std::string s, int m);
        bool changeItemQuantity(std::string s, int m);
        bool containsItem(std::string s);
        Item* getFront();
    private:
        Item* first; // Pointer pointing to the begining of the list
        Item* last; // Pointer pointing to the end of the list
};






#endif
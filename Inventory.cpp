// CP 2020 Digital Character Sheet
// Inventory definitions
// By ctobin1114

#include "Inventory.h"
#include <string>

using namespace std;

Inventory::Inventory(){
    this->first = NULL;
    this->last = NULL;
}

Inventory::~Inventory(){
    while (!this->isEmpty()) removeFromFront();
}

void Inventory::insertAtFront(string s, int m){
    Item* newItem =  new Item; // create new Item
    newItem->item = s; // store item name data
    newItem->count = m; // store item count data
    newItem->next = first; // head now follows newItem
    this->first = newItem;
    if(this->first->next == NULL){
        this->last = first;
    }
}

bool Inventory::removeFromFront(){
    if(!this->isEmpty()){
        Item* oldItem = this->first; // save current head
        first = oldItem->next; // skip over old head
        delete oldItem; // delete the old head
        return 1;
    }else
        return 0;
}

bool Inventory::removeItem(string s){
    if(!this->isEmpty()){
        if(containsItem(s)){
            Item* currentItem = this->first;
            if(currentItem->item == s){
                this->first = currentItem->next; // skip over old head
                delete currentItem; // delete the old head
                return 1;
            }else{
                do{
                    if(currentItem->next->item == s){
                        Item* oldItem = currentItem->next;
                        currentItem->next = oldItem->next; // skip over old head
                        delete oldItem; // delete the old head
                        return 1;
                    }else{
                        currentItem = currentItem->next;
                    }
                }while (currentItem!=last);
            }
        }else
            return 0;
    }else
        return 0;
    
    return 0;
}

bool Inventory::isEmpty(){
    return (this->first == NULL);
}

int Inventory::size(){
    if(this->isEmpty())
        return 0;
    else{
        int counter = 1;
        Item* theItem = this->first;
        while (theItem->next != NULL){
            counter++;
            theItem = theItem->next;
        }
        return counter;
    }
    return -1;
}

void Inventory::clear(){
    while (!this->isEmpty()) removeFromFront();
}

Item* Inventory::searchForItem(string s){
    Item* currentItem = this->first;
    do{
        if(currentItem->item == s)
            return currentItem;
        else{
            currentItem = currentItem->next;
        }
    }while (currentItem!=last);
    
    return NULL;
}

bool Inventory::setItemQuantity(string s, int m){
    if (containsItem(s)){
        Item* theItem = this->searchForItem(s);
        theItem->count = m;
        return 1;
    }else
        return 0;
}

bool Inventory::changeItemQuantity(string s, int m){
    if (containsItem(s)){
        Item* theItem = this->searchForItem(s);
        theItem->count += m;
        return 1;
    }else
        return 0;
}

bool Inventory::containsItem(string s){
    if(isEmpty())
        return 0;
    Item* currentItem = this->first;
    do{
        if(currentItem->item == s)
            return 1;
        else
            currentItem = currentItem->next;
    }while (currentItem!=last);

    return 0;
}

Item* Inventory::getFront(){
    return first;
}
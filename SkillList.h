// CP 2020 Digital Character Sheet
// SkillList declarations
// By ctobin1114

#ifndef SKILLLIST_H 
#define SKILLLIST_H

#include <string>

struct Skill { // linked list skill node
    std::string skill; // skill's name
    int mod; // skill's modifier
    Skill* next; // pointer to the next skill node
};

class SkillList { // Implementation of a linked list.
    public:
        SkillList();
        ~SkillList();
        void insertAtFront(std::string s, int m);
        bool removeFromFront();
        bool isEmpty();
        int size();
        void clear();
        Skill* searchForSkill(std::string s);
        bool modifySkill(std::string s, int m);
        bool containsSkill(std::string s);
        Skill* getFront();
    private:
        Skill* first; // Pointer pointing to the begining of the list
        Skill* last; // Pointer pointing to the end of the list
};

#endif
// CP 2020 Digital Character Sheet
// SkillList definitions
// By ctobin1114

#include "SkillList.h"
#include <string>

using namespace std;

SkillList::SkillList(){
    this->first = NULL;
    this->last = NULL;

    // Populate with the default skill list
    insertAtFront("authority", 0);
    insertAtFront("charismatic leadership", 0);
    insertAtFront("combat sense", 0);
    insertAtFront("credibility", 0);
    insertAtFront("family", 0);
    insertAtFront("interface", 0);
    insertAtFront("jury rig", 0);
    insertAtFront("medical tech", 0);
    insertAtFront("resources", 0);
    insertAtFront("streetdeal", 0);
    insertAtFront("personal grooming", 0);
    insertAtFront("wardrobe & style", 0);
    insertAtFront("endurance", 0);
    insertAtFront("strength feat", 0);
    insertAtFront("swimming", 0);
    insertAtFront("interrogation", 0);
    insertAtFront("intimidate", 0);
    insertAtFront("oratory", 0);
    insertAtFront("resist torture/drugs", 0);
    insertAtFront("streetwise", 0);
    insertAtFront("human perception", 0);
    insertAtFront("interview", 0);
    insertAtFront("leadership", 0);
    insertAtFront("seduction", 0);
    insertAtFront("social", 0);
    insertAtFront("persuation & fast talk", 0);
    insertAtFront("perform", 0);
    insertAtFront("accounting", 0);
    insertAtFront("anthropology", 0);
    insertAtFront("awareness/notice", 0);
    insertAtFront("biology", 0);
    insertAtFront("botany", 0);
    insertAtFront("chemistry", 0);
    insertAtFront("composition", 0);
    insertAtFront("diagnose illness", 0);
    insertAtFront("education & gen know", 0);
    insertAtFront("expert", 0);
    insertAtFront("gamble", 0);
    insertAtFront("geology", 0);
    insertAtFront("hide/evade", 0);
    insertAtFront("history", 0);
    insertAtFront("library search", 0);
    insertAtFront("mathematics", 0);
    insertAtFront("physics", 0);
    insertAtFront("programming", 0);
    insertAtFront("shadow/track", 0);
    insertAtFront("stock market", 0);
    insertAtFront("system knowledge", 0);
    insertAtFront("teaching", 0);
    insertAtFront("wilderness survival", 0);
    insertAtFront("zoology", 0);
    insertAtFront("archer", 0);
    insertAtFront("athletics", 0);
    insertAtFront("brawling", 0);
    insertAtFront("dance", 0);
    insertAtFront("dodge & escape", 0);
    insertAtFront("driving", 0);
    insertAtFront("fencing", 0);
    insertAtFront("handgun", 0);
    insertAtFront("heavy weapons", 0);
    insertAtFront("melee", 0);
    insertAtFront("motorcycle", 0);
    insertAtFront("operate hvy. machinery", 0);
    insertAtFront("pilot (gyro)", 0);
    insertAtFront("pilot (fixed wing)", 0);
    insertAtFront("pilot (dirigible)", 0);
    insertAtFront("pilot (vect.thrust vehicle)", 0);
    insertAtFront("rifle", 0);
    insertAtFront("stealth", 0);
    insertAtFront("submachinegun", 0);
    insertAtFront("aero tech", 0);
    insertAtFront("av tech", 0);
    insertAtFront("basic tech", 0);
    insertAtFront("cryotank operation", 0);
    insertAtFront("cyberdeck design", 0);
    insertAtFront("cyber tech", 0);
    insertAtFront("demolitions", 0);
    insertAtFront("disguise", 0);
    insertAtFront("electronics", 0);
    insertAtFront("elect. security", 0);
    insertAtFront("first aid", 0);
    insertAtFront("forgery", 0);
    insertAtFront("gyro tech", 0);
    insertAtFront("paint or draw", 0);
    insertAtFront("photo & film", 0);
    insertAtFront("pharmacuticals", 0);
    insertAtFront("pick lock", 0);
    insertAtFront("pick pocket", 0);
    insertAtFront("play instrument", 0);
    insertAtFront("weaponsmith", 0);
    insertAtFront("weapons tech", 0);
}

SkillList::~SkillList(){
    while (!this->isEmpty()) removeFromFront();
}

void SkillList::insertAtFront(string skillName, int skillMod){
    Skill* newSkill =  new Skill; // create new Skill
    newSkill->skill = skillName; // store skillName data
    newSkill->mod = skillMod; // store skillMod data
    newSkill->next = first; // head now follows newSkill
    this->first = newSkill;
    if(this->first->next == NULL){
        this->last = first;
    }
}

bool SkillList::removeFromFront(){
    if(!this->isEmpty()){
        Skill* oldSkill = this->first; // save current head
        first = oldSkill->next; // skip over old head
        delete oldSkill; // delete the old head
        return 1;
    }else
        return 0;
}

bool SkillList::containsSkill(string s){
    Skill* currentSkill = this->first;
    do{
        if(currentSkill->skill == s)
            return 1;
        else
            currentSkill = currentSkill->next;
    }while (currentSkill!=last);

    return 0;
}

Skill* SkillList::searchForSkill(string s){
    Skill* currentSkill = this->first;
    do{
        if(currentSkill->skill == s)
            return currentSkill;
        else{
            currentSkill = currentSkill->next;
        }
    }while (currentSkill!=last);
    
    return NULL;
}

bool SkillList::modifySkill(string s, int m){
    if (containsSkill(s)){
        Skill* theSkill = this->searchForSkill(s);
        theSkill->mod = m;
        return 1;
    }else
        return 0;
}

bool SkillList::isEmpty(){
    return (this->first == NULL);
}

int SkillList::size(){
    if(this->isEmpty())
        return 0;
    else{
        int counter = 1;
        Skill* theSkill = this->first;
        while (theSkill->next != NULL){
            counter++;
            theSkill = theSkill->next;
        }
        return counter;
    }
    return -1;
}

void SkillList::clear(){
    while (!this->isEmpty()) removeFromFront();
}

Skill* SkillList::getFront(){
    return first;
}
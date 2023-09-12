// CP 2020 Digital Character Sheet
// Edgerunner definitions
// By ctobin1114

#include "Engine.h"
#include <random>
#include <fstream>
#include <iostream>

using namespace std;

//Utility to read an Edgerunner save
Edgerunner* readSave(string fileName){
    Edgerunner* theCyberpunk = new Edgerunner();
    ifstream theFile;

    theFile.open(fileName);

    string inputLine; 
    getline(theFile,inputLine);
    int foundIndex,foundLength;

        //Handle
    foundIndex = 0;
    foundLength = inputLine.find(",",foundIndex) - foundIndex;;
    theCyberpunk->setHandle(inputLine.substr(foundIndex,foundLength));
        //Role
    foundIndex = foundLength+1;
    foundLength = inputLine.find(",", foundIndex) - foundIndex;
    theCyberpunk->setRole(inputLine.substr(foundIndex, foundLength));
        //Age
    foundIndex = foundIndex+foundLength+1;
    foundLength = inputLine.find(",",foundIndex) - foundIndex;
    theCyberpunk->setAge(stoi(inputLine.substr(foundIndex, foundLength)));
        //DamageTaken
    foundIndex = foundIndex+foundLength+1;
    foundLength = inputLine.find(",",foundIndex) - foundIndex;
    theCyberpunk->setDamageTaken(stoi(inputLine.substr(foundIndex, foundLength)));
        //INT
    foundIndex = foundIndex+foundLength+1;
    foundLength = inputLine.find(",",foundIndex) - foundIndex;
    theCyberpunk->setINT(stoi(inputLine.substr(foundIndex, foundLength)));
        //REF
    foundIndex = foundIndex+foundLength+1;
    foundLength = inputLine.find(",",foundIndex) - foundIndex;
    theCyberpunk->setREF(stoi(inputLine.substr(foundIndex, foundLength)));
        //TECH
    foundIndex = foundIndex+foundLength+1;
    foundLength = inputLine.find(",",foundIndex) - foundIndex;
    theCyberpunk->setTECH(stoi(inputLine.substr(foundIndex, foundLength)));
        //COOL
    foundIndex = foundIndex+foundLength+1;
    foundLength = inputLine.find(",",foundIndex) - foundIndex;
    theCyberpunk->setCOOL(stoi(inputLine.substr(foundIndex, foundLength)));
        //ATTR
    foundIndex = foundIndex+foundLength+1;
    foundLength = inputLine.find(",",foundIndex) - foundIndex;
    theCyberpunk->setATTR(stoi(inputLine.substr(foundIndex, foundLength)));
        //LUCK
    foundIndex = foundIndex+foundLength+1;
    foundLength = inputLine.find(",",foundIndex) - foundIndex;
    theCyberpunk->setLUCK(stoi(inputLine.substr(foundIndex, foundLength)));
        //MOVE
    foundIndex = foundIndex+foundLength+1;
    foundLength = inputLine.find(",",foundIndex) - foundIndex;
    theCyberpunk->setMOVE(stoi(inputLine.substr(foundIndex, foundLength)));
        //BOD
    foundIndex = foundIndex+foundLength+1;
    foundLength = inputLine.find(",",foundIndex) - foundIndex;
    theCyberpunk->setBOD(stoi(inputLine.substr(foundIndex, foundLength)));
        //EMP
    foundIndex = foundIndex+foundLength+1;
    foundLength = inputLine.find(",",foundIndex) - foundIndex;
    theCyberpunk->setEMP(stoi(inputLine.substr(foundIndex, foundLength)));
        //REP
    foundIndex = foundIndex+foundLength+1;
    foundLength = inputLine.find(",",foundIndex) - foundIndex;
    theCyberpunk->setReputation(stoi(inputLine.substr(foundIndex, foundLength)));
        //HUMANITY
    foundIndex = foundIndex+foundLength+1;
    foundLength = inputLine.find(",",foundIndex) - foundIndex;
    theCyberpunk->setHumanity(stoi(inputLine.substr(foundIndex, foundLength)));
        //IMPROVE POINTS
    foundIndex = foundIndex+foundLength+1;
    foundLength = inputLine.find(",",foundIndex) - foundIndex;
    theCyberpunk->setImprovePoints(stoi(inputLine.substr(foundIndex, foundLength)));
        //RUN
    foundIndex = foundIndex+foundLength+1;
    foundLength = inputLine.find(",",foundIndex) - foundIndex;
    theCyberpunk->setRun(stoi(inputLine.substr(foundIndex, foundLength)));
        //LEAP
    foundIndex = foundIndex+foundLength+1;
    foundLength = inputLine.find(",",foundIndex) - foundIndex;
    theCyberpunk->setLeap(stoi(inputLine.substr(foundIndex, foundLength)));
        //CARRY
    foundIndex = foundIndex+foundLength+1;
    foundLength = inputLine.find(",",foundIndex) - foundIndex;
    theCyberpunk->setCarry(stoi(inputLine.substr(foundIndex, foundLength)));
        //LIFT
    foundIndex = foundIndex+foundLength+1;
    foundLength = inputLine.find(",",foundIndex) - foundIndex;
    theCyberpunk->setLift(stoi(inputLine.substr(foundIndex, foundLength)));
        //BODY SAVE
    foundIndex = foundIndex+foundLength+1;
    foundLength = inputLine.find(",",foundIndex) - foundIndex;
    theCyberpunk->setBodySave(stoi(inputLine.substr(foundIndex, foundLength)));
        //BTM
    foundIndex = foundIndex+foundLength+1;
    foundLength = inputLine.find(",",foundIndex) - foundIndex;
    theCyberpunk->setBodyDamageMod(stoi(inputLine.substr(foundIndex, foundLength)));
        //HEAD SP
    foundIndex = foundIndex+foundLength+1;
    foundLength = inputLine.find(",",foundIndex) - foundIndex;
    theCyberpunk->setHeadSP(stoi(inputLine.substr(foundIndex, foundLength)));
        //TORSO SP
    foundIndex = foundIndex+foundLength+1;
    foundLength = inputLine.find(",",foundIndex) - foundIndex;
    theCyberpunk->setTorsoSP(stoi(inputLine.substr(foundIndex, foundLength)));
        //RIGHT ARM SP
    foundIndex = foundIndex+foundLength+1;
    foundLength = inputLine.find(",",foundIndex) - foundIndex;
    theCyberpunk->setRightArmSP(stoi(inputLine.substr(foundIndex, foundLength)));
        //LEFT ARM SP
    foundIndex = foundIndex+foundLength+1;
    foundLength = inputLine.find(",",foundIndex) - foundIndex;
    theCyberpunk->setLeftArmSP(stoi(inputLine.substr(foundIndex, foundLength)));
        //RIGHT LEG SP
    foundIndex = foundIndex+foundLength+1;
    foundLength = inputLine.find(",",foundIndex) - foundIndex;
    theCyberpunk->setRightLegSP(stoi(inputLine.substr(foundIndex, foundLength)));
        //LEFT LEG SP
    foundIndex = foundIndex+foundLength+1;
    foundLength = inputLine.find(",",foundIndex) - foundIndex;
    theCyberpunk->setLeftLegSP(stoi(inputLine.substr(foundIndex, foundLength)));


        //SKILLS
    string skillName;
    int skillMod;
    getline(theFile,inputLine);
    getline(theFile,inputLine);
    while(inputLine.substr(0,9) != "INVENTORY"){
        foundIndex = 0;
        foundLength = inputLine.find(",",foundIndex) - foundIndex;
        skillName = inputLine.substr(foundIndex, foundLength);
        foundIndex = foundIndex+foundLength+1;
        foundLength = inputLine.find(",",foundIndex) - foundIndex;
        skillMod = stoi(inputLine.substr(foundIndex, foundLength));
        if(theCyberpunk->hasSkill(skillName)){
            theCyberpunk->modifySkill(skillName,skillMod);
        }else{
            theCyberpunk->addSkill(skillName, skillMod);
        }
        getline(theFile,inputLine);
    }


        // INVENTORY
    string itemName;
    int itemCount;
    getline(theFile,inputLine);
    while(inputLine.substr(0,3) != "EOF"){
        foundIndex = 0;
        foundLength = inputLine.find(",",foundIndex) - foundIndex;
        itemName = inputLine.substr(foundIndex, foundLength);
        foundIndex = foundIndex+foundLength+1;
        foundLength = inputLine.find(",",foundIndex) - foundIndex;
        itemCount = stoi(inputLine.substr(foundIndex, foundLength));
        theCyberpunk->addItem(itemName, itemCount);
        getline(theFile,inputLine);
    }

    theFile.close();
    return theCyberpunk;
}
//Utility to write an Edgerunner save
void writeSave(string fileName, Edgerunner* theCyberpunk){
    ofstream theFile;
    theFile.open(fileName);

    theFile << theCyberpunk->getHandle() << ",";
    theFile << theCyberpunk->getRole() << ",";
    theFile << theCyberpunk->getAge() << ",";
    theFile << theCyberpunk->getDamageTaken() << ",";

    theFile << theCyberpunk->getINT() << ",";
    theFile << theCyberpunk->getREF() << ",";
    theFile << theCyberpunk->getTECH() << ",";
    theFile << theCyberpunk->getCOOL() << ",";
    theFile << theCyberpunk->getATTR() << ",";
    theFile << theCyberpunk->getLUCK() << ",";
    theFile << theCyberpunk->getMOVE() << ",";
    theFile << theCyberpunk->getBOD() << ",";
    theFile << theCyberpunk->getEMP() << ",";

    theFile << theCyberpunk->getReputation() << ",";
    theFile << theCyberpunk->getHumanity() << ",";
    theFile << theCyberpunk->getImprovePoints() << ",";
    theFile << theCyberpunk->getRun() << ",";
    theFile << theCyberpunk->getLeap() << ",";
    theFile << theCyberpunk->getCarry() << ",";
    theFile << theCyberpunk->getLift() << ",";
    theFile << theCyberpunk->getBodySave() << ",";
    theFile << theCyberpunk->getBodyDamageMod() << ",";

    theFile << theCyberpunk->getHeadSP() << ",";
    theFile << theCyberpunk->getTorsoSP() << ",";
    theFile << theCyberpunk->getRightArmSP() << ",";
    theFile << theCyberpunk->getLeftArmSP() << ",";
    theFile << theCyberpunk->getRightLegSP() << ",";
    theFile << theCyberpunk->getLeftLegSP() << "\n";

    theFile << "SKILLS: \n";
    Skill* currentSkill = theCyberpunk->getFirstSkill();
    while(currentSkill != NULL){
        theFile << currentSkill->skill << "," << currentSkill->mod << "\n";
        currentSkill = currentSkill->next;
    }

    theFile << "INVENTORY: \n";
    Item* currentItem = theCyberpunk->getFirstItem();
    while(currentItem != NULL){
        theFile << currentItem->item << "," << currentItem->count << "\n";
        currentItem = currentItem->next;
    }

    theFile << "EOF";
    theFile.close();
}

//Prints edgerunner's stats
void Engine::printStatus(){
    theCyberpunk.statPrint();
}

Engine::Engine(){
    running = true;
    postLoad = false;
    theCyberpunk = Edgerunner();
}

Engine::~Engine(){}

//Prints user's options
void Engine::printOptions(){
    if(postLoad){
        printStatus();
        cout << endl << "What would you like to do?"
             << endl << "    1) Roll some dice." 
             << endl << "    2) Take/Heal damage." 
             << endl << "    3) Modify stats."
             << endl << "    4) See skill list" 
             << endl << "    5) Modify/add skill"
             << endl << "    6) See inventory" 
             << endl << "    7) Modify/add item" 
             << endl << "    8) Save Edgerunner"
             << endl << "    9) End Program"
             << endl << endl << "Please enter your choice:    ";
    }else{
        cout << endl << "What would you like to do?"
             << endl << "    1) Create a new egderunner."
             << endl << "    2) Load an edgerunner."
             << endl << endl << "Please enter your choice:    ";
    }
}

//Get and use option input
void Engine::getAndUseOptionInput(){
    string input;
    cin >> input;
    int option = stoi(input);
    if(postLoad){
        if(option == 1){ // Roll dice
            cout << endl << "Why are we rolling dice?"
                 << endl << "    1) Just to roll."
                 << endl << "    2) For a skill check."
                 << endl << "    3) For a stat check."
                 << endl << "    4) For damage."
                 << endl << endl << "Please enter your choice:    ";
            cin >> input;
            option = stoi(input);
            if(option == 1){ // Just to roll
                cout << endl << "What die are we rolling?"
                     << endl << "    1) d10"
                     << endl << "    2) d6"
                     << endl << endl << "Please enter your choice:    ";
                cin >> input;
                option = stoi(input);
                if(option == 1){ //d10
                    cout << endl << "What is the modifier for the roll?    ";
                    int modifier, roll;
                    cin >> input;
                    modifier = stoi(input);
                    roll = rolld10();
                    cout << endl << roll + modifier << " = " << roll << " + " << modifier << endl;
                }else if(option == 2){ //d6
                    cout << endl << "What is the modifier for the roll?    ";
                    int modifier, roll;
                    cin >> input;
                    modifier = stoi(input);
                    roll = rolld6();
                    cout << endl << roll + modifier << " = " << roll << " + " << modifier << endl;
                }else{
                    cout << endl << "   !!! Improper Input !!!" << endl;
                }
            }else if(option == 2){ // Skill check
                int skillMod, statMod, roll, extraMod;
                cout << endl << "What skill are we rolling?    ";
                getline(cin, input);
                getline(cin, input);
                cout << "debug line 1";
                if(theCyberpunk.hasSkill(input)){
                    skillMod = theCyberpunk.getSkillMod(input);
                    cout << endl << "What stat is this skill based on?"
                         << endl << "    1) INT"
                         << endl << "    2) REF"
                         << endl << "    3) TECH"
                         << endl << "    4) COOL"
                         << endl << "    5) ATTR"
                         << endl << "    6) LUCK"
                         << endl << "    7) MOVE"
                         << endl << "    8) BOD"
                         << endl << "    9) EMP"
                         << endl << endl << "Please enter your choice:    ";
                    cin >> input;
                    option = stoi(input);
                    if(option == 1)
                        statMod = theCyberpunk.getINT();
                    else if(option == 2)
                        statMod = theCyberpunk.getREF();
                    else if(option == 3)
                        statMod = theCyberpunk.getTECH();
                    else if(option == 4)
                        statMod = theCyberpunk.getCOOL();
                    else if(option == 5)
                        statMod = theCyberpunk.getATTR();
                    else if(option == 6)
                        statMod = theCyberpunk.getLUCK();
                    else if(option == 7)
                        statMod = theCyberpunk.getMOVE();
                    else if(option == 8)
                        statMod = theCyberpunk.getBOD();
                    else if(option == 9)
                        statMod = theCyberpunk.getEMP();
                    else{
                        cout << endl << "   !!! Improper Input !!!" << endl;
                        return;
                    }
                    cout << endl << "What extra modifiers are there?    ";
                    cin >> input;
                    extraMod = stoi(input);
                    roll = statRoll();
                    cout << endl << roll + skillMod + statMod + extraMod << " = " << roll << " + " << skillMod << " + " << statMod <<  " + " << extraMod << endl;
                }else{
                    cout << endl << "   !!! Improper Input !!!" << endl;
                }
            }else if(option == 3){ //Stat check
                int statMod, roll, extraMod;
                cout << endl << "What stat is this skill based on?"
                        << endl << "    1) INT"
                        << endl << "    2) REF"
                        << endl << "    3) TECH"
                        << endl << "    4) COOL"
                        << endl << "    5) ATTR"
                        << endl << "    6) LUCK"
                        << endl << "    7) MOVE"
                        << endl << "    8) BOD"
                        << endl << "    9) EMP"
                        << endl << endl << "Please enter your choice:    ";
                cin >> input;
                option = stoi(input);
                if(option == 1)
                    statMod = theCyberpunk.getINT();
                else if(option == 2)
                    statMod = theCyberpunk.getREF();
                else if(option == 3)
                    statMod = theCyberpunk.getTECH();
                else if(option == 4)
                    statMod = theCyberpunk.getCOOL();
                else if(option == 5)
                    statMod = theCyberpunk.getATTR();
                else if(option == 6)
                    statMod = theCyberpunk.getLUCK();
                else if(option == 7)
                    statMod = theCyberpunk.getMOVE();
                else if(option == 8)
                    statMod = theCyberpunk.getBOD();
                else if(option == 9)
                    statMod = theCyberpunk.getEMP();
                else{
                    cout << endl << "   !!! Improper Input !!!" << endl;
                    return;
                }
                cout << endl << "What extra modifiers are there?    ";
                cin >> input;
                extraMod = stoi(input);
                roll = rolld6();
                cout << endl << roll + statMod + extraMod << " = " << roll << " + " << statMod <<  " + " << extraMod << endl;
            }else if(option == 4){ // Damage
                cout << endl << "What die are we using?"
                     << endl << "    1) d10"
                     << endl << "    2) d6"
                     << endl << endl << "Please enter your choice:    ";
                cin >> input;
                option = stoi(input);
                if(option == 1){ //d10
                    int diceCount, modifier, roll=0;
                    cout << endl << "How many dice are we rolling?    ";
                    cin >> input;
                    diceCount = stoi(input);
                    if(diceCount <= 0){
                        cout << endl << "   !!! Improper Input !!!" << endl;
                        return;
                    }
                    cout << endl << "What is the modifier for the roll?    ";
                    cin >> input;
                    modifier = stoi(input);
                    for(int i = 0; i < diceCount; i++){
                        roll += rolld10();
                    }
                    cout << endl << roll + modifier << " = " << roll << " + " << modifier << endl;
                }else if(option == 2){ //d6
                    int diceCount, modifier, roll=0;
                    cout << endl << "How many dice are we rolling?    ";
                    cin >> input;
                    diceCount = stoi(input);
                    if(diceCount <= 0){
                        cout << endl << "   !!! Improper Input !!!" << endl;
                        return;
                    }
                    cout << endl << "What is the modifier for the roll?    ";
                    cin >> input;
                    modifier = stoi(input);
                    for(int i = 0; i < diceCount; i++){
                        roll += rolld6();
                    }
                    cout << endl << roll + modifier << " = " << roll << " + " << modifier << endl;
                }else{
                    cout << endl << "   !!! Improper Input !!!" << endl;
                }
            }else{
                cout << endl << "   !!! Improper Input !!!" << endl;
            }
        }else if(option == 2){ // Take/Heal damage
            cout << endl << "What's happening to your health?"
                 << endl << "    1) Take damage (w/ formula)."
                 << endl << "    2) Heal Damage."
                 << endl << "    3) Increase damage taken."
                 << endl << "    4) Set damage taken."
                 << endl << endl << "Please enter your choice:    ";
            cin >> input;
            option = stoi(input);
            if(option == 1){ // Take damage w/ formula
                int damage, limbOption, damThrough;
                double apRate;
                cout << endl << "How much damage are you taking?    ";
                cin >> input;
                damage = stoi(input);
                if(damage < 0){
                    cout << endl << "    !!! Improper Input !!!" << endl;
                    return;
                }
                cout << endl << "What's the AP ratio (applied to both SP and through damage)?    ";
                cin >> input;
                apRate = stod(input);
                if(apRate < 0){
                    cout << endl << "    !!! Improper Input !!!" << endl;
                    return;
                }
                cout << endl << "What limb is being hit?"
                     << endl << "    1) Head"
                     << endl << "    2) Torso"
                     << endl << "    3) Right Arm"
                     << endl << "    4) Left Arm"
                     << endl << "    5) Right Leg"
                     << endl << "    6) Left Leg"
                     << endl << endl << "Please enter your choice:    ";
                cin >> input;
                limbOption = stoi(input);
                if(limbOption < 0 || limbOption > 6){
                    cout << endl << "    !!! Improper Input !!!" << endl;
                    return;
                }
                damThrough = theCyberpunk.damageLimb(damage, limbOption, apRate);
                cout << endl << "Took " << damThrough << " points of damage.";
            }else if(option == 2){ // Heal damage
                int heal;
                cout << endl << "How much damage are we healing?    ";
                cin >> input;
                heal = -1 * stoi(input);
                if(theCyberpunk.getDamageTaken() + heal < 0){
                    theCyberpunk.setDamageTaken(0);
                }else{
                    theCyberpunk.changeDamageTaken(heal);
                }
            }else if(option == 3){ // Increase damage taken.
                int damage;
                cout << endl << "How much damage are we taking?    ";
                cin >> input;
                damage = stoi(input);
                cout << endl << "Are we accounting for BTM (y/n)?    ";
                cin >> input;
                if(input == "y"){
                    damage += theCyberpunk.getBodyDamageMod();
                    if(damage < 1){
                        damage = 1;
                    }
                    theCyberpunk.changeDamageTaken(damage);
                    cout << endl << "You have taken " << damage << " points of damage.";
                }else if(input == "n"){
                    theCyberpunk.changeDamageTaken(damage);
                    cout << endl << "You have taken " << damage << " points of damage.";
                }else{
                    cout << endl << "   !!! Improper Input !!!" << endl;
                }
            }else if(option == 4){ // Set damage taken.
                int health;
                cout << endl << "What value is your health at?    ";
                cin >> input;
                health = stoi(input);
                if(health < 0){
                    cout << endl << "   !!! Improper Input !!!" << endl;
                }else{
                    theCyberpunk.setDamageTaken(health);
                }
            }else{
                cout << endl << "   !!! Improper Input !!!" << endl;
            }
        }else if(option == 3){ // Modify stats        !!! TODO !!!
            cout << endl << "Work in progress.";
        }else if(option == 4){ // See skill list
            Skill* currentSkill = theCyberpunk.getFirstSkill();
            while(currentSkill != NULL){
                cout << currentSkill->skill << ", " << currentSkill->mod << endl;
                currentSkill = currentSkill->next;
            }
        }else if(option == 5){ // Modify/add skill
            cout << endl << "Are we:"
                 << endl << "    1) Modifying a skill."
                 << endl << "    2) Adding a skill."
                 << endl << endl << "Please enter your choice.";
            cin >> input;
            option = stoi(input);
            if(option == 1){ // Modify skill
                cout << endl << "What skill are we modifying?    ";
                getline(cin, input);
                getline(cin, input);
                if(theCyberpunk.hasSkill(input)){
                    string skillName = input;
                    cout << endl << "Are we:"
                         << endl << "    1) Setting its modifier."
                         << endl << "    2) In/decreasing its modifier."
                         << endl << endl << "Please enter your choice.";
                    cin >> input;
                    option = stoi(input);
                    if(option == 1){ // Setting modifier
                        int newMod;
                        cout << endl << "What is the new modifier?    ";
                        cin >> input;
                        newMod = stoi(input);
                        if(newMod >= 0){
                            theCyberpunk.modifySkill(skillName, newMod);
                        }else{
                            cout << endl << "New modifier is less than 0." << endl;
                        }
                    }else if(option == 2){ // In/decreasing modifier
                        int newMod;
                        cout << endl << "What is the change?    ";
                        cin >> input;
                        newMod = stoi(input) + theCyberpunk.getSkillMod(skillName);
                        if(newMod >= 0){
                            theCyberpunk.modifySkill(skillName, newMod);
                        }else{
                            cout << endl << "New modifier is less than 0." << endl;
                        }
                    }else{
                        cout << endl << "   !!! Improper Input !!!" << endl;
                    }
                }else{
                    cout << endl << theCyberpunk.getHandle() << " does not have " << input << " skill." << endl;
                }
            }else if(option == 2){ // Add new skill
                string skillName;
                int modifier;
                cout << endl << "What skill are we adding?    ";
                getline(cin, input);
                getline(cin, input);
                skillName = input;
                if(!theCyberpunk.hasSkill(input) && skillName.find(",")){
                    cout << endl << "What is the new modifier?    ";
                    cin >> input;
                    modifier = stoi(input);
                    if(modifier >= 0){
                        theCyberpunk.addSkill(skillName, modifier);
                    }else{
                        cout << endl << "Modifier is less than 0." << endl;
                    }
                }else{
                    cout << endl << "   !!! Improper Input or Skill Already Exists !!!" << endl;
                }
            }else{
                cout << endl << "   !!! Improper Input !!!" << endl;
            }
        }else if(option == 6){ // See inventory
            Item* currentItem = theCyberpunk.getFirstItem();
            while(currentItem != NULL){
                cout << currentItem->item << ", " << currentItem->count << endl;
                currentItem = currentItem->next;
            }
        }else if(option == 7){ // Modify/add item
            cout << endl << "Are we:"
                 << endl << "    1) Modifying an item's quantity."
                 << endl << "    2) Adding a new item."
                 << endl << endl << "Please enter your choice.";
            cin >> input;
            option = stoi(input);
            if(option == 1){ // Modify item
                cout << endl << "What item are we modifying?    ";
                getline(cin, input);
                getline(cin, input);
                if(theCyberpunk.hasItem(input)){
                    string itemName = input;
                    cout << endl << "Are we:"
                         << endl << "    1) Setting its quantity."
                         << endl << "    2) In/decreasing its quantity."
                         << endl << endl << "Please enter your choice.";
                    cin >> input;
                    option = stoi(input);
                    if(option == 1){ // Setting quantity
                        int newCount;
                        cout << endl << "What is the new quantity?    ";
                        cin >> input;
                        newCount = stoi(input);
                        if(newCount >= 0){
                            theCyberpunk.setItemQuantity(itemName, newCount);
                        }else{
                            cout << endl << "New quantity is less than 0." << endl;
                        }
                    }else if(option == 2){ // In/decreasing quantity
                        int newCount;
                        cout << endl << "What is the change?    ";
                        cin >> input;
                        if(newCount >= 0){
                            theCyberpunk.changeItemQuantity(itemName, newCount);
                        }else{
                            cout << endl << "New quantity is less than 0." << endl;
                        }
                    }else{
                        cout << endl << "   !!! Improper Input !!!" << endl;
                    }
                }else{
                    cout << endl << theCyberpunk.getHandle() << " does not have " << input << " item." << endl;
                }
            }else if(option == 2){ // Add new item
                string itemName;
                int count;
                cout << endl << "What item are we adding?    ";
                getline(cin, input);
                getline(cin, input);
                itemName = input;
                if(!theCyberpunk.hasItem(input) && itemName.find(",")){
                    cout << endl << "What is the new quantity?    ";
                    cin >> input;
                    count = stoi(input);
                    if(count >= 0){
                        theCyberpunk.addItem(itemName, count);
                    }else{
                        cout << endl << "Quantity is less than 0." << endl;
                    }
                }else{
                    cout << endl << "   !!! Improper Input OR Item Already Exists !!!" << endl;
                }
            }else{
                cout << endl << "   !!! Improper Input !!!" << endl;
            }
        }else if(option == 8){ // Save Edgerunner
            saveEdgerunner();
            cout << endl << "    !!! Successfully Saved !!!" << endl;
        }else if(option == 9){ // Close
            running = 0;
        }else{
            cout << endl << "   !!! Improper Input !!!" << endl;
        }
    }else{
        if(option == 1){ // Create New Edgerunner      !!! TODO !!!
            cout << "What's the punk's name?    ";
            getline(cin, input);
            getline(cin,input);
            theCyberpunk.setHandle(input);

            cout << "What's the punk's role?    ";
            getline(cin, input);
            theCyberpunk.setRole(input);

            cout << "What's the punk's age?    ";
            getline(cin, input);
            theCyberpunk.setAge(stoi(input));

            cout << "What's their stats? Enter in the following format:" << endl << "[INT],[REF],[TECH],[COOL],[ATTR],[LUCK],[MA],[BOD],[EMP]" << endl;
            getline(cin,input);
            int foundIndex = 0, foundLength;
                //INT
            foundLength = input.find(",",foundIndex) - foundIndex;
            theCyberpunk.setINT(stoi(input.substr(foundIndex, foundLength)));
                //REF
            foundIndex = foundIndex+foundLength+1;
            foundLength = input.find(",",foundIndex) - foundIndex;
            theCyberpunk.setREF(stoi(input.substr(foundIndex, foundLength)));
                //TECH
            foundIndex = foundIndex+foundLength+1;
            foundLength = input.find(",",foundIndex) - foundIndex;
            theCyberpunk.setTECH(stoi(input.substr(foundIndex, foundLength)));
                //COOL
            foundIndex = foundIndex+foundLength+1;
            foundLength = input.find(",",foundIndex) - foundIndex;
            theCyberpunk.setCOOL(stoi(input.substr(foundIndex, foundLength)));
                //ATTR
            foundIndex = foundIndex+foundLength+1;
            foundLength = input.find(",",foundIndex) - foundIndex;
            theCyberpunk.setATTR(stoi(input.substr(foundIndex, foundLength)));
                //LUCK
            foundIndex = foundIndex+foundLength+1;
            foundLength = input.find(",",foundIndex) - foundIndex;
            theCyberpunk.setLUCK(stoi(input.substr(foundIndex, foundLength)));
                //MOVE
            foundIndex = foundIndex+foundLength+1;
            foundLength = input.find(",",foundIndex) - foundIndex;
            theCyberpunk.setMOVE(stoi(input.substr(foundIndex, foundLength)));
                //BOD
            foundIndex = foundIndex+foundLength+1;
            foundLength = input.find(",",foundIndex) - foundIndex;
            theCyberpunk.setBOD(stoi(input.substr(foundIndex, foundLength)));
                //EMP
            foundIndex = foundIndex+foundLength+1;
            theCyberpunk.setEMP(stoi(input));

            theCyberpunk.setRun(theCyberpunk.getMOVE()*3);
            theCyberpunk.setLeap(floor(theCyberpunk.getRun()/4));
            theCyberpunk.setCarry(theCyberpunk.getBOD()*10);
            theCyberpunk.setLift(theCyberpunk.getBOD()*40);
            theCyberpunk.setBodySave(theCyberpunk.getBOD());
            if (theCyberpunk.getBOD() == 2)
                theCyberpunk.setBodyDamageMod(0);
            else if(theCyberpunk.getBOD() == 3 || theCyberpunk.getBOD() == 4)
                theCyberpunk.setBodyDamageMod(-1);
            else if (theCyberpunk.getBOD() == 5 || theCyberpunk.getBOD() == 7 || theCyberpunk.getBOD() == 7)
                theCyberpunk.setBodyDamageMod(-2);
            else if (theCyberpunk.getBOD() == 8 || theCyberpunk.getBOD() == 9)
                theCyberpunk.setBodyDamageMod(-3);
            else if (theCyberpunk.getBOD() == 10)
                theCyberpunk.setBodyDamageMod(-4);
            else if (theCyberpunk.getBOD() >= 11)
                theCyberpunk.setBodyDamageMod(-5);

            cout << "What's the punk's rep?    ";
            getline(cin, input);
            theCyberpunk.setReputation(stoi(input));

            cout << "What's the punk's humanity?    ";
            getline(cin, input);
            theCyberpunk.setHumanity(stoi(input));

            cout << "How many improvement points do they have?    ";
            getline(cin, input);
            theCyberpunk.setImprovePoints(stoi(input));

            cout << "What's their armor looking like? Format their SP as follows:" << endl << "[HEAD],[TORSO],[R.ARM],[L.ARM],[R.LEG],[L.LEG]" << endl;
            getline(cin,input);
            foundIndex = 0;
                //HEAD
            foundLength = input.find(",",foundIndex) - foundIndex;
            theCyberpunk.setHeadSP(stoi(input.substr(foundIndex, foundLength)));
                //TORSO
            foundIndex = foundIndex+foundLength+1;
            foundLength = input.find(",",foundIndex) - foundIndex;
            theCyberpunk.setTorsoSP(stoi(input.substr(foundIndex, foundLength)));
                //R ARM
            foundIndex = foundIndex+foundLength+1;
            foundLength = input.find(",",foundIndex) - foundIndex;
            theCyberpunk.setRightArmSP(stoi(input.substr(foundIndex, foundLength)));
                //L ARM
            foundIndex = foundIndex+foundLength+1;
            foundLength = input.find(",",foundIndex) - foundIndex;
            theCyberpunk.setLeftArmSP(stoi(input.substr(foundIndex, foundLength)));
                //R LEG
            foundIndex = foundIndex+foundLength+1;
            foundLength = input.find(",",foundIndex) - foundIndex;
            theCyberpunk.setRightLegSP(stoi(input.substr(foundIndex, foundLength)));
                //L LEG
            foundIndex = foundIndex+foundLength+1;
            theCyberpunk.setLeftLegSP(stoi(input.substr(foundIndex)));
            
            theCyberpunk.setDamageTaken(0);

            saveEdgerunner();

            postLoad = 1;
        }else if(option == 2){ // Load Edgerunner
            cout << endl << "What's their handle?    ";
            cin >> input;
            if(loadEdgerunner(input)){
                postLoad = 1;
            }else{
                cout << endl << "Our fixers couldn't find " << input << ".";
            }
        }
    }
}


//Load function
bool Engine::loadEdgerunner(string handle){
    string fileName = handle + ".txt";
    
    ifstream theFile;    
    theFile.open(fileName);

    if(theFile){
        theFile.close();
        theCyberpunk = *readSave(fileName);
        return 1;
    }else{
        theFile.close();
        return 0;
    }
}

//Save function
void Engine::saveEdgerunner(){
    string fileName = theCyberpunk.getHandle() + ".txt";

    writeSave(fileName, &theCyberpunk);
}

// Utility to roll a d6
int Engine::rolld6(){
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<> uni(1, 6);
    return uni(rng);
}

// Utility to roll a d10
int Engine::rolld10(){
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<> uni(1, 10);
    return uni(rng);
}

// Utility for stat and skill rolls
int Engine::statRoll(){
    int roll = 0;
    int temp;
    do{
        temp = rolld10();
        roll += temp;
    }
    while(temp == 10);
    return roll;
}

// Utility for printing title to cmd prompt
void Engine::cyberPrint(){
    cout <<     "_________          ___.                    __________                 __    " <<
        endl << "\\_   ___ \\  ___.__.\\_ |__    ____  _______ \\______   \\ __ __   ____  |  | __" <<
        endl << "/    \\  \\/ <   |  | | __ \\ _/ __ \\ \\_  __ \\ |     ___/|  |  \\ /    \\ |  |/ /" <<
        endl << "\\     \\____ \\___  | | \\_\\ \\\\  ___/  |  | \\/ |    |    |  |  /|   |  \\|    < " << 
        endl << " \\______  / / ____| |___  / \\___  > |__|    |____|    |____/ |___|  /|__|_ \\" <<
        endl << "        \\/  \\/          \\/      \\/                                \\/      \\/" <<
        endl << "                                  ________  _______   ________  _______     " <<
        endl << "                                  \\_____  \\ \\   _  \\  \\_____  \\ \\   _  \\    " <<
        endl << "                                   /  ____/ /  /_\\  \\  /  ____/ /  /_\\  \\   " <<
        endl << "                                  /       \\ \\  \\_/   \\/       \\ \\  \\_/   \\  " <<
        endl << "                                  \\_______ \\ \\_____  /\\_______ \\ \\_____  /  " <<
        endl << "                                          \\/       \\/         \\/       \\/   " <<
        endl << endl << "                  Digital Character Sheet By ctobin1114" << endl << endl;
}
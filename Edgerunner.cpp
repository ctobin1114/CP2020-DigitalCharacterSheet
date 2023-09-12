// CP 2020 Digital Character Sheet
// Edgerunner definitions outside of .h file
// By ctobin1114

#include "Edgerunner.h"
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

Edgerunner::Edgerunner(){ // create default edgerunner, Impulse the Nomad Warrior, for debugging purposes.
    // //Character Vars
    // setHandle("Impulse");    setRole("Warrior");    setAge(25);    setDamageTaken(0);
    // //Primary Stats
    // setINT(8);    setREF(10);    setTECH(8);    setCOOL(8);    setATTR(2);
    // setLUCK(4);    setMOVE(6);    setBOD(10);    setEMP(6);
    // //Secondary Stats
    // setReputation(2);    setHumanity(60);    setImprovePoints(0);
    // setRun(18);    setLeap(4);    setCarry(100);    setLift(400);
    // setBodySave(10);    setBodyDamageMod(-4);
    // //Limb SP
    // setHeadSP(22);    setTorsoSP(28);    setRightArmSP(28);
    // setLeftArmSP(28);    setRightLegSP(28);    setLeftLegSP(28);
    // //Skills
    // skillSet = SkillList();

    // modifySkill("intimidate", 4);
    // modifySkill("awareness/notice", 6);
    // modifySkill("wilderness survival",3);
    // modifySkill("athletics", 5);
    // modifySkill("dodge & escape", 3);
    // modifySkill("handgun", 4);
    // modifySkill("motorcycle", 5);
    // modifySkill("rifle",7);
    // modifySkill("basic tech", 6);
    // modifySkill("electronics", 2);
    // modifySkill("first aid", 2);
    // modifySkill("weaponsmith", 4);

    // addSkill("warpath", 10);
    // addSkill("akido", 2);
    // addSkill("cherokee", 4);
    // addSkill("english", 4);
    // addSkill("streetslang", 8);

    // //Inventory
    // backPack = Inventory();

}

Edgerunner::~Edgerunner(){}

int Edgerunner::damageLimb(int damage, int limb, float apRate){ // Mutator to damage a given limb
    int damThrough, limbSP;
    if(limb = 1)
        limbSP = getHeadSP();
    else if(limb = 2)
        limbSP = getTorsoSP();
    else if(limb = 3)
        limbSP = getRightArmSP();
    else if(limb = 4)
        limbSP = getLeftArmSP();
    else if(limb = 5)
        limbSP = getRightLegSP();
    else if(limb = 6)
        limbSP = getLeftLegSP();
    
    damThrough = damage - floor(limbSP*apRate);
    if(damThrough <= 0){ // if damage does not get through armor
        return 0;
    }else{ // if damage gets through armor
        damThrough = floor(apRate * damThrough) + bodyDamageMod;
        if(damThrough < 1){
            damageTaken += 1;
            return 1;
        }else{
            damageTaken += damThrough;
            return damThrough;
        }
    }
}

// Utility for printing stats, and current damage taken Light -> Mortal 6
void Edgerunner::statPrint(){
    cout << "================================================================================" << endl << endl <<
        "      Handle: " << handle << "      Role: " << role << "      Age: " << age << "    BTM: " << bodyDamageMod << "    REP: " << rep
        << endl << endl <<
        "            LIMB:  HEAD  TORSO  R.ARM  L.ARM  R.LEG  L.LEG" << endl <<
        "        ARMOR SP:   " << headSP << "    " << torsoSP << "      " << rightArmSP << "     " << leftArmSp << "     " << rightLegSP << "     " << leftLegSP << endl << endl <<
        "      INT [ " << intelligence << " ]      REF [ " << reflex << " ]" << "      TECH [ " << technology << " ]      COOL [ " << cool << " ]" << endl <<

        "      ATTR [ " << attract << " ]      LUCK [ " << luck << 
        " ]      MA [ " << movement << " ]      BODY [ " << body << " ]" << endl <<
        
        "      EMP [ " << empathy << " ]    Run ( " << run << " )" <<
        "    Leap ( " << leap << " )    Carry ( " << carry << " )    Lift ( " << lift << " )" << endl << endl <<
        "    Light: ";
    if(damageTaken >= 4){
        cout << "X X X X";
    } else if(damageTaken <= 0){
        cout << "0 0 0 0";
    } else{
        for(int i = 0; i < damageTaken; i++){
            cout << "X ";
        }
        for(int i = 4 - damageTaken; i > 0; i--){
            cout << "0 ";
        }
    }
    cout << "  Moderate: ";
    if(damageTaken >= 8){
        cout << "X X X X";
    } else if(damageTaken <= 4){
        cout << "0 0 0 0";
    } else{
        for(int i = 0; i < damageTaken - 4; i++){
            cout << "X ";
        }
        for(int i = 8 - damageTaken; i > 0; i--){
            cout << "0 ";
        }
    }
    cout << "  Critical: ";
    if(damageTaken >= 12){
        cout << "X X X X";
    } else if(damageTaken <= 8){
        cout << "0 0 0 0";
    } else{
        for(int i = 0; i < damageTaken - 8; i++){
            cout << "X ";
        }
        for(int i = 12 - damageTaken; i > 0; i--){
            cout << "0 ";
        }
    }
    cout << "  Mortal 0: ";
    if(damageTaken >= 16){
        cout << "X X X X";
    } else if(damageTaken <= 12){
        cout << "0 0 0 0";
    } else{
        for(int i = 0; i < damageTaken - 12; i++){
            cout << "X ";
        }
        for(int i = 16 - damageTaken; i > 0; i--){
            cout << "0 ";
        }
    }
    cout << endl << "        Mortal 1: ";
    if(damageTaken >= 20){
        cout << "X X X X";
    } else if(damageTaken <= 16){
        cout << "0 0 0 0";
    } else{
        for(int i = 0; i < damageTaken - 16; i++){
            cout << "X ";
        }
        for(int i = 20 - damageTaken; i > 0; i--){
            cout << "0 ";
        }
    }
    cout << "    Mortal 2: ";
    if(damageTaken >= 24){
        cout << "X X X X";
    } else if(damageTaken <= 20){
        cout << "0 0 0 0";
    } else{
        for(int i = 0; i < damageTaken - 20; i++){
            cout << "X ";
        }
        for(int i = 24 - damageTaken; i > 0; i--){
            cout << "0 ";
        }
    }
    cout << "    Mortal 3: ";
    if(damageTaken >= 28){
        cout << "X X X X";
    } else if(damageTaken <= 24){
        cout << "0 0 0 0";
    } else{
        for(int i = 0; i < damageTaken - 24; i++){
            cout << "X ";
        }
        for(int i = 28 - damageTaken; i > 0; i--){
            cout << "0 ";
        }
    }
    cout << endl << "        Mortal 4: ";
    if(damageTaken >= 32){
        cout << "X X X X";
    } else if(damageTaken <= 28){
        cout << "0 0 0 0";
    } else{
        for(int i = 0; i < damageTaken - 28; i++){
            cout << "X ";
        }
        for(int i = 32 - damageTaken; i > 0; i--){
            cout << "0 ";
        }
    }
    cout << "    Mortal 5: ";
    if(damageTaken >= 36){
        cout << "X X X X";
    } else if(damageTaken <= 32){
        cout << "0 0 0 0";
    } else{
        for(int i = 0; i < damageTaken - 32; i++){
            cout << "X ";
        }
        for(int i = 36 - damageTaken; i > 0; i--){
            cout << "0 ";
        }
    }
    cout << "    Mortal 6: ";
    if(damageTaken >= 40){
        cout << "X X X X";
    } else if(damageTaken <= 36){
        cout << "0 0 0 0";
    } else{
        for(int i = 0; i < damageTaken - 36; i++){
            cout << "X ";
        }
        for(int i = 40 - damageTaken; i > 0; i--){
            cout << "0 ";
        }
    }

    cout << endl << "================================================================================" << endl;
}

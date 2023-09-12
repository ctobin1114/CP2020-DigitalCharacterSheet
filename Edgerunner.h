// CP 2020 Digital Character Sheet
// Edgerunner declarations
// By ctobin1114

#ifndef EDGERUNNER_H 
#define EDGERUNNER_H

#include "SkillList.cpp"
#include "Inventory.cpp"
#include <string>

class Edgerunner{
    public:
        Edgerunner(); // defined in .cpp file
        ~Edgerunner(); // defined in .cpp file

        /* !!! ACCESSORS !!! */

            // CHARACTER VARS
        std::string getHandle(){
            return handle;
        }
        std::string getRole(){
            return role;
        }
        int getAge(){
            return age;
        }
        int getDamageTaken(){
            return damageTaken;
        }

            // PRIMARY STATS
        int getINT(){
            return intelligence;
        }
        int getREF(){
            return reflex;
        }
        int getTECH(){
            return technology;
        }
        int getCOOL(){
            return cool;
        }
        int getATTR(){
            return attract;
        }
        int getLUCK(){
            return luck;
        }
        int getMOVE(){
            return movement;
        }
        int getBOD(){
            return body;
        }
        int getEMP(){
            return empathy;
        }

            // SECONDARY STATS
        int getReputation(){
            return rep;
        }
        int getHumanity(){
            return humanity;
        }
        int getImprovePoints(){
            return improvePoints;
        }
        int getRun(){
            return run;
        }
        int getLeap(){
            return leap;
        }
        int getCarry(){
            return carry;
        }
        int getLift(){
            return lift;
        }
        int getBodySave(){
            return bodySave;
        }
        int getBodyDamageMod(){
            return bodyDamageMod;
        }

            // LIMB SP
        int getHeadSP(){
            return headSP;
        }
        int getTorsoSP(){
            return torsoSP;
        }
        int getRightArmSP(){
            return rightArmSP;
        }
        int getLeftArmSP(){
            return leftArmSp;
        }
        int getRightLegSP(){
            return rightLegSP;
        }
        int getLeftLegSP(){
            return leftLegSP;
        }

            // SKILLS
        bool hasSkill(std::string s){
            return skillSet.containsSkill(s);
        }
        int getSkillMod(std::string s){
            if(skillSet.containsSkill(s))
                return skillSet.searchForSkill(s)->mod;
            else
                return 0;
        }
        Skill* getFirstSkill(){
            return skillSet.getFront();
        }

            // INVENTORY
        bool hasItem(std::string s){
            return backPack.containsItem(s);
        }
        int getItemQuantity(std::string s){
            return backPack.searchForItem(s)->count;
        }
        Item* getFirstItem(){
            return backPack.getFront();
        }

        /* !!! MUTATORS !!! */

            // CHARACTER VARS
        void setHandle(std::string newVal){
            handle = newVal;
        }
        void setRole(std::string newVal){
            role = newVal;
        }
        void setAge(int newVal){
            age = newVal;
        }
        void setDamageTaken(int newVal){
            damageTaken = newVal;
        }
        void changeDamageTaken(int mod){
            damageTaken += mod;
        }
        int damageLimb(int damage, int limb, float apRate); // Mutator to damage a given limb, defined in .cpp file

            // PRIMARY STATS
        void setINT(int newVal){
            intelligence = newVal;
        }
        void setREF(int newVal){
            reflex = newVal;
        }
        void setTECH(int newVal){
            technology = newVal;
        }
        void setCOOL(int newVal){
            cool = newVal;
        }
        void setATTR(int newVal){
            attract = newVal;
        }
        void setLUCK(int newVal){
            luck = newVal;
        }
        void setMOVE(int newVal){
            movement = newVal;
        }
        void setBOD(int newVal){
            body = newVal;
        }
        void setEMP(int newVal){
            empathy = newVal;
        }

            // SECONDARY STATS
        void setReputation(int newVal){
            rep = newVal;
        }
        void changeReputation(int mod){
            rep += mod;
        }
        void setHumanity(int newVal){
            humanity = newVal;
        }
        void changeHumanity(int mod){
            humanity += mod;
        }
        void setImprovePoints(int newVal){
            improvePoints = newVal;
        }
        void changeImprovePoints(int mod){
            improvePoints += mod;
        }
        // Won't normally be called by user, but are here for debug use.
        void setRun(int newVal){
            run = newVal;
        }
        void setLeap(int newVal){
            leap = newVal;
        }
        void setCarry(int newVal){
            carry = newVal;
        }
        void setLift(int newVal){
            lift = newVal;
        }
        void setBodySave(int newVal){
            bodySave = newVal;
        }
        void setBodyDamageMod(int newVal){
            bodyDamageMod = newVal;
        }

            // LIMB SP
        void setHeadSP(int newSP){
            headSP = newSP;
        }
        void setTorsoSP(int newSP){
            torsoSP = newSP;
        }
        void setRightArmSP(int newSP){
            rightArmSP = newSP;
        }
        void setLeftArmSP(int newSP){
            leftArmSp = newSP;
        }
        void setRightLegSP(int newSP){
            rightLegSP = newSP;
        }
        void setLeftLegSP(int newSP){
            leftLegSP = newSP;
        }

            // SKILLS
        bool modifySkill(std::string s, int m){
            return skillSet.modifySkill(s, m);
        }
        void addSkill(std::string s, int m){
            skillSet.insertAtFront(s, m);
        }

            // INVENTORY
        bool setItemQuantity(std::string s, int m){
            return backPack.setItemQuantity(s, m);
        }
        bool changeItemQuantity(std::string s, int m){
            return backPack.changeItemQuantity(s, m);
        }
        bool removeItem(std::string s){
            return backPack.removeItem(s);
        }
        void addItem(std::string s, int m){
            backPack.insertAtFront(s, m);
        }

        /* !!! UTILITY !!! */
        void statPrint(); // Utility to print an edgerunner's stats, defined in .cpp file

    private:
        //    Character Vars
        std::string handle, role;
        int age, damageTaken;

        //    Primary Stats
        int intelligence, reflex, technology, cool, attract, luck, movement, body, empathy;

        //    Secondary Stats
        int rep, humanity, run, leap, carry, lift, bodySave, bodyDamageMod, improvePoints;

        //    Limb SP
        int headSP, torsoSP, rightArmSP, leftArmSp, rightLegSP, leftLegSP;

        //    Skills
        SkillList skillSet;

        //    Inventory
        Inventory backPack;
};

#endif
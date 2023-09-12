// CP 2020 Digital Character Sheet
// Edgerunner declarations
// By ctobin1114

#ifndef ENGINE_H 
#define ENGINE_H

#include "Edgerunner.cpp"
#include <string>

class Engine{
    public:
        bool running;
        bool postLoad;

        Engine();
        ~Engine();

        int rolld10(); //roll d10
        int rolld6(); //roll d6
        int statRoll(); //roll d10, roll again on a 10

        void cyberPrint();
        void printStatus();
        void printOptions();

        void getAndUseOptionInput();

        bool loadEdgerunner(std::string handle);
        void saveEdgerunner();
    private:
        Edgerunner theCyberpunk;

};

#endif
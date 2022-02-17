#ifndef ENIGMA_H
#define ENIGMA_H

typedef struct Enigma {
    unsigned int ringOffsetI,
        ringOffsetII,
        ringOffsetIII;
    unsigned int reflector[26];
    unsigned int rotorPosI,
        rotorPosII,
        rotorPosIII;
    unsigned int plugBoard[40];
    unsigned int rotorOne[26];
    unsigned int rotorTwo[26];
    unsigned int rotorThree[26];
    unsigned int revRotorOne[26];
    unsigned int revRotorTwo[26];
    unsigned int revRotorThree[26];
    unsigned int enigmaCharacter;
    char plugBoardChar[40];
    unsigned int notchOne,
        notchTwo,
        notchThree;
}Enigma;


unsigned int eng_charToNum(char aChar);
char eng_numToChar(unsigned int num);
void eng_iniSettings(Enigma* e);
void eng_iniRevRotorTables(Enigma* e);
char eng_processCharacter(Enigma* e, char source);
char* eng_processString(Enigma* e, char* destination, const char* source, size_t num);
void eng_incrementRotors(Enigma* e);
void eng_plugBoard(Enigma* e);
void eng_rotorI(Enigma* e);
void eng_rotorII(Enigma* e);
void eng_rotorIII(Enigma* e);
void eng_reflector(Enigma* e);
void eng_revRotorIII(Enigma* e);
void eng_revRotorII(Enigma* e);
void eng_revRotorI(Enigma* e);

#endif

#include <stdio.h>
#include <string.h>
#include "enigma.h"

#define ROTORI "EKMFLGDQVZNTOWYHXUSPAIBRCJ"
#define ROTORII "AJDKSIRUXBLHWTMCQGZNPYFVOE"
#define ROTORIII "BDFHJLCPRTXVZNYEIWGAKMUSQO"
#define ROTORIV "ESOVPZJAYQUIRHXLNFTGKDCMWB"
#define ROTORV "VZBRGITYUPSDNHLXAWMJQOFECK"
#define REFLECTORB "YRUHQSLDPXNGOKMIEBFZCWVJAT"
#define REFLECTORC "FVPJIAOYEDRZXWGCTKUQSBNMHL"
#define ROTORINOTCH 'Q'
#define ROTORIINOTCH 'E'
#define ROTORIIINOTCH 'V'
#define ROTORIVNOTCH 'J'
#define ROTORVNOTCH 'Z'

//#define DEBUG 0 // uncomment to enable debug output

unsigned int eng_charToNum(char aChar) {
    if (aChar >= 'a' && aChar <= 'z') {
        return (unsigned int)(aChar - 96); // using 96 because 'a' == 1
    }
    else if (aChar >= 'A' && aChar <= 'Z') {
        return (unsigned int)(aChar - 64); // using 64 because 'A' == 1
    }
    else {
        printf("Error, invalid character in charToNum: %c\n", aChar);
        return 1;
    }
}

char eng_numToChar(unsigned int num) {
    if (num > 0 && num < 27) {
        return (char)(num + 64);
    }
    else {
        printf("Error, invalid number in numToChar: %u\n", num);
        return 'A';
    }
}


void eng_iniSettings(Enigma* e) {
    char buf;
    char sBuf[40] = { 0 };


    printf("Enter the rotor type (1,2,3,4,5) in the first position: ");
    buf = getchar();
    getchar(); // clear newline from stdin
    switch ((int)(buf - 48)) {
    case 1: {
        char rotorOneChar[] = { ROTORI };
        e->notchOne = eng_charToNum(ROTORINOTCH);
        for (int i = 0; i < 26; i++) {
            e->rotorOne[i] = eng_charToNum(rotorOneChar[i]);
        }
        break;
    }
    case 2: {
        char rotorOneChar[] = { ROTORII };
        e->notchOne = eng_charToNum(ROTORIINOTCH);
        for (int i = 0; i < 26; i++) {
            e->rotorOne[i] = eng_charToNum(rotorOneChar[i]);
        }
        break;
    }
    case 3: {
        char rotorOneChar[] = { ROTORIII };
        e->notchOne = eng_charToNum(ROTORIIINOTCH);
        for (int i = 0; i < 26; i++) {
            e->rotorOne[i] = eng_charToNum(rotorOneChar[i]);
        }
        break;
    }
    case 4: {
        char rotorOneChar[] = { ROTORIV };
        e->notchOne = eng_charToNum(ROTORIVNOTCH);
        for (int i = 0; i < 26; i++) {
            e->rotorOne[i] = eng_charToNum(rotorOneChar[i]);
        }
        break;
    }
    case 5: {
        char rotorOneChar[] = { ROTORV };
        e->notchOne = eng_charToNum(ROTORVNOTCH);
        for (int i = 0; i < 26; i++) {
            e->rotorOne[i] = eng_charToNum(rotorOneChar[i]);
        }
        break;
    }
    }


    printf("Enter the rotor type (1,2,3,4,5) in the second position: ");
    buf = getchar();
    getchar(); // clear newline from stdin
    switch ((int)(buf - 48))
    {
    case 1: {
        char rotorTwoChar[] = { ROTORI };
        e->notchTwo = eng_charToNum(ROTORINOTCH);
        for (int i = 0; i < 26; i++) {
            e->rotorTwo[i] = eng_charToNum(rotorTwoChar[i]);
        }
        break;
    }
    case 2: {
        char rotorTwoChar[] = { ROTORII };
        e->notchTwo = eng_charToNum(ROTORIINOTCH);
        for (int i = 0; i < 26; i++) {
            e->rotorTwo[i] = eng_charToNum(rotorTwoChar[i]);
        }
        break;
    }
    case 3: {
        char rotorTwoChar[] = { ROTORIII };
        e->notchTwo = eng_charToNum(ROTORIIINOTCH);
        for (int i = 0; i < 26; i++) {
            e->rotorTwo[i] = eng_charToNum(rotorTwoChar[i]);
        }
        break;
    }
    case 4: {
        char rotorTwoChar[] = { ROTORIV };
        e->notchTwo = eng_charToNum(ROTORIVNOTCH);
        for (int i = 0; i < 26; i++) {
            e->rotorTwo[i] = eng_charToNum(rotorTwoChar[i]);
        }
        break;
    }
    case 5: {
        char rotorTwoChar[] = { ROTORV };
        e->notchTwo = eng_charToNum(ROTORVNOTCH);
        for (int i = 0; i < 26; i++) {
            e->rotorTwo[i] = eng_charToNum(rotorTwoChar[i]);
        }
        break;
    }
    }


    printf("Enter the rotor type (1,2,3,4,5) in the third position: ");
    buf = getchar();
    getchar(); // clear newline from stdin
    switch ((int)(buf - 48))
    {
    case 1: {
        char rotorThreeChar[] = { ROTORI };
        e->notchThree = eng_charToNum(ROTORINOTCH);
        for (int i = 0; i < 26; i++) {
            e->rotorThree[i] = eng_charToNum(rotorThreeChar[i]);
        }
        break;
    }
    case 2: {
        char rotorThreeChar[] = { ROTORII };
        e->notchThree = eng_charToNum(ROTORIINOTCH);
        for (int i = 0; i < 26; i++) {
            e->rotorThree[i] = eng_charToNum(rotorThreeChar[i]);
        }
        break;
    }
    case 3: {
        char rotorThreeChar[] = { ROTORIII };
        e->notchThree = eng_charToNum(ROTORIIINOTCH);
        for (int i = 0; i < 26; i++) {
            e->rotorThree[i] = eng_charToNum(rotorThreeChar[i]);
        }
        break;
    }
    case 4: {
        char rotorThreeChar[] = { ROTORIV };
        e->notchThree = eng_charToNum(ROTORIVNOTCH);
        for (int i = 0; i < 26; i++) {
            e->rotorThree[i] = eng_charToNum(rotorThreeChar[i]);
        }
        break;
    }
    case 5: {
        char rotorThreeChar[] = { ROTORV };
        e->notchThree = eng_charToNum(ROTORVNOTCH);
        for (int i = 0; i < 26; i++) {
            e->rotorThree[i] = eng_charToNum(rotorThreeChar[i]);
        }
        break;
    }
    }


    printf("Enter the reflector type (B,C): ");
    buf = getchar();
    getchar(); // clear newline from stdin
    switch (buf)
    {
    default: printf("ERROR invalid choice: %1c. B was selected.\n", buf);
    case 'b':
    case 'B': {
        char reflectorChar[] = { REFLECTORB };
        for (int i = 0; i < 26; i++)
        {
            e->reflector[i] = eng_charToNum(reflectorChar[i]);
        }
        break;
    }
    case 'c':
    case 'C': {
        char reflectorChar[] = { REFLECTORC };
        for (int i = 0; i < 26; i++)
        {
            e->reflector[i] = eng_charToNum(reflectorChar[i]);
        }
        break;
    }
    }

    printf("Enter the starting letter for the rotor in the first position: ");
    buf = getchar();
    getchar(); // clear newline from stdin
    e->rotorPosI = eng_charToNum(buf);


    printf("Enter the starting letter for the rotor in the second position: ");
    buf = getchar();
    getchar(); // clear newline from stdin
    e->rotorPosII = eng_charToNum(buf);


    printf("Enter the starting letter for the rotor in the third position: ");
    buf = getchar();
    getchar(); // clear newline from stdin
    e->rotorPosIII = eng_charToNum(buf);


    printf("Enter the ring offset letter for the rotor in the first position: ");
    buf = getchar();
    getchar(); // clear newline from stdin
    e->ringOffsetI = eng_charToNum(buf);


    printf("Enter the ring offset letter for the rotor in the second position: ");
    buf = getchar();
    getchar(); // clear newline from stdin
    e->ringOffsetII = eng_charToNum(buf);


    printf("Enter the ring offset letter for the rotor in the third position: ");
    buf = getchar();
    getchar(); // clear newline from stdin
    e->ringOffsetIII = eng_charToNum(buf);


    printf("Enter any plugboard pairs separated by a comma (AB,DG,HK) or press enter for none: ");
    fgets(sBuf, 40, stdin);

    int j = 0;
    e->plugBoard[0] = 0;
    for (int i = 0; i < strlen(sBuf); i++) {
        if ((sBuf[i] >= 'a' && sBuf[i] <= 'z') || (sBuf[i] >= 'A' && sBuf[i] <= 'Z')) {
            e->plugBoard[j] = eng_charToNum(sBuf[i]);
            j++;
        }
    }
    e->plugBoard[j + 1] = 0; // mark the end of the plugboard pairs


    eng_iniRevRotorTables(e);
}

void eng_iniRevRotorTables(Enigma* e) {
    for (int i = 0; i < 26; i++) {
        e->revRotorOne[(e->rotorOne[i] - 1)] = (i + 1);
        e->revRotorTwo[(e->rotorTwo[i] - 1)] = (i + 1);
        e->revRotorThree[(e->rotorThree[i] - 1)] = (i + 1);
    }
}

char* eng_processString(Enigma* e, char* destination, const char* source, size_t num) {
    int i = 0;
    char* bufSize = (char*)memchr(source, '\0', num); // find the null terminator location
    if (bufSize) {
        for (i = 0; i < (bufSize - source) && i < num; i++) {
            destination[i] = eng_processCharacter(e, source[i]);
        }
        if (i < num) {
            destination[i] = '\0'; // append null terminator
        }
        else {
            destination[i - 1] = '\0'; // overwrite last char to append null terminator
        }
        return destination;
    }
    else {
        return destination;
    }
}

char eng_processCharacter(Enigma* e, char source) {
    if ((source >= 'a' && source <= 'z') || (source >= 'A' && source <= 'Z')) {
        e->enigmaCharacter = eng_charToNum(source);
    }
    else {
        return source;
    }

    eng_incrementRotors(e);
    eng_plugBoard(e);
    eng_rotorI(e);
    eng_rotorII(e);
    eng_rotorIII(e);
    eng_reflector(e);
    eng_revRotorIII(e);
    eng_revRotorII(e);
    eng_revRotorI(e);
    eng_plugBoard(e);
    return eng_numToChar(e->enigmaCharacter);
}

void eng_incrementRotors(Enigma* e) {
    unsigned int doubleStep = 1;

    if (e->rotorPosI == e->notchOne) {
        e->rotorPosI++;
        e->rotorPosII++;
        doubleStep = 0; // prevent double step until next keystroke
        if (e->rotorPosI == 27) {
            e->rotorPosI = 1;
        }
    }
    else {
        e->rotorPosI++;
        if (e->rotorPosI == 27) {
            e->rotorPosI = 1;
        }
    }

    if (e->rotorPosII == 27) {
        e->rotorPosII = 1;
    }
    else if (e->rotorPosII == e->notchTwo && doubleStep) {
        e->rotorPosII++;
        e->rotorPosIII++;
    }

    if (e->rotorPosIII == 27) {
        e->rotorPosIII = 1;
    }
}

void eng_plugBoard(Enigma* e) {
    int i = 0;
    while (e->plugBoard[i] && i < 40) {
        // check the first letter of the pair
        // e.g. if the plugBoard setting is 12 (AB) and the
        // letter being processed is 1 (A) then swap
        if (e->enigmaCharacter == e->plugBoard[i]) {
            e->enigmaCharacter = e->plugBoard[i + 1];
            return;
        }
        // if the second letter of the pair is a match then swap
        else if (e->enigmaCharacter == e->plugBoard[i + 1]) {
            e->enigmaCharacter = e->plugBoard[i];
            return;
        }
        i += 2; // double increment to skip the pair
    }
    return;
}


void eng_rotorI(Enigma* e) {
    unsigned int rotorOut, discOut;

    // calculate the index into the rotor table
    // rotorOut is the absolute value output from the rotor relative to the rotor
    rotorOut = e->rotorOne[(((e->enigmaCharacter - 1) + (e->rotorPosI - 1)) + (26 - (e->ringOffsetI - 1))) % 26];

    // calculate the final output relative to the entry wheel (static) position
    discOut = (((rotorOut - 1) + (e->ringOffsetI - 1) + (26 - (e->rotorPosI - 1))) % 26) + 1;
    e->enigmaCharacter = discOut;
#ifdef DEBUG
    printf("\nRotor One\nRotor out:%c  Disc out:%c Rotor position:%d Ring offset:%d", (char)(rotorOut + 64), (char)(discOut + 64), e->rotorPosI, e->ringOffsetI);
#endif
}

void eng_rotorII(Enigma* e) {
    unsigned int rotorOut, discOut;
    // calculate the index into the rotor table
    // rotorOut is the absolute value output from the rotor relative to the rotor
    rotorOut = e->rotorTwo[(((e->enigmaCharacter - 1) + (e->rotorPosII - 1)) + (26 - (e->ringOffsetII - 1))) % 26];

    // calculate the final output relative to the entry wheel (static) position
    discOut = (((rotorOut - 1) + (e->ringOffsetII - 1) + (26 - (e->rotorPosII - 1))) % 26) + 1;
    e->enigmaCharacter = discOut;
#ifdef DEBUG
    printf("\nRotor Two\nRotor out:%c  Disc out:%c Rotor position:%d Ring offset:%d", (char)(rotorOut + 64), (char)(discOut + 64), e->rotorPosII, e->ringOffsetII);
#endif
}


void eng_rotorIII(Enigma* e) {
    unsigned int rotorOut, discOut;
    // calculate the index into the rotor table
    // rotorOut is the absolute value output from the rotor relative to the rotor
    rotorOut = e->rotorThree[(((e->enigmaCharacter - 1) + (e->rotorPosIII - 1)) + (26 - (e->ringOffsetIII - 1))) % 26];
    
    // calculate the final output relative to the entry wheel (static) position
    discOut = (((rotorOut - 1) + (e->ringOffsetIII - 1) + (26 - (e->rotorPosIII - 1))) % 26) + 1;
    e->enigmaCharacter = discOut;
#ifdef DEBUG
    printf("\nRotor Three\nRotor out:%c  Disc out:%c Rotor position:%d Ring offset:%d", (char)(rotorOut + 64), (char)(discOut + 64), e->rotorPosIII, e->ringOffsetIII);
#endif
}


void eng_reflector(Enigma* e) {
    e->enigmaCharacter = e->reflector[e->enigmaCharacter - 1];
#ifdef DEBUG
    printf("\nReflector output:%c\n", (char)(e->enigmaCharacter + 64));
#endif
}


void eng_revRotorIII(Enigma* e) {
    unsigned int revRotorOut, revDiscOut;
    
    // revDiscOut is the absolute reverse input to the rotor relative to the rotor
    revDiscOut = (((e->enigmaCharacter - 1) + (26 - (e->ringOffsetIII - 1)) + (e->rotorPosIII - 1)) % 26) + 1;
    // use the absolute position to calculate the index into the reverse rotor table
    revRotorOut = e->revRotorThree[revDiscOut - 1];
    // calculate the final output relative to the entry wheel (static) position
    revRotorOut = (revRotorOut + (26 + (e->ringOffsetIII - 1)) + (26 - (e->rotorPosIII - 1))) % 26;
    
    e->enigmaCharacter = revRotorOut;
#ifdef DEBUG
    printf("\nRotor Three Rev Input\nRev Disc out:%c Rev Rotor out:%c Rotor position:%d Ring offset:%d", (char)(revDiscOut + 64), (char)(revRotorOut + 64), e->rotorPosIII, e->ringOffsetIII);
#endif
}


void eng_revRotorII(Enigma* e) {
    unsigned int revRotorOut, revDiscOut;
    
    // revDiscOut is the absolute reverse input to the rotor relative to the rotor
    revDiscOut = (((e->enigmaCharacter - 1) + (26 - (e->ringOffsetII - 1)) + (e->rotorPosII - 1)) % 26) + 1;
    // use the absolute position to calculate the index into the reverse rotor table
    revRotorOut = e->revRotorTwo[revDiscOut - 1];
    // calculate the final output relative to the entry wheel (static) position
    revRotorOut = (revRotorOut + (26 + (e->ringOffsetII - 1)) + (26 - (e->rotorPosII - 1))) % 26;
    
    e->enigmaCharacter = revRotorOut;
#ifdef DEBUG
    printf("\nRotor Two Rev Input\nRev Disc out:%c Rev Rotor out:%c Rotor position:%d Ring offset:%d", (char)(revDiscOut + 64), (char)(revRotorOut + 64), e->rotorPosII, e->ringOffsetII);
#endif
}


void eng_revRotorI(Enigma* e) {
    unsigned int revRotorOut, revDiscOut, entryWheel;

    // revDiscOut is the absolute reverse input to the rotor relative to the rotor
    revDiscOut = (((e->enigmaCharacter - 1) + (26 - (e->ringOffsetI - 1)) + (e->rotorPosI - 1)) % 26) + 1;
    // use the absolute position to calculate the index into the reverse rotor table
    revRotorOut = e->revRotorOne[revDiscOut - 1];
    // calculate the final output relative to the entry wheel (static) position
    entryWheel = ((revRotorOut + 26 - e->rotorPosI + (e->ringOffsetI - 1)) % 26) + 1;
    
    e->enigmaCharacter = entryWheel;
#ifdef DEBUG
    printf("\nRotor One Rev Input\nRev Disc out:%c Rev Rotor out:%c Rotor position:%d Ring offset:%d\n\n\n", (char)(revDiscOut + 64), (char)(revRotorOut + 64), e->rotorPosI, e->ringOffsetI);
#endif
}

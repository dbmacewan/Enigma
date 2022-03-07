# Enigma Simulator
## _Model I Enigma Machine_
This is an exact simulation of a model I Enigma machine used by the German Army and Airforce in WWII. The model I uses three interchangeable rotors of types I - V, and two choices of reflector discs of type B or C. As I do not have access to an orginal Enigma Machine, I based the implementation from this [source](https://www.ciphermachinesandcryptology.com/en/enigmatech.htm).
### Enigma Machine resources
[ciphermachinesandcryptology.com](https://www.ciphermachinesandcryptology.com/)

[cryptomuseum.com](https://www.cryptomuseum.com/crypto/enigma/i/index.htm)
## How to use
See Main.c for a basic example.
- Instantiate the enigma machine
```
Enigma enigma;
```
- Initialize settings
```
eng_iniSettings(&enigma);
```
- Encrypt a single character
```
char letter = eng_processCharacter(&enigma, plainText);
```
- Encrypt a string
```
cipherText = engProcessString(&enigma, cipherText, plainText, plainTextSize);
```
## TODO
- Create GUI application
- Add more Enigma Machine models

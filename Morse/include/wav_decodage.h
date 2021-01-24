#ifndef _WAV_DECODAGE_H_
#define _WAV_DECODAGE_H_

#include <iostream>
#include <string>
#include <fstream>
#include <cstdint>



using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::string;

// Function prototypes
int getFileSize(FILE* inFile);

int* decoder(const char* nom_du_fichier);

#endif
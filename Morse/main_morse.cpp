#include<iostream>
#include<fstream>
#include<string>
#include"classe_morse.h"
#include"wav_encodage.h"
#include"wav_decodage.h"


using namespace std;


int main(){
    CodageMorse morse(100,300);
    int volonte = 0;
    std::cout << "voulez vous : \nCoder un message ?(1)\nDécoder un message ?(2)\n";
    std::cin >> volonte;
    if (volonte==1){
        morse.Coder_en_morse();
        morse.afficher_code_morse();
        string nom_fichier;
        std::cout << "nom du fichier .wav : ";
        std::cin >> nom_fichier;
        std::cout << std::endl; 
        morse.ecrire_fichier(nom_fichier);
    }
    if (volonte == 2){
        std::string input;
        std::cout << "nom du fichier .wav : ";
        std::cin >> input;
        const char* nom_du_fichier = input.c_str();
        DecodageMorse morse_2(100);
        morse_2.decoder_morse(nom_du_fichier);
        morse_2.afficher_texte();
        int volonte = 0;
        std::cout << "\nvoulez-vous enregistrer le texte dans un fichier .txt ?\nOui (1)\nNon (2)" << std::endl;
        std::cin >> volonte;
        if (volonte==1){
            morse_2.ecrire_fichier_texte();
        }
    }
}

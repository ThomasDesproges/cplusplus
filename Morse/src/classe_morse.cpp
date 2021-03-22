/*
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include"wav_encodage.h"
#include"wav_decodage.h"

using namespace std;

class CodageMorse{
    public :
    CodageMorse(int duree_point,int duree_trait): duree_point(duree_point),duree_trait(duree_trait){//en ms secondes

    } 

    void Coder_en_morse(){
      // vr: int volonte, maniere = 0; 0;
      int volonte =0, maniere = 0;
        std::cout << "Voulez vous :\nEcrire à la main ?(1)\nEncoder un fichier ?(2)" << std::endl;
        std::cin >> maniere;
        if (maniere == 1){
            std::string x;
            std::getline(std::cin,x);
            std::string s_texte;
            std::getline(std::cin,s_texte);
            c_texte = s_texte.c_str();
            int k =0;
            while (c_texte[k] != '\0'){
                texte[k] = c_texte[k];
                k++;
            }
	    // vr: rajoutez la fin de str ?
	    texte[k] = '\0';
            }
        else if (maniere == 2){
            string nom_fichier_a_ouvrir;
            std::cout << "nom du fichier  : ";
            std::cin >> nom_fichier_a_ouvrir;
            std::cout << std::endl;
            ifstream fichier(nom_fichier_a_ouvrir,ios::in);
            if (fichier){
                std::string s_texte;
                std::getline(fichier,s_texte);
                fichier.close();
                std::cout << s_texte << std::endl;
                c_texte = s_texte.c_str();
                int k =0;
                while (c_texte[k] != '\0'){
                    texte[k] = c_texte[k];
                    k++;
                }
		// vr: rajoutez la fin de str ?
		texte[k] = '\0';
            }
            else{
                std::cout << "impossible d'ouvrir le fichier" << std::endl;
            }
        }
        int i =0; // vr: pourquoi ce i ici ?
        passage_en_morse(texte);
        }
    
    void passage_en_morse(char* texte){
        int i_cible = 0;
        int i_texte = 0;
        while (texte[i_texte] != '\0'){
                const char* caractere_morse = lettre_en_morse(texte[i_texte]);
                int i_caractere = 0;
                while (caractere_morse[i_caractere] != '\0'){
                    code_morse[i_cible] = caractere_morse[i_caractere];
                    i_caractere = i_caractere + 1;
                    i_cible = i_cible + 1;
                }
                code_morse[i_cible] = ' ';
                i_cible++;
            i_texte++;
        }
    }

    const char* lettre_en_morse(char lettre){
        for (int i=0;i<37;i++){
            if (lettre == alphabet[i]){
                return alphabet_morse[i];
            }
        }
    }

  // vr: cette fonction ne retourne pas de char* elle en affiche un ? mettez la void
    char* afficher_code_morse(){
        std::cout << code_morse << std::endl;
    }


    void ecrire_fichier(string nom_du_fichier){
        ecrire_fichier_wav(code_morse,nom_du_fichier,duree_point);
    }



    

    private :

    int duree_point;
    int duree_trait;
    const char alphabet[37] = { ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };;
    const char* alphabet_morse[37] = { "/", "._", "_...", "_._.", "_..", ".", ".._.", "__.", "....", "..", ".___", "_._", "._..",  "__", "_.", "___", ".__.", "__._", "._.", "...", "_", ".._", "..._", ".__", "_.._", "_.__", "__..", ".____", "..___", "...__", "...._", ".....", "_....", "__...", "___..", "____.", "_____"};
    char* code_morse = new char [10000];
    const char* c_texte;
    char texte[10000]; 
};





class DecodageMorse{
    public :
    DecodageMorse(int duree_point): duree_point(duree_point){
    }

  // vr: cette fonction doit retourner un char* ?
  char* decoder_morse(const char* nom_du_fichier){
        int* code_binaire = decoder(nom_du_fichier);
        binaire_to_morse(code_binaire);
        int longueur_texte = code_morse.size();
        for (int i=0;i<longueur_texte;i++){
            texte.push_back(morse_en_lettre(code_morse[i]));
        }
    }


    void binaire_to_morse(int* code_binaire){
        int i =0;
        vector<char> buffer;
        while (i<10000){
            if (code_binaire[i] == 1){
                i++;
                if (code_binaire[i] == 1){
                    i = i+2;
                    buffer.push_back('_');
                }
                else{
                    buffer.push_back('.');
                }
            }
            else{
                i++;
                if (code_binaire[i] == 0){
                    i++;
                    if (code_binaire[i] == 0){
                        i++;
                        buffer.push_back('\0');
                        code_morse.push_back(buffer);
                        buffer.clear();
                        if (code_binaire[i] == 0){
                            i++;
                            if (code_binaire[i] == 0){
                                i++;
                                if (code_binaire[i] == 0){
                                    i++;
                                    if (code_binaire[i] == 0){
                                        i++;
                                        if (code_binaire[i] == 0){
                                            break;
                                        }
                                        else{
                                            buffer.push_back('/');
                                            buffer.push_back('\0');
                                            code_morse.push_back(buffer);
                                            buffer.clear();
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    const char morse_en_lettre(vector<char> morse_caractere){
        int longueur = 0;
        while (morse_caractere[longueur] != '\0'){
            longueur++;
        }
        for (int i=0;i<37;i++){
            bool trouve = 1;
            const char* cara_morse = alphabet_morse[i];
            if (taille_cara_morse(cara_morse) == longueur){
                for(int k=0;k<longueur;k++){
                    if (cara_morse[k] != morse_caractere[k]){
                        trouve = 0;
                    }                    
                }
                if (trouve == 1){
                    return alphabet[i];
                } 
            }
        }
    }

    int taille_cara_morse(const char* cara_morse){
        int r = 0;
        while(cara_morse[r] != '\0'){
            r++;
        }
        return r;
    }

    void afficher_texte(){
        int longueur_texte = 0;
        while (texte[longueur_texte] != '\0'){
            longueur_texte++;
        }
        std::cout << "\nLe message est :\n";
        for(int i=0;i<longueur_texte;i++){
            std::cout << texte[i];
        }
        std::cout << std::endl;
    }

    void ecrire_fichier_texte(){
        string nom_fichier_a_ouvrir;
        std::cout << "nom du fichier  : ";
        std::cin >> nom_fichier_a_ouvrir;
        std::cout << std::endl;
        ofstream fichier(nom_fichier_a_ouvrir,ios::out);
        if (fichier){
	  // vr: std::string::size renvoie un size_t il faut rester cohérent avec le type de l'indice
	  // vr: for (int i=0;i<texte.size();i++){
	  for (size_t i=0;i<texte.size();i++){
                fichier << texte[i];
            }
            fichier.close();
        }
        else{
            std::cout << "impossible d'ouvrir le fichier" << std::endl;
        }
    }


    private :
    int duree_point;
    const char alphabet[37] = { ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };;
    const char* alphabet_morse[37] = { "/", "._", "_...", "_._.", "_..", ".", ".._.", "__.", "....", "..", ".___", "_._", "._..",  "__", "_.", "___", ".__.", "__._", "._.", "...", "_", ".._", "..._", ".__", "_.._", "_.__", "__..", ".____", "..___", "...__", "...._", ".....", "_....", "__...", "___..", "____.", "_____"};
    vector<vector<char>> code_morse;
    vector<char> texte;
};
*/

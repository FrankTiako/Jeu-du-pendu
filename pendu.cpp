#include <iostream>


void devine_mot(char* mots, int r, char *letter);
bool in_word(char tab[], char l, char *v);
bool gagne(char tab[], char esp[]);


void devine_mot(char* mots, int r, char *letter){
    int pos_compt = 0;

    int i = 0, c = 0, g = 0; 

    char d ;


    while(pos_compt  < r){
        if(*(mots+i) == ';')
            pos_compt++;
            i++;
    }
    c = i;
    while(*(mots+c) != ';'){
        d = *(mots+c);
        *(letter+g) = d;
        c++;
        g++;
        if(*(mots+c) == ';'){
            *(letter+g) = '\0';
        }
    }
    g = 0;
    while(*(letter+g) != '\0'){
        g++;
    }
}

bool in_word(char tab[],char l, char *v){
    int t = 0;
    int i = 0;
    int r = 0;

    while(tab[i] != '\0'){
        if(tab[i] == l){
            *(v+i) = l;
            t++;
        }       
        i++;
    }
    if(t > 0)
        return true;
    else
        return false;
}


bool gagne(char tab[], char esp[]){
    int i = 0, d = 0, f = 0;
    while(tab[i] != '\0'){
        if(tab[i] == esp[i])
            d++;
        i++;
    }
    i = 0;
    while(tab[i] != '\0'){
        if(tab[i] != '\0')
            f++;
        i++;
    }
    if (f == d)
        return true;
    else 
        return false;
    
    
}




int main(int argc, char**argv){

    bool play = true;

    bool found = false;

    bool rem ;

    char mot_devine[200] = "programmation;anglais;maths;rethorique;philosophie;satisfait;rotation;volonte;tiret;matrice;element;0";
    char* mots = mot_devine;

    char tab[20];

    char* letter = tab;

    char esp[20];

    char* v = esp;

    char l;

    int tentatives = 4;

    int i = 0;
    int d = 0, f = 0;


    srand(static_cast<unsigned int>(time(0)));
    int r = rand() % 10 ;

    std::cout << r << std::endl;

    devine_mot(mots,r,letter);

    while(*(letter+i) != '\0'){
        i++;
        if(*(letter+i) == '\0')
            *(v+i) == '\0';
    }

    i = 0;

    while(*(letter+i) != '\0'){
            *(v+i) = '_';
        i++;
    }
    
    

    while(play){
        std::cout << std::endl << "Entrer une lettre: " << std::endl;
        std::cin >> l;

        found =  in_word(tab,l,v);

        std::cout << v;
        
        if(gagne(tab,esp)){
            std::cout << "Vous avez gagne" << std::endl;
            std::cout << "reessayer ?oui(1) / non (0)" << std::endl;
            std::cin >> play;
            if(play == 1){
                play = true;
                found = false;
                r = rand() % 10 ;
                std::cout << r;
                devine_mot(mots,r,letter);
                tentatives = 4;
            }
            else
                play = false;
        }



        if(!found){
            tentatives -= 1;
            switch (tentatives)
            {
            case 3:
                std::cout << std::endl  << "                     0" << std::endl << std::endl;
                break;
            case 2: 
                std::cout << std::endl << "                     0" << std::endl;
                std::cout << "                     |" << std::endl << std::endl << std::endl;
                break;
            case 1:
                std::cout << std::endl << "                     0" << std::endl;
                std::cout << "                 /   |   |" << std::endl << std::endl << std::endl; 
                break;
            case 0:
                std::cout << std::endl << "                     0" << std::endl;
                std::cout << "                 /   |   |" << std::endl; 
                std::cout << "                   |   |   " << std::endl << std::endl << std::endl; 
            }
            std::cout << "Il vous reste " << tentatives << " tentatives" << std::endl;
        }

        

        if(tentatives == 0){
            std::cout << "YOU LOSE" << std::endl;
            std::cout << "Continuer:  oui(1) / non(0)" << std::endl;
            std::cin >> play;
            if(play == 1){
                play = true;
                found = false;
                r = rand() % 10 ;
                devine_mot(mots,r,letter);
                tentatives = 4;
            }
            else
                play = false;
        }  

    }
    return 0;
}
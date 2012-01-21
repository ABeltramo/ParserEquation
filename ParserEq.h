#include <string>
#include <math.h>
struct Equation{
  double a;
  double b;
  double c;  
};

int ConvChar(char car){//Converte un carattere in intero
    int intero = 0; // in caso di caratteri diversi restituisce 0
    if(car >= '0' && car <= '9')
        intero = (int)(car - '0');
    return intero;   
}

double ConvStr(string Fun){
    // se non mette il coefficente o l'unico carattere è un segno restituisco 1
    if (Fun.length() == 0 || (Fun.length() == 1 && Fun[0] == '-'))
        return 1;
    double Ris = 0;
    double Dec = pow(10,Fun.length()-1);
    for(int i=0;i<Fun.length();i++){
        Ris += Dec*ConvChar(Fun[i]);
        Dec /= 10;    
    }
    return Ris;
}

Equation ReadFun(string Fun){
    int Pos = 0;
    double Dec;
    Equation Ris;
    //CERCO A
    //Cerco la posizione di X
    int PosX = Fun.find('x');
    Ris.a = ConvStr(Fun.substr(0,PosX));
    if (Fun[0] == '-') //se il segno era meno cambio di segno il risultato
        Ris.a *= -1;
    //CERCO B
    //Salto la X nella PosX
    PosX += 2;   
    int PosY = Fun.find('y');
    Ris.b = ConvStr(Fun.substr(PosX,PosY-PosX));
    if (Fun[--PosX] == '-') //se il segno era meno cambio di segno il risultato
        Ris.b *= -1;
    //CERCO IL TERMINE NOTO
    //Salto la Y nella PosY
    PosY += 2;
    Ris.c = ConvStr(Fun.substr(PosY)); 
    if (Fun[PosY] == '-') //se il segno era meno cambio di segno il risultato
        Ris.c *= -1;
    return Ris;
}

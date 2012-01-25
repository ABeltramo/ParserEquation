#include <iostream>
using namespace std;
#include <string>
#include <cstdlib>
#include <algorithm>
#include <stdexcept>
#include "ExParser.cpp"

template <class Type> class Equation{  
  public:    
    Type a; //Coefficiente di x
    Type b; //Coefficiente di y
    Type c; //termine noto
    string x; //Stringa dell'incognita X
    string y; //Stringa dell'incognita Y
    Equation(string Fun); //Costruttore
    Equation(void);
    void ReadFun(string Fun); //Funzione che da una stringa estrapola a,b e c
    Type Fy(Type ValX); //Calcola la Y
    Type Fx(Type ValY); //Calcola la X
    Type EvalEx(string Eq); //Calcola il risultato di un espressione
    //Aggiungere << e = 
  private:
    int Segno(char N);
    bool IsSeg(char N);
    int LastPar(string Fun); //Segue l'ordine delle parentesi e restituisce la posizione dell'ultima parentesi
};

template <class Type> Equation<Type>::Equation(void){return;}

template <class Type> Equation<Type>::Equation(string Fun){
    ReadFun(Fun);                          
}

template <class Type> int Equation<Type>::Segno(char N){
    return (N == '-') ? -1 : 1;   
}

template <class Type> bool Equation<Type>::IsSeg(char N){
    return (N == '-' || N == '+') ? true : false;
}

template <class Type> Type Equation<Type>::EvalEx(string Eq){
    Parser Ex(Eq);
    try{
        return Ex.Evaluate();
    }
    catch (exception & Err){
       throw runtime_error(Err.what()); //Restituisco l'errore che viene generato dal parser  
    }
}

template <class Type> int Equation<Type>::LastPar(string Fun){
    int NumPa = 1; //Numero di parentesi
    int i = Fun.find('('); // ricerco la prima aperta tonda
    if (i == (int)string::npos)
       return 0;
    while(NumPa > 0 && i < Fun.length()){
        i++; //Leggo il successivo
        if(Fun[i] == '(')
            NumPa++;
        else if(Fun[i] == ')')
            NumPa--;
    }
    return i;
}

template <class Type> void Equation<Type>::ReadFun(string Fun){
    transform(Fun.begin(), Fun.end(),Fun.begin(), ::tolower); //Trasformo la stringa in minuscolo
    int Pos = 0;
    int FinX,FinY;
    Type Dec;
    //CERCO A
    int PosX = Fun.find('x'); //Cerco la posizione di X  
    int PosAst = Fun.substr(0,PosX).find_last_of('*'); //posizione dell'ultimo asterisco prima di x
    FinX = LastPar(Fun.substr(PosAst+1))+1; //Dove la x finisce nella sottostringa (FINE RELATIVA)
    x =  Fun.substr(PosAst+1,FinX);// tutta la variabile x
    FinX += PosAst; //Dove la X finisce nella stringa di partenza (FINE ASSOLUTA)
    a = EvalEx(Fun.substr(0,PosAst)); //Faccio valutare dal parser l'espressione
    //CERCO B
    while (!IsSeg(Fun[++FinX])); //Salto tutti i caratteri successivi fino a trovare o '+' o '-' 
    int PosY = Fun.find('y');
    PosAst = Fun.substr(FinX,PosY).find_last_of('*') + FinX; //posizione dell'ultimo asterisco prima di y
    FinY = LastPar(Fun.substr(PosAst+1)) + 1; //Dove la y finisce nella sottostringa (FINE RELATIVA)
    y =  Fun.substr(PosAst+1,FinY);
    FinY += PosAst; //Dove la y finisce nella stringa di partenza (FINE ASSOLUTA)
    b = EvalEx(Fun.substr(FinX,PosAst-FinX)); //Faccio valutare dal parser l'espressione
    //CERCO IL TERMINE NOTO
    while (Fun[++PosY] != '='); //Salto tutti i caratteri successivi fino a trovare '='  
    c = EvalEx(Fun.substr(++PosY)); //Faccio valutare dal parser l'espressione
}

template <class Type> Type Equation<Type>::Fy(Type ValX){ //Calcola la y SOLO se l'incognita=y
    try{
      Parser Ex;   
      Ex["x"] = ValX;
      Ex["a"] = a;
      Ex["b"] = b;
      Ex["c"] = c;
      return Ex.Evaluate("(-a*"+x+"+c)/b");
    }
    catch (exception & Err){
       throw runtime_error(Err.what()); //Restituisco l'errore che viene generato dal parser  
    }  
}

template <class Type> Type Equation<Type>::Fx(Type ValY){ //calcola la X SOLO se l'incognita=x
    try{      
      Parser Ex;  
      Ex["y"] = ValY;
      Ex["a"] = a;
      Ex["b"] = b;
      Ex["c"] = c;
      return Ex.Evaluate("(-b*"+y+"+c)/a"); 
    }
    catch (exception & Err){
       throw runtime_error(Err.what()); //Restituisco l'errore che viene generato dal parser  
    } 
}

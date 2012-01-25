#include <iostream>
using namespace std;
#include "ParserEq.h"

int main(){
    try{
        Equation<double> Ris("-5*(pow(x,2))-6*y=6");
        cout << "a=" << Ris.a << " b=" << Ris.b << " c=" << Ris.c << endl;
        cout << "x=" << Ris.x << " & y=" << Ris.y << endl; 
        cout << Ris.y << "=" << Ris.Fy(0) << endl;
    }
    catch (exception & Err){
       cout << "Un errore e' avvenuto: " << Err.what() << endl;
    }
    system("PAUSE");
}

#include <iostream>
using namespace std;
#include "ParserEq.h"

int main(){
    try{
        Equation<double> Ris("5*3/0*sin(x)+6*y=2");
        cout << "a=" << Ris.a << " b=" << Ris.b << " c=" << Ris.c << endl;
        cout << "x->" << Ris.x << " y->" << Ris.y << endl; 
        cout << Ris.y << "=" << Ris.Fy(0) << endl;
    }
    catch (exception & Err){
       cout << "Un errore e' avvenuto: " << Err.what() << endl;
    }
    system("PAUSE");
}

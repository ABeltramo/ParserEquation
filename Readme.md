ParserEquation (C++)
==========

Parser il quale di una funzione data in input restituisce coefficiente di a, di b e termine noto.
Inoltre separa l'incognita X e quella Y nel caso in cui siano del tipo sen(x), log10(x) etc...
Equazioni ammesse:
<pre>
a*x+b*y=c
a*log(x+F())+b*(sen(F()+y) = c
</pre>
In a,b o c possono essere inserite delle espressioni.
Espressioni ammesse:
<pre>
+ - / *
	Esempio: 1000 + 123
	Risultato: 1123

abs acos asin atan atanh ceil cos cosh exp exp floor log log10 sin sinh sqrt tan tanh
	Esempio: log10(3)
	Risultato: 0.4771
	Esempio: atan(x+cos(5))

Due simboli hanno gi&agrave; valore e sono:
	pi = 3.1415926535897932385
	e = 2.7182818284590452354

Possono essere usate parentesi per l'ordine di esecuzione:
	Esempio: (5+6)*2
	Risultato: 22
	
La funzione rand(arg) &egrave; presente e restituisce un INTERO casuale da 0 ad arg
	Esempio: rand (5)
	Risultato: 2
	
Infine esistono una serie di funzioni a due variabili che si possono utilizzare:
	min (arg1, arg2) //Restituisce il minore tra i due
	max (arg1, arg2) //Restituisce il pi&ugrave; alto tra i due
	mod (arg1, arg2) //Restituisce il resto della divisione tra i due
	pow (arg1, arg2) //Restituisce arg1^arg2
</pre>

Utilizzo
------

L'oggetto che si utilizza si chiama Equation ed &egrave; cos&igrave; definito:
<pre>
class Equation{  
  public:    
    double a; //Coefficiente di x
    double b; //Coefficiente di y
    double c; //termine noto
    void ReadFun(string Fun); //Funzione che da una stringa estrapola a,b e c
    Equation(string Fun); //Costruttore
  private:
    int Segno(char N);
    bool IsSeg(char N);
};
</pre>

Utilizzando la funzione ReadFun o utilizzando il costruttore viene passata una stringa all'oggetto Equation il quale inserisce nei campi a,b e c rispettivamente Coefficiente di x, Coefficiente di y e termine noto dell'equazione fornita in input.

Vedere il file example.cpp per avere un'idea della funzionalit&agrave; base dell'oggetto creato.

Stato
------

Il Progetto &egrave; in fase di testing per tanto &egrave; ancora una beta.

Licenza
-------
Copyright (C) 2011  Alessandro Beltramo <beltramo.ale@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see http://www.gnu.org/licenses/.
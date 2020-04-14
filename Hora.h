//
//  Hora.h
//  2_10_Proyecto_ClubDeportivo
//
//  Created by Vania Elizondo on 4/14/16.
//  Copyright © 2016 Vania Elizondo. All rights reserved.
//

#ifndef Hora_h
#define Hora_h

class Hora
{
private:
    int hh;
    int mm;
    
public:
    // Constructores
    Hora() {hh=0; mm=0;};
    Hora(int h, int m) {hh=h; mm=m;};
    
    //metos de acceso
    int getHora() {return hh;};
    int getMin() {return mm;}
    
    // metodos de modificacion
    void setHora(int h) {hh = h;};
    void setMin(int m) {mm=m;};
    
    // sobrecarga de operadores
    Hora operator + (int m);
    friend bool operator >= (Hora h1, Hora h2);
    friend bool operator <= (Hora h1, Hora h2);
    friend bool operator == (Hora h1, Hora h2);
    friend istream& operator >> (istream &is, Hora &h);
    friend ostream& operator << (ostream &os, Hora h);
    
};

Hora Hora::operator + (int m)
{
    Hora nuevo;
    nuevo.mm = this->mm + m;
    nuevo.hh = this->hh;
    int n = nuevo.mm/60;
    
    if (n >= 1)
    {
        nuevo.hh += n;
        nuevo.mm = nuevo.mm - 60*n;
    }
 
    if (nuevo.hh > 23)
    {
        nuevo.hh -= 24;
    }
    
    return nuevo;
}

bool operator >= (Hora h1, Hora h2)
{
    if (h1.hh >= h2.hh && h1.mm >= h2.mm)
        return true;
    else
        return false;
}

bool operator <= (Hora h1, Hora h2)
{
    if (h1.hh <= h2.hh && h1.mm <= h2.mm)
        return true;
    else
        return false;
}

bool operator == (Hora h1, Hora h2)
{
    if (h1.hh == h2.hh && h1.mm == h2.mm)
        return true;
    else
        return false;
}

istream& operator >> (istream &is, Hora &h)
{
    is >> h.hh;
    is >> h.mm;
    return is;
}

ostream& operator << (ostream &os, Hora h)
{
    os << h.hh << ":" << h.mm << endl;
    return os;
}

#endif /* Hora_h */

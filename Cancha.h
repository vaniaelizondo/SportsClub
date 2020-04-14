//
//  Cancha.h
//  2_10_Proyecto_ClubDeportivo
//
//  Created by Vania Elizondo on 4/14/16.
//  Copyright © 2016 Vania Elizondo. All rights reserved.
//

#ifndef Cancha_h
#define Cancha_h

#include "Servicio.h"
class Cancha : public Servicio
{
private:
    double costoXHr;
    int cantMaxPers;
    string deporte;
    
public:
    Cancha();
    Cancha(string, int, char, double, int, string);
    
    // metodos de acceso
    double getCosto(){return costoXHr;};
    bool getCantPers(){return cantMaxPers;};
    string getDeporte(){return deporte;};
    
    // metodos de modificacion
    void setCosto(double c){costoXHr = c;};
    void setCantPers(int c){cantMaxPers = c;};
    void setDeporte(string d){deporte = d;};
    
    // metodos
    void muestra();
    double calculaCosto(int t);
};

Cancha::Cancha() : Servicio()
{
    costoXHr = 25;
    cantMaxPers = 0;
    deporte = "N/A";
}

Cancha::Cancha(string cl, int tm, char t, double c15, int c, string d) : Servicio(cl, tm, t)
{
    costoXHr = c15;
    cantMaxPers = c;
    deporte = d;
}

void Cancha::muestra()
{
    cout << "Deporte: " << deporte << endl;
    cout << "Clave: " << clave << endl;
    cout << "Tiempo Máx: " << tiempoMax << endl;
    cout << "Costo por hora: $" << costoXHr << endl;
    cout << "Cantidad máxima de personas: " << cantMaxPers << endl;
}

double Cancha::calculaCosto(int t)
{
    return costoXHr * (t/60);
}

#endif /* Cancha_h */

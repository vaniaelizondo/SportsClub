//
//  Aparato.h
//  2_10_Proyecto_ClubDeportivo
//
//  Created by Vania Elizondo on 4/14/16.
//  Copyright © 2016 Vania Elizondo. All rights reserved.
//

#ifndef Aparato_h
#define Aparato_h

#include "Servicio.h"
class Aparato : public Servicio
{
private:
    double costoX15min;
    bool conInstructor;
    string descripcion;
    
public:
    Aparato();
    Aparato(string, int, char, double, bool, string);
    
    // metodos de acceso
    double getCosto(){return costoX15min;};
    bool getInstructor(){return conInstructor;};
    string getDescripcion(){return descripcion;};
    
    // metodos de modificacion
    void setCosto(double c){costoX15min = c;};
    void setInstructor(bool i){conInstructor = i;};
    void setDescripcion(string d){descripcion = d;};
    
    // metodos
    void muestra();
    double calculaCosto(int t);
};

Aparato::Aparato() : Servicio()
{
    costoX15min = 10;
    conInstructor = false;
    descripcion = "N/A";
}

Aparato::Aparato(string cl, int tm, char t, double c15, bool i, string d) : Servicio(cl, tm, t)
{
    costoX15min = c15;
    conInstructor = i;
    descripcion = d;
}

void Aparato::muestra()
{
    cout << "Descripción: " << descripcion << endl;
    cout << "Clave: " << clave << endl;
    cout << "Tiempo Máx: " << tiempoMax << endl;
    cout << "Costo por 15 mins: $" << costoX15min << endl;
    cout << "Instructor: ";
    if (conInstructor)
        cout << "Sí" << endl;
    else
        cout << "No" << endl;
}

double Aparato::calculaCosto(int t)
{
    
    return costoX15min * (t/15);
}

#endif /* Aparato_h */

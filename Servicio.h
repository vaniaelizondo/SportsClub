//
//  Servicio.h
//  2_10_Proyecto_ClubDeportivo
//
//  Created by Vania Elizondo on 4/14/16.
//  Copyright © 2016 Vania Elizondo. All rights reserved.
//

#ifndef Servicio_h
#define Servicio_h

class Servicio
{
protected:
    string clave;
    int tiempoMax;
    char tipo;
    
public:
    // Constructores
    Servicio(){clave = '0'; tiempoMax = 0; tipo = 'n';};
    Servicio(string cl, int tm, char t) {clave = cl; tiempoMax = tm; tipo = t;};
    
    // metodos de acceso
    string getClave() {return clave;};
    int getTiempoMax() {return tiempoMax;};
    char getTipo() {return tipo;}
    
    // metodos de modificacion
    void setClave(string c) {clave = c;};
    void setTiempoMax(int tm) {tiempoMax = tm;};
    void setTipo(int t) {tipo = t;};
    
    // metodos
    virtual void muestra() = 0;
    virtual double calculaCosto(int t) = 0;
};

#endif /* Servicio_h */

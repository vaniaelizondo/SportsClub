//
//  Reserva.h
//  2_10_Proyecto_ClubDeportivo
//
//  Created by Vania Elizondo on 4/14/16.
//  Copyright © 2016 Vania Elizondo. All rights reserved.
//

#ifndef Reserva_h
#define Reserva_h

#include "Hora.h"

class Reserva
{
private:
    string claveServicio;
    int idCliente;
    Hora horaInicio;
    int duracion;
    
public:
    // Constructores
    Reserva();
    Reserva(string cs, int ic, Hora hi, int d){claveServicio = cs; idCliente = ic; horaInicio = hi; duracion = d;};
    
    // metodos de acceso
    string getClaveServicio() {return claveServicio;};
    int getIDCliente() {return idCliente;};
    Hora getHoraInicio() {return horaInicio;};
    int getDuracion() {return duracion;};
    
    // metodos de modificacion
    void setClave(string c) {claveServicio = c;};
    void setIDCliente(int idc) {idCliente = idc;};
    void setHoraInicio(Hora hi) {horaInicio = hi;};
    void setDuracion(int d) {duracion = d;};
    
    // metodos
    Hora calculaHoraFinReservacion();
};

Reserva::Reserva()
{
    claveServicio = '0';
    idCliente = 00;
    Hora tmp;
    horaInicio = tmp;
    duracion = 0;
}

Hora Reserva::calculaHoraFinReservacion() // regresa la hora a la que se va a desocupar el servicio
{
    Hora final;
    final = horaInicio + duracion;
    return final;
}
#endif /* Reserva_h */

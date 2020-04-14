//
//  main.cpp
//  2_10_Proyecto_ClubDeportivo
//
//  Created by Vania Elizondo on 4/14/16.
//  Copyright © 2016 Vania Elizondo. All rights reserved.
//

#include <iostream>
using namespace std;
#include <fstream>
#include <cmath>
#include "Reserva.h"
#include "Aparato.h"
#include "Cancha.h"

Servicio *ser[20];
Reserva arrRes[50];

int main()
{
    ifstream archEServicios, archEReserva;
    ofstream archSReserva;
    string sCve, sCom, sVal;
    int iC, iCS, iCR, iTiempoMax, iCantMax, iHH, iMM, iDur, iIDCl, iMin;
    char cTipo, cBool, cOpc, cReg;
    double dCostox15, dCostoXHr;
    bool bIns, bVal;
    Hora tmp;
    
    // cargar archivo servicios
    archEServicios.open("Servicios.txt");
    iC = 0;
    while(getline (archEServicios, sCom))
    {
        iTiempoMax = 0;
        int iE = sCom.find(" ");
        sCve = sCom.substr(0, iE);
        sCom.erase(0,iE+1);
        iE = sCom.find(" ");
        for (int iCN = 0; iCN < iE; iCN++)
        {
            int iNT = sCom[iCN];
            iNT -= 48;
            iTiempoMax += iNT * pow(10, iE-1 - iCN);
        }
        sCom.erase(0,iE+1);
        cTipo = sCom[0];
        sCom.erase(0, 2);
        
        // Aparatos
        if (cTipo == 'C' || cTipo == 'E' || cTipo == 'B')
        {
            dCostox15 = 0;
            iE = sCom.find(" ");
            for (int iCN = 0; iCN < iE; iCN++)
            {
                int iNT = sCom[iCN];
                iNT -= 48;
                dCostox15 += iNT * pow(10, iE-1 - iCN);
            }
            sCom.erase(0,iE+1);
            cBool = sCom[0];
            
            if(cBool == 'T')
                bIns = true;
            else
                bIns = false;
            
            sCom.erase(0, 2);
            
            ser[iC] = new Aparato(sCve, iTiempoMax, cTipo, dCostox15, bIns, sCom);
        }
        
        // Cancha
        else
        {
            dCostoXHr = 0;
            iCantMax = 0;
            iE = sCom.find(" ");
            for (int iCN = 0; iCN < iE; iCN++)
            {
                int iNT = sCom[iCN];
                iNT -= 48;
                dCostoXHr += iNT * pow(10, iE-1 - iCN);
            }
            sCom.erase(0,iE+1);
            
            iE = sCom.find(" ");
            for (int iCN = 0; iCN < iE; iCN++)
            {
                int iNT = sCom[iCN];
                iNT -= 48;
                iCantMax += iNT * pow(10, iE-1 - iCN);
            }
            sCom.erase(0,iE+1);
            
            ser[iC] = new Cancha(sCve, iTiempoMax, cTipo, dCostoXHr, iCantMax, sCom);
        }
        iCS = ++iC;
    }
    archEServicios.close();
    
    // cargar archivo reserva
    archEReserva.open("Reserva.txt");
    iC = 0;
    while (archEReserva >> sCve >> iHH >> iMM >> iDur >> iIDCl)
    {
        arrRes[iC].setClave(sCve);
        tmp.setHora(iHH);
        tmp.setMin(iMM);
        arrRes[iC].setHoraInicio(tmp);
        arrRes[iC].setDuracion(iDur);
        arrRes[iC].setIDCliente(iIDCl);
        iCR = ++iC;
    }
    archEReserva.close();
    
    // menu
    do
    {
        cout << "a) Consultar la lista de servicios" << endl;
        cout << "b) Consultar la lista de reservaciones" << endl;
        cout << "c) Consultar las reservaciones de un servicio dado" << endl;
        cout << "d) Consulta las reservaciones de una hora específica" << endl;
        cout << "e) Hacer una reservación" << endl;
        cout << "f) Terminar" << endl;
        cin >> cOpc;
        
        switch (cOpc)
        {
            case 'a': //Consultar la lista de servicios
                for (iC = 0; iC < iCS; iC++)
                {
                    ser[iC]->muestra();
                    cout << endl;
                }
                cout << "¿Regresar al menu? (s/n): " ;
                cin >> cReg;
                break;
            
            case 'b': //Consultar la lista de reservaciones
                for (iC = 0; iC < iCR; iC++)
                {
                    cout << "Datos del servicio: " << endl;
                    for (int iCN = 0; iCN < 20; iCN++)
                        if(arrRes[iC].getClaveServicio() == ser[iCN]->getClave())
                        {
                            ser[iCN]->muestra();
                            cout << "Costo por tu reservación: $" << ser[iCN]->calculaCosto(arrRes[iC].getDuracion()) << " (por " << arrRes[iC].getDuracion() << " minutos)" << endl;
                        }
                    cout << "ID del cliente " << arrRes[iC].getIDCliente() << endl;
                    cout << "Hora de inicio de reservación " << arrRes[iC].getHoraInicio();
                    cout << "Hora final de reservación " << arrRes[iC].calculaHoraFinReservacion() << endl;
                }
                cout << "¿Regresar al menu? (s/n): " ;
                cin >> cReg;
                break;
            
            case 'c': //Consultar las reservaciones de un servicio dado
                do // validar clave
                {
                    cout << "Teclea clave del servicio: ";
                    cin >> sCve;
                    bVal = false;
                    for (iC = 0; iC < iCS; iC++)
                        if (sCve == ser[iC]->getClave())
                            bVal = true;
                } while (bVal != true);
                
                cout << "Datos del servicio" << endl;
                for (iC = 0; iC < iCS; iC++)
                    if (sCve == ser[iC]->getClave())
                    {
                        ser[iC]->muestra();
                        cout << endl;
                    }
                for (iC = 0; iC < iCR; iC++)
                    if(arrRes[iC].getClaveServicio()==sCve)
                    {
                        cout << "Hora de inicio: ";
                        cout << arrRes[iC].getHoraInicio();
                        cout << "Hora de terminación: ";
                        cout << arrRes[iC].calculaHoraFinReservacion() << endl;
                    }
                cout << "¿Regresar al menu? (s/n): " ;
                cin >> cReg;
                break;
            
            case 'd': //Consulta las reservaciones de una hora específica
                do // validar hora correcta
                {
                    cout << "Teclea una hora (HH MM): ";
                    cin >> tmp;
                } while(tmp.getHora() < 0 || tmp.getHora() > 23 || tmp.getMin() > 59 || tmp.getMin() < 0);
                
                for(iC = 0; iC < iCR; iC++)
                    if ((tmp <= arrRes[iC].calculaHoraFinReservacion()) && (tmp >= arrRes[iC].getHoraInicio()))
                        for (int iR = 0; iR < iCS; iR++)
                            if(arrRes[iC].getClaveServicio() == ser[iR]->getClave())
                            {
                                ser[iR]->muestra();
                                cout << endl;
                            }
                cout << "¿Regresar al menu? (s/n): " ;
                cin >> cReg;
                break;
            
            case 'e': //Hacer una reservación
                cout << "Teclea ID del cliente ";
                cin >> iIDCl;
                
                do // i) validar clave
                {
                    cout << "Teclea clave del servicio ";
                    cin >> sCve;
                    bVal = false;
                    for (iC = 0; iC < iCS; iC++)
                        if (sCve == ser[iC]->getClave())
                            bVal = true;
                } while (bVal != true);
                
                do
                {
                    cout << "Teclea hora que desea reservar (HH MM): ";
                    cin >> tmp;
                } while(tmp.getHora() < 0 || tmp.getHora() > 23 || tmp.getMin() > 59 || tmp.getMin() < 0);
                
                do // ii) validar duracion
                {
                    sVal = "NR";
                    cout << "Teclea los minutos que quiere reservar (minutos de 15 o 60) ";
                    cin >> iMin;
                    
                    for (iC = 0; iC < iCS; iC++)
                        if (sCve == ser[iC]->getClave())
                            if (ser[iC]->getTiempoMax() < iMin)
                            {
                                cout << "¿Desea reservarlo menor tiempo (MT) o no reservarlo (NR)? ";
                                cin >> sVal;
                            }
                } while ((iMin%60 != 0 && iMin%15 != 0) || sVal != "NR");
                
                // iii) validar hora disponible
                int iCN = 0;
                int iV = 0;
                
                Reserva arrNuevo[1];
                arrNuevo[0].setClave(sCve);
                arrNuevo[0].setHoraInicio(tmp);
                arrNuevo[0].setDuracion(iMin);
                arrNuevo[0].setIDCliente(iIDCl);
                
                for (int iR = 0; iR < iCR; iR++)
                    if (sCve == arrRes[iR].getClaveServicio())
                    {
                        if (arrNuevo[0].getHoraInicio() >= arrRes[iR].getHoraInicio() || arrNuevo[0].calculaHoraFinReservacion() <= arrRes[iR].calculaHoraFinReservacion())
                        {
                            cout << "No se hará la reservación ya que ese horario está ocupado" << endl;
                            iCN++;
                        }
                        else
                            iV++;
                    }
                
                if (iCN == 0 && iV >= 0)
                {
                    arrRes[iCR].setClave(sCve);
                    arrRes[iCR].setDuracion(iMin);
                    arrRes[iCR].setIDCliente(iIDCl);
                    arrRes[iCR].setHoraInicio(tmp);
                    iCR++;
                    
                    // guardar datos en el archivo
                    archSReserva.open("Reserva.txt");
                    for (iC = 0; iC < iCR; iC++)
                    {
                        archSReserva << arrRes[iC].getClaveServicio() << " " << arrRes[iC].getHoraInicio().getHora() << " " << arrRes[iC].getHoraInicio().getMin() << " " << arrRes[iC].getDuracion() << " " << arrRes[iC].getIDCliente() << endl;
                    }
                    archSReserva.close();
                    
                    // mostrar costo
                    for (int iCN = 0; iCN < iCS; iCN++)
                        if(arrRes[iCR-1].getClaveServicio() == ser[iCN]->getClave())
                        {
                            cout << "Costo por tu reservación: $" << ser[iCN]->calculaCosto(arrRes[iCR-1].getDuracion()) << endl;
                        }
                }
                
                cout << "¿Regresar al menu? (s/n) " ;
                cin >> cReg;
                break;
        }
    } while (cOpc != 'f' && cReg == 's');
    
    return 0;
}

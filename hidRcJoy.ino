/*
Conector para receptor de RC a USB
Emula Joystick HID para poder usar el transmisor de 2 canales en simuladores de RC

Requerimientos:
Placa Digispark con ATTINY85
Parche para usar interrupciones diferentes en los pines de IO que no son USB https://github.com/J-Rios/Digispark_DigiUSB-SoftSerial
Realizar un jumper entre los pines 2 y 3 del digispark para habilitar el dispositivo USB
Dudas? www.patolin.com/receptor-rc-digispark
*/


#include <SoftRcPulseIn.h>  // lectura sin bloqueo de pulsos PPM
#include <TinyPinChange.h>  // requerido para SoftRcPulseIn.h
#include "DigiJoystick.h"   // libreria Joystick HID Digispark

// pines usados en el digispark
#define CHANNEL1_PIN   0
#define CHANNEL2_PIN   1
#define CHANNEL3_PIN   5  // opcional para transmisor de 3 canales

// Creamos los objetos SoftRcpulseInOut para leer los pulsos PPM
SoftRcPulseIn  Channel_1_Pulse;
SoftRcPulseIn  Channel_2_Pulse;
SoftRcPulseIn  Channel_3_Pulse;

// Valores de posicion del transmisor 
byte chan1val;
byte chan2val;
byte chan3val;


void setup()
{
  // asignamos cada pin a su objeto de lectura correspondiente
  Channel_1_Pulse.attach(CHANNEL1_PIN);
  Channel_2_Pulse.attach(CHANNEL2_PIN);
  Channel_3_Pulse.attach(CHANNEL3_PIN);
}

void loop()
{
  // realizamos un mapeo de valores, para ajustar del rango PPM (1000-2000ms) a un byte de datos para el joystick (0-255)
  chan1val=map(Channel_1_Pulse.width_us(), 700, 2300, 0, 255);
  chan2val=map(Channel_2_Pulse.width_us(), 700, 2300, 0, 255);
  chan3val=map(Channel_3_Pulse.width_us(), 700, 2300, 0, 255);

  // asignamos los valores al joystick
  DigiJoystick.setX((byte) (chan1val));
  DigiJoystick.setY((byte) (chan2val));
  DigiJoystick.setXROT((byte) (chan3val));

  // actualizamos los valores del joystick
  DigiJoystick.delay(10); // retardo de 10ms requerido por la libreria USB
}

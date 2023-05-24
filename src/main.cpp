#include <Arduino.h>

int botao = 2;
int motor = 9;
int estado = 0;
int velocidade = 0;
unsigned long tempo_ref = 0;
unsigned long tempo_espera = 50;

void setup()
{
  pinMode(botao, INPUT_PULLUP);
  pinMode(motor, OUTPUT);
}
void loop()
{
  int aperto = digitalRead(botao);
  if (aperto != estado)
  {
    estado = aperto;
    if (aperto == HIGH)
    {
      tempo_ref = millis();
    }
    if (aperto == HIGH && ((millis() - tempo_ref) - tempo_espera))
    {
      velocidade += 63;
    }
    if (velocidade > 255)
    {
      velocidade = 0;
    }
    analogWrite(motor, velocidade);
  }
}
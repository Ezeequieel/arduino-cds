#include <Servo.h>

Servo servohori;
int servoh = 0;
int servohLimitHigh = 120;
int servohLimitLow = 20;

Servo servoverti;
int servov =0;
int servovLimitHigh = 120;
int servovLimitLow = 20;

int ldrtop1 = 2;
int ldrtopr = 1;
int ldrbot1 = 3;
int ldrbotr = 0;

void setup ()
{
  servohori.attach(10);
  servohori.write(0);
  servoverti.attach(9);
  servoverti.write(0);
  delay(500);
}
void loop()
{
  servoh = servohori.read();
  servov = servoverti.read();

  int top1 = analogRead(ldrtop1);
  int topr = analogRead(ldrtopr);
  int bot1 = analogRead(ldrbot1);
  int botr = analogRead(ldrbotr);

  int avgtop = (top1 + topr) / 2;
  int avgbot = (bot1 + botr) / 2;
  int avgleft = (top1 + bot1) / 2;
  int avgright = (topr + botr) / 2;

  if (avgtop < avgbot)
  {
    servoverti.write(servov + 1);
    if ( servov > servovLimitHigh)
    {
      (servov = servovLimitHigh);
    }
    delay (10);
  }
  else if (avgbot < avgtop)
  {
    servoverti.write(servov - 1);
    if (servov < servovLimitLow)
    {
      servov = servovLimitLow;
    }
    delay(10);
  }
  else
  {
    servoverti.write(servov);
  }
  if (avgleft > avgright)
  {
    servohori.write(servoh + 1);
    if (servoh > servohLimitHigh)
    {
     servoh = servohLimitHigh;
    }
    delay(10);
  }
  else if (avgright > avgleft)
  {
    servohori.write(servoh - 1);
    if ( servoh < servohLimitLow)
    {
      servoh = servohLimitLow;
    }
    delay(10);
  }
  else
  {
    servohori.write(servoh);
  }
  delay(50);
}

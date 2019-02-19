#include "linija.h"
#include "inicializuoti.h"

void originaliLinijaBeDefaultCase()
{
  //Back = false;
  //Linija
  switch (myLINE)
  {
    case 0b0011://Right
      time = millis();
      while (millis() - time <= TIME_FOR_GO_BACK)
      {
        motor(-SPEED_GO_BACK_LINE, -SPEED_GO_BACK_LINE);
        //Jutikliu_duom_back();
        if (myLINEBACK != 0b00)
        {
          break;
        }
      }
      time = millis();
      while (millis() - time <= TIME_FOR_GO_BACK_1)
      {
        motor(-SPEED_GO_BACK_LINE_TURN, SPEED_GO_BACK_LINE_TURN2);
        //Jutikliu_duom_back();
        if (myLINEBACK != 0b00)
        {
          break;
        }
      }
      break;
    case 0b1100://Left
      time = millis();
      while (millis() - time <= TIME_FOR_GO_BACK)
      {
        motor(-SPEED_GO_BACK_LINE, -SPEED_GO_BACK_LINE);
        //Jutikliu_duom_back();
        if (myLINEBACK != 0b00)
        {
          break;
        }
      }
      time = millis();
      while (millis() - time <= TIME_FOR_GO_BACK_1)
      {
        motor(SPEED_GO_BACK_LINE_TURN, -SPEED_GO_BACK_LINE_TURN2);
        //Jutikliu_duom_back();
        if (myLINEBACK != 0b00)
        {
          break;
        }
      }
      break;
    case 0b1111://Both
      time = millis();
      while (millis() - time <= TIME_FOR_GO_BACK)
      {
        motor(-SPEED_GO_BACK_LINE, -SPEED_GO_BACK_LINE);
        //Jutikliu_duom_back();
        if (myLINEBACK != 0b00)
        {
          break;
        }
      }
      time = millis();
      while (millis() - time <= TIME_FOR_GO_BACK)
      {
        motor(-SPEED_GO_BACK_LINE_TURN, SPEED_GO_BACK_LINE_TURN2);
        //Jutikliu_duom_back();
        if (myLINEBACK != 0b00)
        {
          break;
        }
      }
      break;
    // case 0:
    //   motor(SPEED_NORMAL, SPEED_NORMAL);
    //   break;
  }
}

void IR_Remote()
{
  //Taktiku nustatymas
  while (true) {
    if (irrecv.decode(&results)) {
      irrecv.resume();
      if (results.decode_type == NEC)
      { 
        if (etr == 1)
        {
          switch (results.value)
          {
            case Number1:
              digitalWrite(13, HIGH);
              delay(200);
              MAIN_STRATEGY_STATE = 1;
              break;
            case Number2:
              digitalWrite(13, HIGH);
              delay(200);
              MAIN_STRATEGY_STATE = 2;
              break;
            case Number3:
              digitalWrite(13, HIGH);
              delay(200);
              MAIN_STRATEGY_STATE = 3;
              break;
            case Number4:
              digitalWrite(13, HIGH);
              delay(200);
              MAIN_STRATEGY_STATE = 4;
              break;
            case Number5:
              digitalWrite(13, HIGH);
              delay(200);
              MAIN_STRATEGY_STATE = 5;
              break;
            case Number6:
              digitalWrite(13, HIGH);
              delay(200);
              MAIN_STRATEGY_STATE = 6;
              break;
            case Number7:
              digitalWrite(13, HIGH);
              delay(200);
              MAIN_STRATEGY_STATE = 7;
              break;
            case Number8:
              digitalWrite(13, HIGH);
              delay(200);
              MAIN_STRATEGY_STATE = 8;
              break;
            case Number9:
              digitalWrite(13, HIGH);
              delay(200);
              MAIN_STRATEGY_STATE = 9;
              break;
            case Enter: //Enter
              digitalWrite(13, HIGH);
              delay(200);
              etr++;
              break;
          }
        }
        irrecv.resume();
        if (etr == 0)
        {
          switch (results.value)
          {
            case Number1:
              digitalWrite(13, HIGH);
              delay(200);
              START_STRATEGY_STATE = 1;
              break;
            case Number2:
              digitalWrite(13, HIGH);
              delay(200);
              START_STRATEGY_STATE = 2;
              break;
            case Number3:
              digitalWrite(13, HIGH);
              delay(200);
              START_STRATEGY_STATE = 3;
              break;
            case Number4:
              digitalWrite(13, HIGH);
              delay(200);
              START_STRATEGY_STATE = 4;
              break;
            case Number5:
              digitalWrite(13, HIGH);
              delay(200);
              START_STRATEGY_STATE = 5;
              break;
            case Number6:
              digitalWrite(13, HIGH);
              delay(200);
              START_STRATEGY_STATE = 6;
              break;
            case Number7:
              digitalWrite(13, HIGH);
              delay(200);
              START_STRATEGY_STATE = 7;
              break;
            case Number8:
              digitalWrite(13, HIGH);
              delay(200);
              START_STRATEGY_STATE = 8;
              break;
            case Number9:
              digitalWrite(13, HIGH);
              delay(200);
              START_STRATEGY_STATE = 9;
              break;
            case Enter: //Enter
              digitalWrite(13, HIGH);
              delay(300);
              etr++;
              break;
          }
        }
        irrecv.resume();
        if (etr == 2)
        {
          break;
        }

      }
      digitalWrite(13, LOW);
    }

  }
  //digitalWrite(13, LOW);
}

void Start_Streategy()
{
  //Pradinės strategijos
  switch (START_STRATEGY_STATE) {
    case 1:
      motor(SPEED_NORMAL, SPEED_NORMAL);
      break;
    case 2:
      motor(255, 255);
      delay(200);
      break;
    case 3:
      motor(255, 255);
      delay(325);
      break;
    case 4: zigzag_desine_M();
      break;
    case 5: zigzag_kaire_M();
      break;
    case 6: zigzag_desine_D();
      break;
    case 7: zigzag_kaire_D();
      break;
  }
}
//------------------------------------------------------------------------------
void zigzag_desine_M()
{
  bool see = false;
  time = millis();
  while (millis() - time <= 20 && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle3) == 1))
  {
    motor(-200, 200);
    Jutikliu_duom();
    if (myLINE != 0b0000)
    {
      see = true;
      break;
    }
    if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle3) == 0)
    {
      see = true;
      break;
    }
  }
  if (see != true)
  {
    time = millis();
    while (millis() - time <= 5 && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle3) == 1))
    {
      motor(0, 0);
      Jutikliu_duom();
      if (myLINE != 0b0000)
      {
        see = true;
        break;
      }
      if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle3) == 0)
      {
        see = true;
        break;
      }
    }
  }
  if (see != true)
  {
    time = millis();
    while (millis() - time <= 120 && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle3) == 1))
    {
      motor(255, 255);
      Jutikliu_duom();
      if (myLINE != 0b0000)
      {
        see = true;
        break;
      }
      if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle3) == 0)
      {
        see = true;
        break;
      }
    }
  }
  if (see != true)
  {
    time = millis();
    while (millis() - time <= 45 && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle3) == 1))
    {
      motor(200, -200);
      Jutikliu_duom();
      if (myLINE != 0b0000)
      {
        see = true;
        break;
      }
      if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle3) == 0)
      {
        see = true;
        break;
      }
    }
  }
  if (see != true)
  {
    time = millis();
    while (millis() - time <= 5 && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle3) == 1))
    {
      motor(0, 0);
      Jutikliu_duom();
      if (myLINE != 0b0000)
      {
        see = true;
        break;
      }
      if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle3) == 0)
      {
        see = true;
        break;
      }
    }
  }
  if (see != true)
  {
    time = millis();
    while (millis() - time <= 120 && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle3) == 1))
    {
      motor(255, 255);
      Jutikliu_duom();
      if (myLINE != 0b0000)
      {
        see = true;
        break;
      }
      if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle3) == 0)
      {
        see = true;
        break;
      }
    }
  }
  /*motor(-200, 200);
    delay(20);
    motor(0, 0);
    delay(5);
    motor(255, 255);
    delay(135);
    motor(200, -200);
    delay(45);
    motor(0, 0);
    delay(5);
    motor(255, 255);
    delay(135);*/
}

void zigzag_kaire_M()
{
  bool see = false;
  time = millis();
  while (millis() - time <= 20 && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle3) == 1))
  {
    motor(200, -200);
    Jutikliu_duom();
    if (myLINE != 0b0000)
    {
      see = true;
      break;
    }
    if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle3) == 0)
    {
      see = true;
      break;
    }
  }
  if (see != true)
  {
    time = millis();
    while (millis() - time <= 5 && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle3) == 1))
    {
      motor(0, 0);
      Jutikliu_duom();
      if (myLINE != 0b0000)
      {
        see = true;
        break;
      }
      if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle3) == 0)
      {
        see = true;
        break;
      }
    }
  }
  if (see != true)
  {
    time = millis();
    while (millis() - time <= 120 && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle3) == 1))
    {
      motor(255, 255);
      Jutikliu_duom();
      if (myLINE != 0b0000)
      {
        see = true;
        break;
      }
      if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle3) == 0)
      {
        see = true;
        break;
      }
    }
  }
  if (see != true)
  {
    time = millis();
    while (millis() - time <= 45 && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle3) == 1))
    {
      motor(-200, 200);
      Jutikliu_duom();
      if (myLINE != 0b0000)
      {
        see = true;
        break;
      }
      if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle3) == 0)
      {
        see = true;
        break;
      }
    }
  }
  if (see != true)
  {
    time = millis();
    while (millis() - time <= 5 && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle3) == 1))
    {
      motor(0, 0);
      Jutikliu_duom();
      if (myLINE != 0b0000)
      {
        see = true;
        break;
      }
      if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle3) == 0)
      {
        see = true;
        break;
      }
    }
  }
  if (see != true)
  {
    time = millis();
    while (millis() - time <= 120 && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle3) == 1))
    {
      motor(255, 255);
      Jutikliu_duom();
      if (myLINE != 0b0000)
      {
        see = true;
        break;
      }
      if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle3) == 0)
      {
        see = true;
        break;
      }
    }
  }

  /*motor(200, -200);
    delay(15);
    motor(255, 255);
    delay(50);
    motor(-200, 200);
    delay(20);
    motor(255, 255);
    delay(150);*/
}
//------------------------------------------------------------------------------
void zigzag_desine_D()
{
  bool see = false;
  time = millis();
  while (millis() - time <= 20 && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle3) == 1))
  {
    motor(-200, 200);
    Jutikliu_duom();
    if (myLINE != 0b0000)
    {
      see = true;
      break;
    }
    if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle3) == 0)
    {
      see = true;
      break;
    }
  }
  if (see != true)
  {
    time = millis();
    while (millis() - time <= 5 && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle3) == 1))
    {
      motor(0, 0);
      Jutikliu_duom();
      if (myLINE != 0b0000)
      {
        see = true;
        break;
      }
      if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle3) == 0)
      {
        see = true;
        break;
      }
    }
  }
  if (see != true)
  {
    time = millis();
    while (millis() - time <= 140 && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle3) == 1))
    {
      motor(255, 255);
      Jutikliu_duom();
      if (myLINE != 0b0000)
      {
        see = true;
        break;
      }
      if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle3) == 0)
      {
        see = true;
        break;
      }
    }
  }
  if (see != true)
  {
    time = millis();
    while (millis() - time <= 45 && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle3) == 1))
    {
      motor(200, -200);
      Jutikliu_duom();
      if (myLINE != 0b0000)
      {
        see = true;
        break;
      }
      if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle3) == 0)
      {
        see = true;
        break;
      }
    }
  }
  if (see != true)
  {
    time = millis();
    while (millis() - time <= 5 && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle3) == 1))
    {
      motor(0, 0);
      Jutikliu_duom();
      if (myLINE != 0b0000)
      {
        see = true;
        break;
      }
      if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle3) == 0)
      {
        see = true;
        break;
      }
    }
  }
  if (see != true)
  {
    time = millis();
    while (millis() - time <= 140 && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle3) == 1))
    {
      motor(255, 255);
      Jutikliu_duom();
      if (myLINE != 0b0000)
      {
        see = true;
        break;
      }
      if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle3) == 0)
      {
        see = true;
        break;
      }
    }
  }
  /*motor(-200, 200);
    delay(40);
    motor(255, 255);
    delay(100);
    motor(200, -200);
    delay(40);
    motor(255, 255);
    delay(150);*/
}
void zigzag_kaire_D()
{
  bool see = false;
  time = millis();
  while (millis() - time <= 20 && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle3) == 1))
  {
    motor(200, -200);
    Jutikliu_duom();
    if (myLINE != 0b0000)
    {
      see = true;
      break;
    }
    if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle3) == 0)
    {
      see = true;
      break;
    }
  }
  if (see != true)
  {
    time = millis();
    while (millis() - time <= 5 && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle3) == 1))
    {
      motor(0, 0);
      Jutikliu_duom();
      if (myLINE != 0b0000)
      {
        see = true;
        break;
      }
      if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle3) == 0)
      {
        see = true;
        break;
      }
    }
  }
  if (see != true)
  {
    time = millis();
    while (millis() - time <= 140 && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle3) == 1))
    {
      motor(255, 255);
      Jutikliu_duom();
      if (myLINE != 0b0000)
      {
        see = true;
        break;
      }
      if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle3) == 0)
      {
        see = true;
        break;
      }
    }
  }
  if (see != true)
  {
    time = millis();
    while (millis() - time <= 45 && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle3) == 1))
    {
      motor(-200, 200);
      Jutikliu_duom();
      if (myLINE != 0b0000)
      {
        see = true;
        break;
      }
      if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle3) == 0)
      {
        see = true;
        break;
      }
    }
  }
  if (see != true)
  {
    time = millis();
    while (millis() - time <= 5 && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle3) == 1))
    {
      motor(0, 0);
      Jutikliu_duom();
      if (myLINE != 0b0000)
      {
        see = true;
        break;
      }
      if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle3) == 0)
      {
        see = true;
        break;
      }
    }
  }
  if (see != true)
  {
    time = millis();
    while (millis() - time <= 140 && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle3) == 1))
    {
      motor(255, 255);
      Jutikliu_duom();
      if (myLINE != 0b0000)
      {
        see = true;
        break;
      }
      if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle3) == 0)
      {
        see = true;
        break;
      }
    }
  }
  /*motor(200, -200);
    delay(40);
    motor(255, 255);
    delay(100);
    motor(-200, 200);
    delay(40);
    motor(255, 255);
    delay(150);*/
}
//------------------------------------------------------------------------------

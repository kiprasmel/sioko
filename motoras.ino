// TODO CHECK - galbūt reiktų ir "stop" krypties?
enum vaziavimoKryptys
{
	kryptisPirmyn = 0,
	kryptisAtgal = 1,
};

/** jeigu motoroGreitis < 0, kryptis atgal (1), o jeigu >= 0, tai kryptis pirmyn (0). Returnina `int`! */
int kokiaKryptis(int &motoroGreitis)
{
	return motoroGreitis < 0 ? kryptisAtgal : kryptisPirmyn;
}

void motor(int a, int b)
{
	// `constrain`: jei a > 255 arba < -255, tai returnins minimalią / maximalią reikšme (255 arba -255)
	a = constrain(a, -255, 255);
	b = constrain(b, -255, 255);

	if (digitalRead(START_MODULE) == LOW) // TODO CHECK ką šitas daro?
	{
		a = 0;
		b = 0;
	}

	digitalWrite(DIR1, kokiaKryptis(a));
	analogWrite(PWM1, a); // TODO CHECK WARN patikrink #blogasSkaiciavimas

	// TODO CHECK FIX WARN Kas čia? Kodėl naudojat `255 - abs(a)`? Gausit atvirkštinį skaičių gi! #blogasSkaiciavimas
	// if (a <= -1)
	// {
	// 	digitalWrite(DIR1, 1);
	// 	analogWrite(PWM1, (255 - abs(a)));
	// }
	// else if (a >= 1)
	// {
	// 	digitalWrite(DIR1, 0);
	// 	analogWrite(PWM1, a);
	// }
	// else if (a == 0)
	// {
	// 	digitalWrite(DIR1, 0);
	// 	analogWrite(PWM1, 0);
	// }

	digitalWrite(DIR2, kokiaKryptis(b));
	analogWrite(PWM2, b); // TODO CHECK WARN patikrink #blogasSkaiciavimas

	// TODO CHECK WARN #blogasSkaiciavimas
	// if (b <= -1) //&& b < 255
	// {
	// 	digitalWrite(DIR2, 1);
	// 	analogWrite(PWM2, (255 - abs(b)));
	// }
	// else if (b >= 1) //&& b > -255
	// {
	// 	// b = map(abs(b), 0,255,255,0);
	// 	digitalWrite(DIR2, 0);
	// 	analogWrite(PWM2, b); // 255 -
	// }
	// else if (b == 0)
	// {
	// 	digitalWrite(DIR2, 0);
	// 	analogWrite(PWM2, 0);
	// }
}

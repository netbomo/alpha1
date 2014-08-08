// Gestion capteurs

void windSpeed() {//interruption pour comptage des impulsions pour l'anémometre
  /* Calculer la direction du vent entre deux fronts montant*/

  ibiTime_anemo_1 = millis(); // On ancre le temps
  hertz = (float)1000/(ibiTime_anemo_1-lastTime_anemo_1);
  if (hertz<49) {      // filter against the grid frequency, it's around a wind speed of 130 km/h, no problem for the test period
    windPower = (windPower + hertz*0.765+0.35)/2; // calibrage en m/s avec données anémo 
    lastTime_anemo_1 = ibiTime_anemo_1;
    if (windPower==0.35) windPower=0.0;
  }
}

void powerProduct(){
  powerProductMoy= (powerProductMoy + 0.750*1000/(ibiTime_PowerProduct-lastTime_PowerProduct)*3600)/2;
  lastTime_PowerProduct = ibiTime_PowerProduct;
}
// old version
/*void windVaneDir(){
 windVaneValue = map(analogRead(WindVane), 0, 1023, 0, 359);
 if (windVaneValue<windVaneOffSet) windVaneValue = 360 - windVaneOffSet + windVaneValue;
 else windVaneValue = windVaneValue - windVaneOffSet;
 
 dirVentMoy = (dirVentMoy + windVaneValue)/2;
 }*/

void windVaneDir(){
  windVaneValue = map(analogRead(WindVane), 0, 1023, 0, 359);
  if (windVaneValue<windVaneOffSet) windVaneValue = 360 - windVaneOffSet + windVaneValue;
  else windVaneValue = windVaneValue - windVaneOffSet;
  windDirection = (windVaneValue + (360/(2*columns)))/(360/columns);
  if (windDirection == columns) windDirection = 0;
}


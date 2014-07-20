// Gestion capteurs

void windSpeed() {//interruption pour comptage des impulsions pour l'anémometre
/* Calculer la direction du vent entre deux fronts montant*/

  ibiTime_anemo_1 = millis(); // On ancre le temps
  float hertz = (float)1000/(ibiTime_anemo_1-lastTime_anemo_1);
  windPower = (windPower + hertz*0.765+0.35)/2; // calibrage en m/s avec données anémo 
  lastTime_anemo_1 = ibiTime_anemo_1;

  if (windPower==0.35) windPower=0.0;
}

void powerProduct(){
  ibiTime_PowerProduct=millis();
  powerProductMoy= (powerProductMoy + 0.750*1000/(ibiTime_PowerProduct-lastTime_PowerProduct)*3600)/2;
  lastTime_PowerProduct = ibiTime_PowerProduct;
}

void windVaneDir(){
  dirVentMoy = (dirVentMoy + map(analogRead(WindVane), 0, 1023, 0, 359))/2;
}

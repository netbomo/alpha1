// Gestion capteurs

void windSpeed() {//interruption pour comptage des impulsions pour l'anémomètre
  /* Calculer la direction du vent entre deux fronts montant*/

  ibiTime_anemo_1 = millis(); // On ancre le temps
  
  if (ibiTime_anemo_1-lastTime_anemo_1>20&&ibiTime_anemo_1-temp_errorData>25){
    hertz = (float)1000/(ibiTime_anemo_1-lastTime_anemo_1);
    windPower = (windPower + hertz*0.765+0.35)/2;
    if (windPower==0.35) windPower=0.0;
    temp_errorData=lastTime_anemo_1;
    lastTime_anemo_1 = ibiTime_anemo_1;
    }else if (ibiTime_anemo_1-temp_errorData<=25){
      temp_errorData=ibiTime_anemo_1;
    }
  }

void powerProduct(){
  ibiTime_PowerProduct=millis();
  powerProductAverage= (powerProductAverage + (0.750*1000/(ibiTime_PowerProduct-lastTime_PowerProduct)*3600))/2;
  lastTime_PowerProduct = ibiTime_PowerProduct;
}


void windVaneDir(){
  windVaneValue = map(analogRead(WindVane), 0, 1023, 0, 359);
  if (windVaneValue<windVaneOffSet) windVaneValue = 360 - windVaneOffSet + windVaneValue;
  else windVaneValue = windVaneValue - windVaneOffSet;
  windDirection = (windVaneValue + (360/(2*columns)))/(360/columns);
  if (windDirection == columns) windDirection = 0;
  windDirectionAverage = (windDirectionAverage + windDirection)/2;
}


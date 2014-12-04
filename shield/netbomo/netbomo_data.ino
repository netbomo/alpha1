void sendData(){
  // Print data
  Serial.print(node_id);
  Serial.print(" ");
  Serial.print(windPower);
  Serial.print(" ");
  Serial.print(windDirection); 
  Serial.print(" ");
  Serial.print(powerProductAverage);
  Serial.println();
  
  windPower = 0; 
  powerProductAverage = 0;
  windDirection = 0;
}


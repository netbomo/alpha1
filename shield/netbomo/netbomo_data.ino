void sendData(){
  // Print data
  Serial.print(node_id);
  Serial.print(" ");
  Serial.print(windPower);
  Serial.print(" ");
  Serial.print(windDirection); 
  Serial.print(" ");
  Serial.print(powerProductMoy);
  Serial.println();
  
  windPower = 0; 
  powerProductMoy = 0;
  windDirection = 0;
}


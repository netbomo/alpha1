void sendData(){
  // Print data
  Serial.print(node_id);
  Serial.print(" ");
  Serial.print(windPower);
  Serial.print(" ");
  Serial.print(dirVentMoy);
  Serial.print(" ");
  Serial.print(powerProductMoy);
  Serial.println();
  
  windPower = 0; 
  powerProductMoy = 0;
  dirVentMoy=0;
}


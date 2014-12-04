
// Définitions pour l'anémomètre 
float windPower = 0; 
float hertz =0;
int ibiTime_anemo_1 = 0;
int lastTime_anemo_1 = 0;
int temp_errorData =0;

// Définitions pour le wattNode
float powerProductAverage = 0;
int ibiTime_PowerProduct=0;
int lastTime_PowerProduct = 0; 

// Définition pour la girouette
const int WindVane = 0;
int windVaneValue = 0;
int windVaneOffSet = 140;
int columns = 16;
int windDirection = 0;
int windDirectionAverage = 0;

int node_id=6;  // Référence du node pour Emoncms

// déclaration temps d'attente : ici 10 min
unsigned long WaitToSendData = 600000;
unsigned long WaitWindVane = 5000;
unsigned long global_lastTime;
unsigned long time_test=0;

void setup() { 

  Serial.begin(9600); // Initialisation de la liaison serie

  attachInterrupt(1, windSpeed, RISING); 
  attachInterrupt(0, powerProduct, RISING);

  lastTime_anemo_1 = millis(); 
  lastTime_PowerProduct = millis();
  global_lastTime = 0;

}


void loop(){

  time_test = millis()-global_lastTime; // référence flotante de temps

  if (time_test/WaitWindVane>=1) {
    windVaneDir();
  }

  if (time_test/WaitToSendData>=1){

    noInterrupts();

    sendData();

    interrupts();
    global_lastTime=millis(); 
  }
} 





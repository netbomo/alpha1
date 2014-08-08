
// Définitions pour l'anémomètre 
float windPower = 0; 
float hertz =0;
int ibiTime_anemo_1 = 0;
int lastTime_anemo_1 = 0;

// Définitions pour le wattNode
float powerProductMoy = 0;
int ibiTime_PowerProduct=0;
int lastTime_PowerProduct = 0; 

// Définition pour la girouette
const int WindVane = 0;
int windVaneValue = 0;
//int dirVentMoy=0;//old version
int windVaneOffSet = 140;
//new version
int columns = 8;
int windDirection = 0;

int node_id=6;  // Référence du node pour Emoncms

// déclaration temps de moyennage : ici 10 min
unsigned long echantillonageToSendData = 600000;
unsigned long echantillonageWindVane = 5000;
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

  time_test = millis()-global_lastTime;

  if (time_test/echantillonageWindVane>=1) {
    windVaneDir();
  }

  if (time_test/echantillonageToSendData>=1){

    noInterrupts();

    sendData();

    interrupts();
    global_lastTime=millis(); 
  }
} 





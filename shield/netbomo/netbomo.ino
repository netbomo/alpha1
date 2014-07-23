
// Définitions pour l'anémomètre
const int Anemo_1 = 3; 
float windPower = 0; 
int ibiTime_anemo_1 = 0;
int lastTime_anemo_1 = 0;
int windVaneOffSet = 140;

// Définitions pour le wattNode
const int WattNode = 2;
float powerProductMoy = 0;
int ibiTime_PowerProduct=0;
int lastTime_PowerProduct = 0; 

// Définition pour la girouette
const int WindVane = 0;
int dirVent = 0;
int dirVentMoy=0;


int node_id=6;  // Référence du node pour Emoncms

// déclaration temps de moyennage : ici 10 min
int echantillonageToSendData = 600000;
int echantillonageWindVane = 1000;
int global_lastTime;

void setup() { 

  Serial.begin(9600); // Initialisation de la liaison serie

  attachInterrupt(1, windSpeed, RISING); 

  lastTime_anemo_1 = millis(); 
  lastTime_PowerProduct = millis();
  global_lastTime = millis();

}


void loop(){
  
  if (global_lastTime-millis()>=echantillonageWindVane) windVaneDir();

  if (global_lastTime-millis()>=echantillonageToSendData){
  
    noInterrupts();
    
    sendData();
    
    interrupts();
    
  }
} 






// --- Déclaration des constantes des broches analogiques ---
const int anemo = 3;  // constante de broche pour l'anemometre
const int wattnode = 2;
// --- Déclaration des variables globales ---
volatile long count_V = 0;  // déclaration de la variable de comptage d'impulsion pour le vent, variable volatile pour utilisation avec interruption
volatile long count_P = 0;

float vent = 0;  // déclaration de la variable de vitesse de vent
float puissance = 0;
int ibiTime_anemo = 0;
int ibiTime_puissance=0;// variable de temp
int lastTime_anemo = 0;  // variable de l'ancien temp
int lastTime_puissance = 0;  // variable de l'ancien temp
int node_id=6;
// --- Déclaration des objets utiles pour les fonctionnalités utilisées ---



void mesure_Anemo() {//interruption pour comptage des impulsions pour l'anémometre
count_V ++;
}
void mesure_puissance() {//interruption pour comptage des impulsions pour le wattmatre
count_P ++;
}


// ////////////////////////// 2. FONCTION SETUP = Code d'initialisation ////////////////////////// 
// La fonction setup() est exécutée en premier et 1 seule fois, au démarrage du programme

void setup()   { // debut de la fonction setup()

// --- ici instructions à exécuter 1 seule fois au démarrage du programme --- 
Serial.begin(9600);  // Initialisation de la liaison serie

attachInterrupt(1, mesure_Anemo, RISING);  // interruption permettant le comptage des tours d'anémometre
attachInterrupt(0,mesure_puissance,RISING);
// ------- Initialisation fonctionnalités utilisées -------  
//lcd.begin(16, 2);  // définition de la matrice du LCD

// ------- Broches en sorties numériques -------  

// ------- Broches en entrées numériques -------  

// ------- Activation si besoin du rappel au + (pullup) des broches en entrées numériques -------  

// ------- Initialisation des variables utilisées ------- 
lastTime_anemo = millis();  // réfférence temps
lastTime_puissance = millis();  // réfférence temps

} // fin de la fonction setup()


////////////////////////////////// 3. FONCTION LOOP = Boucle sans fin = coeur du programme //////////////////
// la fonction loop() s'exécute sans fin en boucle aussi longtemps que l'Arduino est sous tension

void loop(){ // debut de la fonction loop()

////test

////// fin test


ibiTime_anemo = millis();  // On ancre le temps
ibiTime_puissance = millis(); 
float hertz = float(count_V*1000)/(ibiTime_anemo-lastTime_anemo);

vent = hertz*0.765+0.35;  // calibrage en m/s avec données anémo (sur cet anémo la vitesse de vent en m/s correspond à la fréquence)

lastTime_anemo = ibiTime_anemo;
count_V = 0;
if (vent==0.35) vent=0.0;




int sensorValue = analogRead(A0);       // lit la tension d'entrée sur la pin A0 et la convertit entre 0 et 1023 (CAN)
int dirVent = map(sensorValue, 0, 1023, 0, 359);     // étalonne les valeurs trouvées pour avoir un angle entre 0 et 360° en 



puissance=0.750*count_P*1000/(ibiTime_puissance-lastTime_puissance)*3600;
lastTime_puissance = ibiTime_puissance;
count_P=0;


  // Print data
  Serial.print(node_id);
    Serial.print(" "); 
  Serial.print(vent);     
  Serial.print(" "); 
  Serial.print(dirVent);
  Serial.print(" "); 
  Serial.print(puissance);
  Serial.println();
  
delay(3000);
} // fin de la fonction loop() - le programme recommence au début de la fonction loop sans fin
// ********************************************************************************



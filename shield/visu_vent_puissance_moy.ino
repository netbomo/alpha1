

// --- Déclaration des constantes des broches analogiques ---
const int anemo = 3;  // constante de broche pour l'anemometre
const int wattnode = 2;
// --- Déclaration des constante paramétrable 
unsigned int temps_entre_tram=10000;
 int nb_valeur_dir=10;
const int nb_part_cercle=32;
// --- Déclaration des variables globales ---
volatile long count_V = 0;  // déclaration de la variable de comptage d'impulsion pour le vent, variable volatile pour utilisation avec interruption
volatile long count_P = 0;
float vent = 0;  // déclaration de la variable de vitesse de vent
float puissance = 0;// déclaration de la variable de puissance
int ibiTime_anemo = 0; //variable de temp vitesse
int ibiTime_puissance=0;// variable de temp puissance
int lastTime_anemo = 0;  // variable de l'ancien temp vitesse  
int lastTime_puissance = 0;  // variable de l'ancien temp puissance
int dirVent;
int dirVentint;
int sensorValue;
float tabdirvent[nb_part_cercle]={}; //declaration du tableau pour stoquer les mesure successive de la direction du vent
float taille_part=360/nb_part_cercle;//definition de la taille des partition du cercle
float moy=0;
int cas;
int k=0;
unsigned int delay_dir=temps_entre_tram/nb_valeur_dir; //definition du temps entre 2 mesures de direction
// --- Déclaration des objets utiles pour les fonctionnalités utilisées ---



void mesure_Anemo() {//interruption pour comptage des impulsions pour l'anémometre
count_V ++;
}
void mesure_puissance() {//interruption pour comptage des impulsions pour le wattmetre
count_P ++;
}

// ////////////////////////// 2. FONCTION SETUP = Code d'initialisation ////////////////////////// 

void setup()   { 

Serial.begin(9600);  // Initialisation de la liaison serie

attachInterrupt(1, mesure_Anemo, RISING);  // interruption permettant le comptage des tours d'anémometre
attachInterrupt(0,mesure_puissance,RISING);

// ------- Initialisation des variables utilisées ------- 
lastTime_anemo = millis();  // réfférence temps
lastTime_puissance = millis();  // réfférence temps

} // fin de la fonction setup()


////////////////////////////////// 3. FONCTION LOOP = Boucle sans fin = coeur du programme //////////////////

void loop(){

ibiTime_anemo = millis();  // On ancre le temps
ibiTime_puissance = millis(); 

vent= ((count_V*1000)/(ibiTime_anemo-lastTime_anemo))*0.765+0.35;// calcule de la frequence du signal et calibrage en m/s avec données anémo
if (vent==0.35) vent=0.0; //
lastTime_anemo = ibiTime_anemo;
count_V = 0;


while (k<nb_valeur_dir)
{
  sensorValue = analogRead(A0);       // lit la tension d'entrée sur la pin A0 et la convertit entre 0 et 1023 (CAN)
dirVentint = map(sensorValue, 0, 1023, 0, 359);     // étalonne les valeurs trouvées pour avoir un angle entre 0 et 360° en 
cas=int(dirVentint/taille_part);
tabdirvent[cas]++;

delay(500);
k++;
}

float somme=0;
for (cas=0;cas<nb_part_cercle;cas++){
 somme=somme+cas*(taille_part)*tabdirvent[cas];
}
dirVent=somme/nb_valeur_dir-5.5;
for (cas=0;cas<nb_part_cercle+1;cas++){
tabdirvent[cas]=0;
}

puissance=0.750*count_P*1000/(ibiTime_puissance-lastTime_puissance)*3600;
lastTime_puissance = ibiTime_puissance;
count_P=0;

noInterrupts();//disenable interrupt for seending data
  // Print data
  Serial.print(sensorValue);     
  Serial.print("  vite  "); 
  Serial.print(dirVent);
  Serial.print("  deg  "); 
  Serial.print(dirVentint);
  Serial.print("  pui  "); 
  Serial.println();
  
interrupts(); // enable interupt for collecting data
} // fin de la fonction loop() - le programme recommence au début de la fonction loop sans fin
// ********************************************************************************




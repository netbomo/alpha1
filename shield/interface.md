Capteur et interface
====================

Nous avons 3 mesures à faire :

La mesure de la vitesse du vent
La direction du vent
La puissance électrique fournie par l’éolienne



### Mesure de la vitesse du vent


Pour mesure la vitesse du vent nous utilisons un anémomètre NGR 40C. Cet anémomètre à l'avantage d'avoir une longue durée de vie (15ans environ). En sortie de l’anémomètre on observe un signal sinusoïdal de fréquence variant entre 0 et 120 Hz et d'amplitude de 40mV à 6V. La vitesse du vent est donnée par la relation [m/s = (Hz x 0,765) + 0.35]. Nous avons donc dut créer l'interface permettant de mesurer la fréquence de ce signal :




Le premier étage est un montage Amplificateur différentiel il permet de récupérer le signal de l’anémomètre et de l'amplifier, on à :

	Vo=10*(V1-V2)

Cette amplification nous permet de lire la fréquence même si l'amplitude des signaux d'entrés est faible.

Le deuxième étage R5-C1 joue le rôle d'un filtre passe bas d'ordre 1. Cela vas permettre de limiter le bruit et les interférences. La fréquence de coupure de ce filtre est de 130Hz car dans le cas ou l’anémomètre délivrerait cette fréquence la vitesse du vent serais de 300 km/h...

Le dernier étage est un comparateur à 2 seuils (trigger de Schmitt). Il va permettre de convertir le signal sinusoïdal en un signal carrée de même fréquence.



nous utilisons ensuite un script arduino pour calculer la fréquence : voir visu_vent_puissance.ino



### mesure de la direction du vent.


On utilise un girouette : cette girouette est un potentiomètre rotatif : NRG #200

On rentre dans une entrée analogique de la carte arduino avec Vs pour lire la direction du vent.
Comme on envoie des données toutes les 10 minutes il faut réaliser plusieurs mesures avec la girouette pour pouvoir les moyenner et avoir un résultat concernant le vent dominant sur ces 10 minutes et s’il est ou non turbulent.

Pour cela :
On crée une boucle nous permettant de réaliser plusieurs mesures avant l'envoi, dans cette boucle on remap les valeurs entre 0 et 360 degrés puis on divise le cercle en secteur et on incrémente le secteur correspondant à la direction du vent pour pouvoir faire la moyenne on calcule la moyenne pondérée des secteurs par le nombre de valeurs observé dans le secteur et l'écart-type.

voir visu_vent_puissance_moy.ino

### Mesure de puissance


On utilise un « Wattnode pulse » qui se branche sur la ligne avec une pince ampèremétrique et une prise de tension en parallèle.
Ce système va calculer la tension, le courant et le déphasage entre les 2 et sortir un signal carré comprit entre 0 et 5V.


Figure 3 visu puissance ??

La fréquence de ce signal nous permet d'obtenir la puissance avec la formule :

	P=0,75*f*3600

voir visu_vent_puissance.ino

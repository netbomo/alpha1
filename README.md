alpha1
======

Prototype de shield pour arduino, permettant de monitorer une éolienne.

Voir les premières données :

http://desplanchesdepalette.org/colibri/Colibri_Energie.html

Projet :
--------

Le but est de créer une shield pouvant par exemple créer un node pour le système OpenEnergyMonitor ou se greffant sur une carte Akeru, une carte Arduino Yun...

###Capteur désirés :

- Anémomètre
- girouette
- capteur de courant
- capteur de tension 

note : Pour l'instant ma carte emontx ne fontionne plus, et la sonde de courant CT ne donne plus de valeur correcte, donc nous utilisons un WattNode Pulse ainsi qu'une carte arduino UNO.

###Etat des lieux :
 Le systême fonctionne à l'atelier, mais pose problème en situation, la présence proche du réseau à l'air d'en être la cause. La prochaine modification sera de mettre le systême dans un boitier métalique avec une mise à la masse. Une carte de meilleure qualité devrait aider aussi.

Le premier prototype est installé avec la version du programme netbomo.ino

##installation de raspbian sur carte sd:

Utilsation des tutoriels :

installation de l'image raspbian sur carte sd :
http://lea-linux.org/documentations/Installation_de_la_carte_SD_du_Raspberry_Pi

premier boot sur le raspberry:
http://lea-linux.org/documentations/Tutoriel_pour_d%C3%A9buter_avec_le_Raspberry_Pi


##connexion 3g :

http://itsacleanmachine.blogspot.fi/2012/11/raspberry-router.html

	comment rendre sakis3g permanant ????

Création des règles udev pour le téléphone:
-- fichier udev avec son emplacement ---

##emoncms : 

Tutoriel:
http://openenergymonitor.blogspot.fr/2012/05/installing-emoncms-on-raspberry-pi.html

deamon oemgateway :
il faut copier le répertoire oem_gateway dans /usb/bin
	sudo mv ~/oem_gateway-master /usr/bin/oemgateway

sudo oem_gateway.init.??? /etc/init.d/oemgateway

paramètrer ce fichier:

--- détails fichier ---

éditer /usb/bin/oem_gateway/oemgateway.conf:

--- détails fichier ----


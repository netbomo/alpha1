NETBOMO
=======

instalation et configuration du raspberry.

###installation de raspbian sur carte sd:

Utilsation des tutoriels :

installation de l'image raspbian sur carte sd :

http://lea-linux.org/documentations/Installation_de_la_carte_SD_du_Raspberry_Pi

premier boot sur le raspberry:

http://lea-linux.org/documentations/Tutoriel_pour_d%C3%A9buter_avec_le_Raspberry_Pi


###connexion 3g :

http://itsacleanmachine.blogspot.fi/2012/11/raspberry-router.html

copier sakis dans /usr/bin
	
	sudo mv sakis3g /usr/bin/sakis3g

créer un deamon pour sakis3g :

	sudo nano /etc/init.d/sakis3g 

et coller le code de sakis3g

trouver ici:

http://www.raspberrypi.org/forums/viewtopic.php?f=31&t=40529

et modifié pour rajouter la fonction restart.

On lui rajoute la posibilité de s'executer :

	sudo chmod +x /etc/init.d/sakis3g


Création des règles udev pour le téléphone :

voir: 60-zte.rules

Placer dans /etc/udev/rules.d/

Script permettant de verifier la connexion 3g à placer dans /usr/bin/3Gtest :
	
	#! /bin/bash
	# /usr/bin/3Gtest

	PATH=/usr/sbin:/usr/bin:/sbin:/bin

	echo "test de connexion 3G"

	./sakis3g status

	if [[ $?=6 ]]		# Valeur de non connexion
	then sudo ./sakis3g start
	else
        	echo "Already connect"
	fi



###emoncms : 

Tutoriel:
http://openenergymonitor.blogspot.fr/2012/05/installing-emoncms-on-raspberry-pi.html

deamon oemgateway :

il faut copier le répertoire oem_gateway dans /usb/bin puis placer le script oem_gateway.int.dist dans /usr/bin

	sudo mv ~/oem_gateway-master /usr/bin/oemgateway
	sudo oem_gateway.init.dist /etc/init.d/oemgateway

vous devez arriver à un résultat similaire :
	
	/usr/bin/oemgateway/  	#le repertoire
		/oemgateway	# le script

voir oemgateway et oemgateway.conf pour les configurations.

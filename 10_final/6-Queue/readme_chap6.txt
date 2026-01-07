Ce projet est une application embarquée utilisant FreeRTOS sur Raspberry Pi Pico.
Il permet d’afficher une valeur binaire aléatoire sur 7 LEDs, tout en utilisant une architecture multitâche basée sur des agents logiciels.

Le système repose sur :

FreeRTOS pour la gestion des tâches

GPIO du Pico pour piloter les LEDs

Une approche orientée objet avec des classes BlinkAgent et CounterAgent

🎯 Objectifs pédagogiques

Comprendre le fonctionnement de FreeRTOS

Créer et gérer plusieurs tâches concurrentes

Manipuler des GPIO

Observer l’état du système en temps réel (statistiques FreeRTOS)

Mettre en œuvre une architecture modulaire

🧩 Fonctionnalités principales

🔴 Clignotement d’une LED (heartbeat système)

🔢 Affichage d’un nombre binaire aléatoire sur 7 LEDs

📊 Affichage des statistiques FreeRTOS :

Nombre de tâches

Priorités

Utilisation de la pile

État du tas (heap)

⏱️ Mise à jour toutes les 3 secondes

🛠️ Matériel requis

Raspberry Pi Pico

8 LEDs

Résistances adaptées

Câblage GPIO :

GPIO 0 → LED de clignotement

GPIO 1 à 7 → LEDs binaires

📂 Structure du code
main.c
BlinkAgent.h / BlinkAgent.cpp
CounterAgent.h / CounterAgent.cpp
FreeRTOS

🧠 Explication générale du code
1️⃣ Inclusions et définitions

Le programme inclut :

Les bibliothèques Pico SDK

FreeRTOS

Les agents personnalisés BlinkAgent et CounterAgent

Les GPIO des LEDs sont définis avec des macros pour plus de clarté.

2️⃣ Gestion des statistiques FreeRTOS

La fonction runTimeStats() :

Récupère le nombre de tâches actives

Affiche pour chaque tâche :

Son ID

Sa priorité actuelle et de base

Son utilisation de pile

Son nom

Affiche l’état du heap mémoire

👉 Cette fonction est très utile pour le debug et l’analyse des performances temps réel.

3️⃣ Tâche principale (mainTask)

Cette tâche :

Initialise deux agents :

BlinkAgent : fait clignoter une LED (GPIO 0)

CounterAgent : contrôle les 7 LEDs binaires

Démarre les deux tâches avec la même priorité

Entre dans une boucle infinie où :

Les statistiques système sont affichées

Une valeur aléatoire sur 7 bits est générée

Cette valeur est affichée sur les LEDs

Le système attend 3 secondes

4️⃣ Architecture par agents
🔹 BlinkAgent

Gère une LED indépendante

Sert de témoin de fonctionnement du système

🔹 CounterAgent

Reçoit une valeur binaire

Allume/éteint les LEDs selon les bits du nombre

👉 Cette séparation améliore la lisibilité, la maintenance et la scalabilité du code.

5️⃣ Lancement de FreeRTOS

vLaunch() crée la tâche principale

vTaskStartScheduler() démarre le noyau FreeRTOS

Le programme ne revient jamais dans main() après cela

▶️ Fonctionnement global

Initialisation du système et du port série

Lancement de FreeRTOS

Création de la tâche principale

Démarrage des agents

Exécution continue du système multitâche

🚀 Améliorations possibles

Ajout d’une interface UART ou USB

Utilisation de timers FreeRTOS

Gestion multi-cœur (core 1 du Pico)

Ajout de boutons pour modifier le comportement

Journalisation plus avancée






# Projet SD-Graphes

> Emmanuel Ladoh et Léa Ribeiro

> Sous la direction de Clarisse Dhaenens

> Juin 2019


Dans cette archive, vous trouverez tous les fichiers nécessaires à la résolution du problème posé.
Pour chaque étape de résolution de la méthode *route-first / cluster-second* les fichiers .c et les fichiers d'entêtes.
Un fichier main.c contient l'appel à toutes les fonctions. 

Le détail pour exécuter le programme est aussi disponible dans le rapport.


#### Pour compiler le programme :
* Se placer dans le répertoire où sont enregistrer les fichiers (les .c et les  .h)
* Dans un terminal, utiliser la commande make . Un exécutable de nom programme est créé.

#### Pour exécuter le programme créé :
* Créer un fichier structuré de la même façon que le fichier **exemple.dat**. Il faut impérativement que 
  * la première ligne contienne le numéro du premier client à livrer (Entier)
  * la deuxième ligne contienne le nombre de clients présents dans le fichier (Entier)
  * la troisième ligne doit correspondre à la capacité maximale des véhicules du transporteur (Entier)
  * la quatrième ligne contient, pour chaque client, les quantités à leur livrer (Entier)
  * les ligens suivantes représentent la matrice des distances entre les clients et entre le clients et le dépôt.
*Exécuter le programme à l’aide de la commande ./programme < NOM*. *Où NOM* correspond au nom complet (extension comprise) du fichier de données nouvellement créé*.

**Exemple de lignes de commande et d’exécution :**
	
  $ make
	
  $ ./programme < exemple.dat
  
  **OU**
  
  $ make
  
  $ ./a.out < exemple.dat >resultat.txt

*La seconde version permet de stocker les résultats de la méthode du route-first/cluster second dans le fichier resultat.txt de manière à ce que l’affichage ne se fasse pas dans le terminal.*

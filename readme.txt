#Project TP-APP
Bensafi Sarra et Chikh Dounia
21/01/2021

 *** 1/ Introduction
 Ce mini-projet a pour but le calcul du produit matriciel selon la méthode séquentielle classique et la méthode parallele.

 *** 2/ Architecture

     --mmm.c:
                -Appel à "initMatrix","displayMatrix","funcThread","funThreadC","sequentielle" et "verifMatrixequal".
                -Allocation des matrices.
                -Création et affichage des matrices a et b.
                -Affichage du resultat du calcul parallele (ligne-colonne/colonne-ligne) et séquentiel.
                -Affichage et calcul du temps sequetiel et parallel en secondes.
                -Calcul et affichage du "speedup".




     --initMatrix.h:
                -Génére une matrice avec des valeurs aléatoires grace à la fonction "generateRandomMatrix".


     --displayMatrix.h:
                -Affiche la matrice grace à la fonction "printMatrix".


     --funcThread.h:
               -Déclaration variables locales et globales.
               -Appel de "displayMatrix".
               -Création des threads "initialisation".
               -Multiplication matricielle ligne/colonne "funcao".



     --funThreadC.h:
               -Déclaration variables locales et globales.
               -Appelle de "displayMatrix".
               -Création des threads "initialisationC".
               -Multiplication matricielle colonne/ligne "funcaoC".
     

     --verifMatrixequal.h:
               -Vérification de l'égalité de deux matrices.


*** 2/ Execution:
                 cc mmm.c -o mmm -lpthread
                 ./mmm [dimension des matrix nxn * nxn ] [num thread] [mode de calcul 0 pour parallel 1 pour sequentiel]

*** 3/ Erreur: 
               -Affichage du message d'erreur "Specifier le mode sequentiel avec : 1 Specifier le mode parallel avec : 0" lorsqu'on ne précise pas le mode de calcul.
               -Affichage du message d'erreur "Utiliser : ./mmm [dimension des matrix nxn * nxn ] [num thread] [mode de calcul 0 pour parallel 1 pour sequentiel]" lorsqu'il y'a une erreur de synthaxe lors de la saisie de la commande d'execution.


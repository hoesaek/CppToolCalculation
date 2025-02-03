/**
 * @file test_calculMaths.cpp
 * @brief Programme de calcul matriciel simple.
 *
 * Ce programme effectue des opérations sur une matrice 2x2 et affiche le résultat.
 * Il réalise des multiplications et additions en manipulant les chiffres des produits.
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

/**
 * @brief Fonction principale du programme.
 * 
 * Cette fonction effectue plusieurs opérations mathématiques sur une matrice 2x2,
 * notamment des multiplications et des sommes de chiffres extraits des produits intermédiaires.
 * Elle affiche ensuite le résultat final sous forme de matrice 2x2.
 * 
 * @return int Retourne 0 si l'exécution est réussie.
 */
int main() {
    int x[2][2] = {
        {7, 3},
        {8, 3}
    };

    // Calcul des produits intermédiaires
    int produit3 = x[0][1] * x[1][0];
    int produit4 = x[0][0] * x[1][1];
    int prod = produit3 + produit4;

    // Extraction des chiffres
    int a = prod % 10;
    int b = (prod / 10) % 10;
    int c = prod / 100;

    // Initialisation des matrices temporaires
    int t1[2][2] = { {0, 0}, {0, 0} };
    int t2[2][2] = { {0, 0}, {0, 0} };
    int res[2][2] = { {0, 0}, {0, 0} };

    // Calcul des sous-produits
    int produit1 = x[0][1] * x[1][1];
    t1[1][1] = produit1 % 10;
    t1[1][0] = (produit1 / 10) % 10;

    int produit2 = x[0][0] * x[1][0];
    t1[0][1] = produit2 % 10;
    t1[0][0] = (produit2 / 10) % 10;

    // Remplissage de la deuxième matrice temporaire
    t2[0][0] = c; // centaine
    t2[0][1] = b; // dizaine
    t2[1][0] = a; // unité
    t2[1][1] = 0; // reste 0

    // Somme des matrices temporaires
    int z = t1[0][0] + t2[0][0];
    int q = t1[0][1] + t2[0][1];
    int s = t1[1][0] + t2[1][0];
    int v = t1[1][1] + t2[1][1];

    // Gestion des retenues
    int retenue = 0;
    if (s >= 10) {
        retenue = s / 10;
        s = s % 10;
    }
    q += retenue;

    if (q >= 10) {
        retenue = q / 10;
        q = q % 10;
    }
    z += retenue;

    // Stockage du résultat final
    res[0][0] = z;
    res[0][1] = q;
    res[1][0] = s;
    res[1][1] = v;

    // Affichage du résultat
    cout << res[0][0] << "" << res[0][1] << "" << res[1][0] << "" << res[1][1] << endl;

    return 0;
}

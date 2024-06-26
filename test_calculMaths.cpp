// test_calculMaths.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main() {
    int x[2][2] = {
        {7, 3},
        {8, 3}
    };

    int produit3 = x[0][1] * x[1][0];
    int produit4 = x[0][0] * x[1][1];

    int prod = produit3 + produit4; 
    int a = prod % 10; 
    int b = (prod / 10) % 10; 
    int c = prod / 100; 

    int t1[2][2] = { {0, 0}, {0, 0} };
    int t2[2][2] = { {0, 0}, {0, 0} };
    int res[2][2] = { {0, 0}, {0, 0} };

    int produit1 = x[0][1] * x[1][1];
    t1[1][1] = produit1 % 10;        
    t1[1][0] = (produit1 / 10) % 10; 

    int produit2 = x[0][0] * x[1][0]; 
    t1[0][1] = produit2 % 10; 
    t1[0][0] = (produit2 / 10) % 10; 

    t2[0][0] = c; // centaine
    t2[0][1] = b; // dizaine
    t2[1][0] = a; // unité
    t2[1][1] = 0; // rester 0

    int z = t1[0][0] + t2[0][0];
    int q = t1[0][1] + t2[0][1];
    int s = t1[1][0] + t2[1][0];
    int v = t1[1][1] + t2[1][1];

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

    res[0][0] = z;
    res[0][1] = q;
    res[1][0] = s;
    res[1][1] = v;

    cout << res[0][0] << "" << res[0][1] << "" << res[1][0] << "" << res[1][1] << endl;

    return 0;
}




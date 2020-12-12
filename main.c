#define _CRT_SECURE_NO_WARNINGS
#include "header.h"
#include<stdio.h>


int main() {
	printf("\n===============================================================================\n");
	printf("\t \t DOBRO DOSLI U e-Dnevnik za profesore");
	printf("\n===============================================================================\n");
	printf("Unesite lozinku za e-Dnevnik\n");
	PROFESOR* lozinka = {3221};
	PROFESOR* pokP = &lozinka;
	int provjeraLozinke;
	int k;
	do {
		scanf("%d", &provjeraLozinke);
		k = provjera(provjeraLozinke);
	} while (k != 1);
	int n;
	izbornik();
	return 0;
}
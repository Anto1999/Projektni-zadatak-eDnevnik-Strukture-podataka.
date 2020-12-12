#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <string.h>
#include <errno.h>
#include<conio.h>


int provjera(int a) {
	if (a != 3221) {
		printf("Kriva lozinka,ponovite unos\n");
	}
	else {
		printf("Tocna lozinka\n");
		printf("\n===============================================================================\n");
		return 1;
	}
}

void izbornik() {
	int izbor;
	FILE* fp;
	UCENIK ucenik[20];
	UCENIK* pokU = ucenik;
	do {
		printf("Unesite izbor:\n");
		printf("1.Kreiranje datoteke Ucenici.bin,te zapisivanje ucenika\n");
		printf("2.Ispis ucenika iz datoteke Ucenici.bin\n");
		printf("3.Trazenje ucenika s najvecim brojem izostanaka\n");
		printf("4.Sortiranje po prosjeku datoteke Ucenici.bin\n");
		printf("5.Preuredjivanje postojeceg ucenika iz datoteke Ucenici.bin\n");
		printf("6.Izlaz\n");
		scanf("%d", &izbor);
		switch (izbor) {
		case 1:
			system("cls");
			int brojUcenika;
			printf("Koliko ucenika zelite dodati u datoteku Ucenici.bin:\n");
			scanf("%d", &brojUcenika);
			fp = fopen("Ucenici.bin", "ab");
			if (fp == NULL) {
				printf("Error opening file!\n");
				exit(1);
			}
			else {
				system("cls");
				printf("\n\nUpisite podatke ucenika\n\n");
				for (int i = 0; i < brojUcenika; i++)
				{
					printf("%d. Ucenik:", i + 1);
					printf("\nUnesite ime :\n");
					scanf("%s", (pokU + i)->ime);
					printf("\nUnesite prezime:\n");
					scanf("%s", &(pokU + i)->prezime);
					printf("\nUnesite mjesto iz kojeg je ucenik:\n");
					scanf("%s", &(pokU + i)->mjesto);
					printf("\nUnesite broj izostanaka ucenika za ovu skolsku godinu:\n");
					scanf("%d", &(pokU + i)->izostanci);
					printf("\nUnesite zakljucnu ocijenu iz predmeta Matematika:\n");
					scanf("%d", &(pokU + i)->mat);
					printf("\nUnesite zakljucnu ocijenu iz predmeta Fizika:\n");
					scanf("%d", &(pokU + i)->fizika);
					printf("\nUnesite zakljucnu ocijenu iz predmeta Informatika:\n");
					scanf("%d", &(pokU + i)->inf);
					(pokU + i)->prosjek =(float) ((float)(pokU + i)->inf + (float)(pokU + i)->mat + (float)(pokU + i)->fizika)/3;

				}
				printf("\n===============================================================================\n");
			}


			fwrite(pokU, sizeof(UCENIK), brojUcenika, fp);
			fclose(fp);
			break;

			

		case 2:
			fp = fopen("Ucenici.bin", "ab");
			if (fp == NULL) {
				printf("Error opening file!\n");
				exit(1);
			}
			else {
				fp = fopen("Ucenici.bin", "rb");
				if (fp == NULL) {
					perror("Otvaranje");
				}
				else {
					fprintf(stdout, "Datoteka postoji na disku.\n");
					fread(pokU, sizeof(UCENIK), sizeof(ucenik) / sizeof(UCENIK), fp);

					for (int i = 0; i < sizeof(ucenik) / sizeof(UCENIK); i++) {
						if ((pokU + i )->prosjek < 0) {
							printf("Unesite podatke za studente.\n");
							break;
						}
						fprintf(stdout, "\n %d.ucenik\nIme:%s \nPrezime:%s\nMjesto:%s\nBroj sati izostanaka za sk.godinu:%d\nZakljucna ocijena Matematika:%d\nZakljucna ocijena Fizika:%d\nZakljucna ocijena Informatika:%d\nProsjek ucenika:%5f\n", i + 1, ucenik[i].ime, ucenik[i].prezime, ucenik[i].mjesto, ucenik[i].izostanci, ucenik[i].mat, ucenik[i].fizika, ucenik[i].inf,ucenik[i].prosjek);
						if ((pokU + i+1)->prosjek < 0) {
							break;
						}
					}
					fclose(fp);
					printf("\n===============================================================================\n");
				}
			}
			break;


		case 3:
			
			system("cls");
			int naj=0;
			fp = fopen("Ucenici.bin", "ab");
			if (fp == NULL) {
				printf("Error opening file!\n");
				exit(1);
			}
			else {
				fp = fopen("Ucenici.bin", "rb");
				if (fp == NULL) {
					perror("Otvaranje");
				}
				else {
					fprintf(stdout, "Datoteka postoji na disku.\n\n\n");
					fread(pokU, sizeof(UCENIK), sizeof(ucenik) / sizeof(UCENIK), fp);

					for (int i = 0; i < sizeof(ucenik) / sizeof(UCENIK); i++) {

						if ((pokU + i)->izostanci > naj) {
							naj = (pokU + i)->izostanci;
						}

					}
					for (int i = 0; i < sizeof(ucenik) / sizeof(UCENIK); i++) {

						if ((pokU + i)->izostanci == naj) {
							fprintf(stdout, "\nUcenik s najvecim brojem izostanaka je %s %s s brojem izsotanaka:%d\n",(pokU+i)->ime,(pokU+i)->prezime,naj);
						}
						
					}
					printf("\n===============================================================================\n");
					fclose(fp);
				}
			}
			break;
		case 4:
			system("cls");
			fp = fopen("Ucenici.bin", "rb");
			printf("\n===============================================================================\n");
			if (fp == NULL)
			{
				fprintf(stderr, "Vrijednost pogreske je: %d\n", errno);
				fprintf(stderr, "Pogreska: %s\n", strerror(errno));
			}
			else {
				int i, j;
				struct ucenik temp;
				fread(ucenik, sizeof(UCENIK), sizeof(ucenik) / sizeof(UCENIK), fp);
				for (i = 0; i < (sizeof(ucenik) / sizeof(UCENIK)) - 1; i++)
				{
					for (j = 0; j < ((sizeof(ucenik) / sizeof(UCENIK)) - 1 - i); j++)
					{
						if (ucenik[j].prosjek < ucenik[j + 1].prosjek)
						{
							temp = ucenik[j];
							ucenik[j] = ucenik[j + 1];
							ucenik[j + 1] = temp;
						}
					}
				}
				for (i = 0; i < (sizeof(ucenik) / sizeof(UCENIK)); i++)
				{
					fprintf(stdout, " Ucenik s %d.prosjekom je %s %s\n", i + 1,(pokU+i)->ime,(pokU+i)->prezime);
					fprintf(stdout, "Njegov prosjek iznosi %5f", (pokU + i)->prosjek);
					if ((pokU + i + 1)->prosjek < 0) {
						break;
					}
					printf("\n");
				}
				printf("\n===============================================================================\n");

			}
			break;
		case 5:
			system("cls");
			int i;
			printf("Unesite redni broj ucenika kojem zelite mjenjati podatke:\n");
			scanf("%d", &i);
			i = i - 1;
			fp = fopen("Ucenici.bin", "r+b");
			if (fp == NULL) {
				printf("Error opening file!\n");
				exit(1);
			}
			
			else {
				system("cls");
					printf("\nUnesite ime :\n");
					scanf("%s", (pokU + i)->ime);
					printf("\nUnesite prezime:\n");
					scanf("%s", &(pokU + i)->prezime);
					printf("\nUnesite mjesto iz kojeg je ucenik:\n");
					scanf("%s", &(pokU + i)->mjesto);
					printf("\nUnesite broj izostanaka ucenika za ovu skolsku godinu:\n");
					scanf("%d", &(pokU + i)->izostanci);
					printf("\nUnesite zakljucnu ocijenu iz predmeta Matematika:\n");
					scanf("%d", &(pokU + i)->mat);
					printf("\nUnesite zakljucnu ocijenu iz predmeta Fizika:\n");
					scanf("%d", &(pokU + i)->fizika);
					printf("\nUnesite zakljucnu ocijenu iz predmeta Informatika:\n");
					scanf("%d", &(pokU + i)->inf);
					(pokU + i)->prosjek = (float)((float)(pokU + i)->inf + (float)(pokU + i)->mat + (float)(pokU + i)->fizika) / 3;
				printf("\n===============================================================================\n");
			}


			fwrite(pokU, sizeof(UCENIK),i+1 , fp);
			fclose(fp);
			
			break;
		case 6:
			exit(0);
			break;
		default: printf("Nevaljajuci unos,ponovi!\n");
			printf("\n===============================================================================\n");
			break;
		}
		
		} while (izbor != 6);
}
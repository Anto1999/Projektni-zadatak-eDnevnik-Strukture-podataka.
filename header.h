#ifndef HEADER_H
#define HEADER_H
typedef struct ucenik {
	char ime[20];
	char prezime[20];
	char mjesto[20];
	int izostanci;
	int mat;
	int fizika;
	int inf;
	float prosjek;

}UCENIK;

typedef struct profesor {

	unsigned short lozinka;

}PROFESOR;

void izbornik();
int provjera(int);

#endif 
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include<time.h>

void naplataPutarine(FILE *, FILE *);
void upisEvidencija(FILE *);
void upisPotvrda(FILE *, FILE *, int, char *);
int randomInkasant();
void evidencija(FILE *, SYSTEMTIME, int, int, int);

int main()
{
	FILE *evidencija, *potvrda=fopen("PotvrdaIskljucenje.txt", "w");
	char komanda;
	do{
		printf("\n");
		printf("\n\t\t\t\tEvidencija             - A");
		printf("\n\t\t\t\tNaplata putarine       - B");
		printf("\n\t\t\t\tUputstvo za koriscenje - C");
		printf("\n\t\t\t\tKRAJ                   - 0\n");
		printf("\n\t\t\t\t\t   ");
		komanda=getch();
		if(komanda=='a' || komanda=='A')
		{
			system("cls");
			system("start EvidencijaIskljucenje.txt");
		}
		else if(komanda=='b' || komanda=='B')
		{
			system("cls");
			evidencija=fopen("EvidencijaIskljucenje.txt", "a");
			naplataPutarine(evidencija, potvrda);
			printf("\n\t\t\t\tTroskovi su obracunati!");
			fclose(evidencija);
		}
		else if(komanda=='c' || komanda=='C')
		{
			system("cls");
			system("start UputstvoIskljucenje.txt");
		}
		else if(komanda!='0')
		{
			system("cls");
			printf("\n\t\t\t\t   ---------------------");
			printf("\n\t\t\t\t   |Komanda ne postoji!|");
			printf("\n\t\t\t\t   |Ponovite unos!     |");
			printf("\n\t\t\t\t   ---------------------");
		}
	}while(komanda!='0');
	system("cls");
	printf("KRAJ!\n");
	system("pause");
	return 0;
}

void naplataPutarine(FILE *evidencija, FILE *potvrda)
{
	int vrijeme=0;
	FILE *vp=fopen("VP.txt", "r");
	char komanda_klasa, kazna[2];
	fscanf(vp, "%d", &vrijeme);
	if(vrijeme<15)
		strcpy(kazna, "Da");
	else if(vrijeme>15)
		strcpy(kazna, "Ne");
	do{
		printf("\n\t\t\t\tKlasa vozila (A, B, C, D)? ");
		printf("\n\t\t\t\tPocetak - 0\n");
		printf("\n\t\t\t\t\t   ");
		komanda_klasa=getch();
		if(komanda_klasa=='a' || komanda_klasa=='A')
		{
			printf("\n\t\t\t\tObracunavanje troskova...");
			Sleep(3000);
			system("cls");
			upisPotvrda(potvrda, evidencija, 1, kazna);
			return;
		}
		else if(komanda_klasa=='b' || komanda_klasa=='B')
		{
			printf("\n\t\t\t\tObracunavanje troskova...");
			Sleep(3000);
			system("cls");
			upisPotvrda(potvrda, evidencija, 2, kazna);
			return;
		}
		else if(komanda_klasa=='c' || komanda_klasa=='C')
		{
			printf("\n\t\t\t\tObracunavanje troskova...");
			Sleep(3000);
			system("cls");
			upisPotvrda(potvrda, evidencija, 3, kazna);
			return;
		}
		else if(komanda_klasa=='d' || komanda_klasa=='D')
		{
			printf("\n\t\t\t\tObracunavanje troskova...");
			Sleep(3000);
			system("cls");
			upisPotvrda(potvrda, evidencija, 4, kazna);
			return;
		}
		else if(komanda_klasa=='0')
		{
			system("cls");
			return;
		}
		if(komanda_klasa!='a' || komanda_klasa!='A' || komanda_klasa!='b'  || komanda_klasa!='B' || komanda_klasa!='c' || komanda_klasa!='C' ||
		   komanda_klasa!='d' || komanda_klasa!='D' || komanda_klasa!='0')
		{
			system("cls");
			printf("\n\t\t\t\t   ---------------------");
			printf("\n\t\t\t\t   |Komanda ne postoji!|");
			printf("\n\t\t\t\t   |Ponovite unos!     |");
			printf("\n\t\t\t\t   ---------------------\n");
		}
	}while(komanda_klasa!='0');
}

int randomInkasant()
{
	srand((unsigned)time(NULL));
	return (rand()%9)+1;
}

void upisPotvrda(FILE *f, FILE *evidencija_iskljucenje, int klasa_vozila, char *kazna1)
{
	int inkasant, kazna=0, putarina=0, ukupno=0;
	SYSTEMTIME t;
	fprintf(f, "**************************************\n");
	fprintf(f, "* ================================== *\n");
	fprintf(f, "*     JAVNO PREDUZECE - MS Putevi    *\n");
	fprintf(f, "* ================================== *\n");
	fprintf(f, "*                                    *\n");
	inkasant=4;
	fprintf(f, "* Inkasant: %d                        *\n", inkasant);
	fprintf(f, "*                                    *\n");
	GetSystemTime(&t);
	fprintf(f, "* Datum: %02d.%02d.%d.                 *\n", t.wDay, t.wMonth, t.wYear);
	fprintf(f, "*                                    *\n");
	fprintf(f, "* Vrijeme: %02d:%02d:%02d                  *\n", t.wHour+1, t.wMinute, t.wSecond);
	fprintf(f, "*                                    *\n");
	fprintf(f, "* Klasa vozila: %d                    *\n", klasa_vozila);
	fprintf(f, "*                                    *\n");
	if(strcmp(kazna1, "Da")==0)
	{
		if(klasa_vozila==1)
		{
			kazna=100;
			putarina=2;
			fprintf(f, "* Kazna: %-3.2fKM                    *\n", (float)kazna);
			fprintf(f, "*                                    *\n");
			fprintf(f, "* Putarina: %dKM                      *\n", putarina);
		}
		else if(klasa_vozila==2)
		{
			kazna=200;
			putarina=4;
			fprintf(f, "* Kazna: %-3.2fKM                    *\n", (float)kazna);
			fprintf(f, "*                                    *\n");
			fprintf(f, "* Putarina: %dKM                      *\n", putarina);
		}
		else if(klasa_vozila==3)
		{
			kazna=300;
			putarina=6;
			fprintf(f, "* Kazna: %-3.2fKM                    *\n", (float)kazna);
			fprintf(f, "*                                    *\n");
			fprintf(f, "* Putarina: %dKM                      *\n", putarina);
		}
		else if(klasa_vozila==4)
		{
			kazna=400;
			putarina=6;
			fprintf(f, "* Kazna: %-3.2fKM                    *\n", (float)kazna);
			fprintf(f, "*                                    *\n");
			fprintf(f, "* Putarina: %dKM                      *\n", putarina);
		}
		fprintf(f, "*                                    *\n");
		ukupno=kazna+putarina;
		fprintf(f, "* Ukupno (KM): %-3.2f                *\n", (float)ukupno);
	}
	else if(strcmp(kazna1, "Ne")==0)
	{
		if(klasa_vozila==1)
		{
			putarina=2;
			fprintf(f, "* Putarina: %dKM                      *\n", putarina);
		}
		else if(klasa_vozila==2)
		{
			putarina=4;
			fprintf(f, "* Putarina: %dKM                      *\n", putarina);
		}
		else if(klasa_vozila==3)
		{
			putarina=6;
			fprintf(f, "* Putarina: %dKM                      *\n", putarina);
		}
		else if(klasa_vozila==4)
		{
			putarina=10;
			fprintf(f, "* Putarina: %-2dKM                     *\n", putarina);
		}
		fprintf(f, "*                                    *\n");
		ukupno=putarina;
		if(putarina!=10)
			fprintf(f, "* Ukupno (KM): %-3.2f                  *\n", (float)ukupno);
		else
			fprintf(f, "* Ukupno (KM): %-3.2f                 *\n", (float)ukupno);
	}
	fprintf(f, "*                                    *\n");
	fprintf(f, "* ================================== *\n");
	fprintf(f, "*      	  Manhattan Solutions	     *\n");
	fprintf(f, "* ======= Hvala! Srecan put! ======= *\n");
	fprintf(f, "**************************************\n");
	evidencija(evidencija_iskljucenje, t, klasa_vozila, putarina, kazna);
}

void evidencija(FILE *evidencija_iskljucenje, SYSTEMTIME t, int klasa_vozila, int putarina, int kazna)
{
	fprintf(evidencija_iskljucenje, "------------------\n");
	fprintf(evidencija_iskljucenje, "Datum: %02d.%02d.%d.\n", t.wDay, t.wMonth, t.wYear);
	fprintf(evidencija_iskljucenje, "Vrijeme: %02d:%02d:%02d\n", t.wHour, t.wMinute, t.wSecond);
	fprintf(evidencija_iskljucenje, "Klasa vozila: %d\n", klasa_vozila);
	if(kazna!=0)
		fprintf(evidencija_iskljucenje, "Kazna (KM): %-3.2f\n", (float)kazna);
	fprintf(evidencija_iskljucenje, "Putarina (KM): %d\n", putarina);
	fprintf(evidencija_iskljucenje, "------------------\n");
}

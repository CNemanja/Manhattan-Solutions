#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include<time.h>
// JA SAM RETARD
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

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<string.h>

#define KORISNICKO_IME "administrator"
#define SIFRA "manhattan2712"

void ukljucenjeDatoteka(FILE *, FILE *);
int randomInkasant();
void formiraj_kIme_sifra(char *);
void evidencija(FILE *, SYSTEMTIME, int);

int main()
{
	char komanda;
	FILE *f=fopen("potvrdaUkljucenje.txt", "w"), *f1; // f otvara tekstualnu datoteku potvrda o ukljucenju u rezimu pisanja
	printf("\n");
	do{
		printf("\n\t\t\t\tEvidencija             - A");
		printf("\n\t\t\t\tPutarina               - B");
		printf("\n\t\t\t\tUputstvo za koriscenje - C");
		printf("\n\t\t\t\tKRAJ                   - 0\n");
		printf("\n\t\t\t\t\t   ");
		komanda=getch();
		if(komanda=='a' || komanda=='A')
		{
			char izbor, korisnicko_ime[21], sifra[21];
			system("cls");
			printf("\n\t\t\t\t   EVIDENCIJA: ");
			printf("\n\t\t\t\t   -----------\n");
			do{
				printf("\n\t\t\t\t Korisnicko ime: ");
				formiraj_kIme_sifra(korisnicko_ime); // Ovdje se formira korisnièko ime. Pored toga, ispisuju se zvjezdice.
				printf("\n\t\t\t\t Sifra: ");
				formiraj_kIme_sifra(sifra); // Isti princip kao kod korisnièkog imena.
				if(strcmp(korisnicko_ime, KORISNICKO_IME)!=0 || strcmp(sifra, SIFRA)!=0) // Ovdje se provjerava da li su korisnièko ime i šifra razlièiti od definisanih.
				{
					/*
					
						Ukoliko se uneseno korisnièko ime i šifra ne poklapaju sa definisanim, ispisuje se sljedeæa poruka;
						Promjenljiva izbor može da bude D kao Da, i N kao Ne;
						Ukoliko izaberemo D, postupak æe se ponoviti, a ukoliko izaberemo N, izlazi se iz petlje i vraæa na poèetni meni.
					
					*/
					printf("\n");
					printf("\n\t\t\t------------------------------------");
					printf("\n\t\t\t|Pogresno korisnicko ime ili sifra!|");
					printf("\n\t\t\t------------------------------------\n");
					printf("\n\t\t\t\t Ponoviti unos?(D/N) ");
					izbor=getch();
					if(izbor=='d' || izbor=='D')
					{
						system("cls");
						printf("\n\t\t\t\t   EVIDENCIJA: ");
						printf("\n\t\t\t\t   -----------\n");
						continue;
					}
					else if(izbor=='n' || izbor=='N')
					{
						system("cls");
						printf("\n");
						break;
					}
					else
					{
						system("cls");
						printf("\n");
						break;
					}
				}
			}while(strcmp(korisnicko_ime, KORISNICKO_IME)!=0 || strcmp(sifra, SIFRA)!=0);
			if(strcmp(korisnicko_ime, KORISNICKO_IME)==0 || strcmp(sifra, SIFRA)==0)
			{
				system("cls");
				system("start Evidencija.txt");  // Ako se šifra i korisnièko ime poklapaju sa unesenim, vrši se otvaranje datoteke Evidencija. U njoj se nalaze svi podaci o ukljuèenju na autoput.
				printf("\n");
			}
		}
		else if(komanda=='b' || komanda=='B')
		{
			system("cls");
			char komanda_putarina;
			do{
				printf("\n\t\t\t\t\tNAPLATNA KUCICA: ");
				printf("\n\t\t\t\t\t----------------\n");
				printf("\n\t\t\t\t Gotovinska naplata putarine - A");
				printf("\n\t\t\t\t Pocetak                     - 0");
				printf("\n\t\t\t\t -------------------------------\n");
				printf("\n\t\t\t\t\t      ");
				komanda_putarina=getch();
				if(komanda_putarina=='a' || komanda_putarina=='A')
				{
					system("cls");
					FILE *vp=fopen("VP.txt", "w"); // Datoteka VP æe nam služiti kao neki posrednik izmeðu konzole ukljuèenja i konzole iskljuèenja. U nju æe se upisati vrijeme putovanja da bismo kasnije u konzoli iskljuèenje mogli utvrditi vrijeme putovanja.
					int timer; // Promjenljiva timer æe nam služiti za smiještanje sluèajno generisanog broja u intervalu od 0 do 30.
					srand((unsigned)time(NULL));
					timer=((rand()%20)+10); // Promjenljivoj timer se vrši dodavanje sluèajno generisanog broja iz prethodno navedenog intervala.
					f1=fopen("Evidencija.txt", "a");
					ukljucenjeDatoteka(f, f1); // Ovdje se vrši izdavanje odnosno ispis potvrde o ukljuèenju na autoput.
					printf("\n\n\n\n\n\n\n\n\t\t\t   Putovanje ce trajati %d minut(a)!", timer);
					fprintf(vp, "%d", timer);
					Sleep(timer*1000); // Funkcija Sleep æe 'uspavati' konzolu na odreðeno vrijeme. To vrijeme je sluèajno generisan broj iz intervala od 0 do 30 pomnožen sa 1000. U tom, konzolu æemo uspavati na nekoliko sekundi. Primjer: 3*1000=3s.
					system("cls");
					system("start Iskljucenje.exe");
					exit(0);
				}
				else if(komanda_putarina!='0')
				{
					system("cls");
					printf("\n\t\t\t\t     ---------------------");
					printf("\n\t\t\t\t     |Komanda ne postoji!|");
					printf("\n\t\t\t\t     |Ponovite unos!     |");
					printf("\n\t\t\t\t     ---------------------\n");
				}	
			}while(komanda_putarina!='0');	
			system("cls");
			printf("\n");
		}
		else if(komanda=='c' || komanda=='C')
		{
			system("cls");
			system("start Uputstvo.txt"); // Izborom komande C, otvara se tekstualna datoteka sa uputstvom.
			printf("\n");
		}
		else if(komanda!='0')
		{
			system("cls");
			printf("\n\t\t\t\t   ---------------------");
			printf("\n\t\t\t\t   |Komanda ne postoji!|");
			printf("\n\t\t\t\t   |Ponovite unos!     |");
			printf("\n\t\t\t\t   ---------------------\n");
		}
	}while(komanda!='0');
	system("cls");
	printf("KRAJ!\n");
	system("pause");
	return 0;
}

int randomInkasant()
{
	// U ovoj funkciji se vrši generisanje sluèajnog broja od 1 do 9.
	srand((unsigned)time(NULL));
	return (rand()%9)+1;
}

void ukljucenjeDatoteka(FILE *f, FILE *f1)
{
	int inkasant;
	SYSTEMTIME t;
	fprintf(f, "**************************************\n");
	fprintf(f, "* ================================== *\n");
	fprintf(f, "*     JAVNO PREDUZECE - MS Putevi    *\n");
	fprintf(f, "* ================================== *\n");
	fprintf(f, "*                                    *\n");
	inkasant=randomInkasant(); // Promjenljivoj inkasant se dodjeljuje sluèajno generisan broj koji je rezultat funkcije randomInkasant().
	fprintf(f, "* Inkasant: %d                        *\n", inkasant);
	fprintf(f, "*                                    *\n");
	GetSystemTime(&t); // Funkcijom GetSystemTime, promjenljivoj t dodjeljuje trenutno vrijeme na sistemu.
	fprintf(f, "* Datum: %02d.%02d.%d.                 *\n", t.wDay, t.wMonth, t.wYear);
	fprintf(f, "*                                    *\n");
	fprintf(f, "* Vrijeme: %02d:%02d:%02d                  *\n", t.wHour+1, t.wMinute, t.wSecond);
	fprintf(f, "*                                    *\n");
	fprintf(f, "* ================================== *\n");
	fprintf(f, "*      	  Manhattan Solutions	     *\n");
	fprintf(f, "* ======= Hvala! Srecan put! ======= *\n");
	fprintf(f, "**************************************\n");
	evidencija(f1, t, inkasant);
}

void evidencija(FILE *f1, SYSTEMTIME t, int inkasant)
{
	fprintf(f1, "-----------------------------\n");
	fprintf(f1, "Datum ukljucenja: %02d.%02d.%d.\n", t.wDay, t.wMonth, t.wYear);
	fprintf(f1, "Inkasant: %d\n", inkasant);
	fprintf(f1, "Vrijeme ukljucenja: %02d:%02d:%02d\n", t.wHour+1, t.wMinute, t.wSecond);
	fprintf(f1, "-----------------------------\n\n");
}

void formiraj_kIme_sifra(char *sifra)
{
	// U funciji formiraj_kIme_sifra se vrši formiranje šifre ili korisnièkog imena s tim da se na konzolu ispisuju zvjezdice kao neki oblik zaštite.
	
	/*
	
		Promjenljivu i postavljam na -1.
		Promjenljiva c æe oèitati uneseni znak sa konzole, odnosno, promjenljivoj c æe se dodijeliti rezultat funkcije getch().
		getch() æe proèitati znak u eho (echo) režimu.
		Koristim while petlju koja je na neki naèin beskonaèna (uslov joj je razlièit od nula (1)).
		Ukoliko je promjenljiva i manja od 0 (a u prvom koraku jeste), promjenljivoj i se dodjeljuje vrijednost 0.
		Promjenljivoj c se dodjeljuje rezultat funkcije getch().
		Ukoliko je uneseni znak Enter, vrši se nasilni izlazak iz petlje.
		Ukoliko je uneseni znak Backspace, promjenljiva i se umanje za 1 i onda dolazi novi uslov.
		Ako je i veæe ili jednako od 0, funkcija printf briše ispisane zvjezdice.
		Ukoliko uneseni znak nije ni Enter ni Backspace, promjenljivoj šifra se dodjeljuje c i ispisuje se zvjezdica.
	
	*/
	
	int i=-1;
	char c;
	while(1)
	{
		if(i<0)
			i=0;
		c=getch();
		if(c==13)
			break;
		if(c==8)
		{
			i--;
			if(i>=0)
				printf("\b \b");
			else
				c=getch();
			if(c==13)
				break;
			else
				continue;
		}
		sifra[i++]=c;
		printf("*");
	}
	sifra[i]='\0';
}

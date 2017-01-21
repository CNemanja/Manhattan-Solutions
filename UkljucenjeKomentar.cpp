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
				formiraj_kIme_sifra(korisnicko_ime); // Ovdje se formira korisni�ko ime. Pored toga, ispisuju se zvjezdice.
				printf("\n\t\t\t\t Sifra: ");
				formiraj_kIme_sifra(sifra); // Isti princip kao kod korisni�kog imena.
				if(strcmp(korisnicko_ime, KORISNICKO_IME)!=0 || strcmp(sifra, SIFRA)!=0) // Ovdje se provjerava da li su korisni�ko ime i �ifra razli�iti od definisanih.
				{
					/*
					
						Ukoliko se uneseno korisni�ko ime i �ifra ne poklapaju sa definisanim, ispisuje se sljede�a poruka;
						Promjenljiva izbor mo�e da bude D kao Da, i N kao Ne;
						Ukoliko izaberemo D, postupak �e se ponoviti, a ukoliko izaberemo N, izlazi se iz petlje i vra�a na po�etni meni.
					
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
				system("start Evidencija.txt");  // Ako se �ifra i korisni�ko ime poklapaju sa unesenim, vr�i se otvaranje datoteke Evidencija. U njoj se nalaze svi podaci o uklju�enju na autoput.
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
					FILE *vp=fopen("VP.txt", "w"); // Datoteka VP �e nam slu�iti kao neki posrednik izme�u konzole uklju�enja i konzole isklju�enja. U nju �e se upisati vrijeme putovanja da bismo kasnije u konzoli isklju�enje mogli utvrditi vrijeme putovanja.
					int timer; // Promjenljiva timer �e nam slu�iti za smije�tanje slu�ajno generisanog broja u intervalu od 0 do 30.
					srand((unsigned)time(NULL));
					timer=((rand()%20)+10); // Promjenljivoj timer se vr�i dodavanje slu�ajno generisanog broja iz prethodno navedenog intervala.
					f1=fopen("Evidencija.txt", "a");
					ukljucenjeDatoteka(f, f1); // Ovdje se vr�i izdavanje odnosno ispis potvrde o uklju�enju na autoput.
					printf("\n\n\n\n\n\n\n\n\t\t\t   Putovanje ce trajati %d minut(a)!", timer);
					fprintf(vp, "%d", timer);
					Sleep(timer*1000); // Funkcija Sleep �e 'uspavati' konzolu na odre�eno vrijeme. To vrijeme je slu�ajno generisan broj iz intervala od 0 do 30 pomno�en sa 1000. U tom, konzolu �emo uspavati na nekoliko sekundi. Primjer: 3*1000=3s.
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
	// U ovoj funkciji se vr�i generisanje slu�ajnog broja od 1 do 9.
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
	inkasant=randomInkasant(); // Promjenljivoj inkasant se dodjeljuje slu�ajno generisan broj koji je rezultat funkcije randomInkasant().
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
	// U funciji formiraj_kIme_sifra se vr�i formiranje �ifre ili korisni�kog imena s tim da se na konzolu ispisuju zvjezdice kao neki oblik za�tite.
	
	/*
	
		Promjenljivu i postavljam na -1.
		Promjenljiva c �e o�itati uneseni znak sa konzole, odnosno, promjenljivoj c �e se dodijeliti rezultat funkcije getch().
		getch() �e pro�itati znak u eho (echo) re�imu.
		Koristim while petlju koja je na neki na�in beskona�na (uslov joj je razli�it od nula (1)).
		Ukoliko je promjenljiva i manja od 0 (a u prvom koraku jeste), promjenljivoj i se dodjeljuje vrijednost 0.
		Promjenljivoj c se dodjeljuje rezultat funkcije getch().
		Ukoliko je uneseni znak Enter, vr�i se nasilni izlazak iz petlje.
		Ukoliko je uneseni znak Backspace, promjenljiva i se umanje za 1 i onda dolazi novi uslov.
		Ako je i ve�e ili jednako od 0, funkcija printf bri�e ispisane zvjezdice.
		Ukoliko uneseni znak nije ni Enter ni Backspace, promjenljivoj �ifra se dodjeljuje c i ispisuje se zvjezdica.
	
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

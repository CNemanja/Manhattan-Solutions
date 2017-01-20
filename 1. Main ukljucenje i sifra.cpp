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
	FILE *f=fopen("potvrdaUkljucenje.txt", "w"), *f1;
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
				formiraj_kIme_sifra(korisnicko_ime);
				printf("\n\t\t\t\t Sifra: ");
				formiraj_kIme_sifra(sifra);
				if(strcmp(korisnicko_ime, KORISNICKO_IME)!=0 || strcmp(sifra, SIFRA)!=0)
				{
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
				system("start Evidencija.txt");
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
					FILE *vp=fopen("VP.txt", "w");
					int timer;
					srand((unsigned)time(NULL));
					timer=((rand()%20)+10);
					f1=fopen("Evidencija.txt", "a");
					ukljucenjeDatoteka(f, f1);
					printf("\n\n\n\n\n\n\n\n\t\t\t   Putovanje ce trajati %d minut(a)!", timer);
					fprintf(vp, "%d", timer);
					Sleep(timer*1000);
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
			system("start Uputstvo.txt");
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

void formiraj_kIme_sifra(char *sifra)
{
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

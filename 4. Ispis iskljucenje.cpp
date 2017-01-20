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

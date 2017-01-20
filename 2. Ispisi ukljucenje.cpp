int randomInkasant()
{
	srand((unsigned)time(NULL));
	return (rand()%9)+1;
}
// BOJIC JE KONJINA
void ukljucenjeDatoteka(FILE *f, FILE *f1)
{
	int inkasant;
	SYSTEMTIME t;
	fprintf(f, "**************************************\n");
	fprintf(f, "* ================================== *\n");
	fprintf(f, "*     JAVNO PREDUZECE - MS Putevi    *\n");
	fprintf(f, "* ================================== *\n");
	fprintf(f, "*                                    *\n");
	inkasant=randomInkasant();
	fprintf(f, "* Inkasant: %d                        *\n", inkasant);
	fprintf(f, "*                                    *\n");
	GetSystemTime(&t);
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

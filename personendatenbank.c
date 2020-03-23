/*
..........................................................................
ITW, H.Hochhaus 03.2020
B. Hoffmann 03.2020

Aufgabenstellung
Erstellen eines Programms zu Verwaltung von Kontaktadressen.

Die Eingabe der Daten soll in einer Funktion erfolgen. Zum wechseln der Eingabe soll der Tabulator genutzt werden und bei Return werden die Daten auf der Festplatte
gespeichert(fwrite). Das Programm soll die Möglichkeit beinhalten schon gespeicherte Daten zu verändern(fseek,fread).
..........................................................................
*/

/*Bibliotheken einbinden*/
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include "myfunctions.c"

/*Konstanten definieren*/
#define MAX 48

/*Struktur deklarieren*/

struct personen
{
	char vname[MAX];
	char nname[MAX];
	char adresse[MAX];
	char gebtag[2];
	char gebmon[2];
	char gebjahr[4];
	char erstesfach[20];
	char zweitesfach[20];
	char drittesfach[20];
	char telefon[16];
	char email[MAX];
};

/*Funktionen deklarieren*/

void menue();
void neuePersonAnlegen(struct personen*);
void datenAuslesen(struct personen*);
void datenLegende();

/*Programmstart*/

int main(void)
{
	//Variablen deklarieren
	char eingabe;
	struct personen pers={"0"}; //={"falko","foerster","Weg 1","Deutsch","Mathe","Englisch"}
	struct personen *persPtr;
	int i,chars;
	
	//intros
	system("cls");
	itwIntro(0,11);
	delay(1000);
	
	//Menü zeichnen
	do
	{
	system("cls");
	farbeWaehlen(6,0);
	gotoxy(15,4);
	printf("\n\n\n\n\t\t[n] Neue Person anlegen");
	printf("\n\n\t\t[a] Datenbank ansehen und bearbeiten");	
	printf("\n\n\t\t[ESC] Programm beenden");
	menue();
	persPtr=&pers;
	eingabe=getch();
	
	if(eingabe=='n')
	{
		system("cls");
		menue();
		neuePersonAnlegen(persPtr);
	}
	
	if(eingabe=='a')
	{
		datenAuslesen(persPtr);
	}
	
	
	} while(eingabe!=27);
	
	//Programm Ende
	farbeWaehlen(3,0);
	gotoxy(12,22);
	return 0;
}

void neuePersonAnlegen(struct personen *persPtr)
{
	FILE *datenbank;
	char auswahl;
	
   	if((datenbank = fopen( "datenbank.txt" , "a" ))==NULL)
	{
		farbeWaehlen(3,0);
		printf("Fehler beim Lesen der Datenbank");
		getch();
		farbeWaehlen(6,0);
	}
	else
	{
		datenLegende();
		gotoxy(8,7);farbeWaehlen(3,0);printf("--------------------------------------------------");farbeWaehlen(6,0);
		gotoxy(20,8);strcpy((*persPtr).vname,eingabeTextTab(MAX-1)); //gets((*persPtr).vname);
		gotoxy(20,9);strcpy((*persPtr).nname,eingabeTextTab(MAX-1));
		gotoxy(20,10);strcpy((*persPtr).adresse,eingabeTextTab(MAX-1));
		gotoxy(20,11);
			printf("TTMMYYYY");printf("%c%c%c%c%c%c%c%c",8,8,8,8,8,8,8,8);
			strcpy((*persPtr).gebtag,eingabeTextTab(2));
			strcpy((*persPtr).gebmon,eingabeTextTab(2));	
			strcpy((*persPtr).gebjahr,eingabeTextTab(4));	
		gotoxy(20,16);
			farbeWaehlen(3,0);printf("\n\n\t[0 Keins]");
			farbeWaehlen(3,0);printf(" [1 Deutsch]");
			farbeWaehlen(3,0);printf(" [2 Englisch]");
			farbeWaehlen(3,0);printf(" [3 Franzoesisch]");
			farbeWaehlen(3,0);printf("\n\t[4 Spanisch]");
			farbeWaehlen(2,0);printf(" [5 Physik]");
			farbeWaehlen(2,0);printf("[6 Mathe]");
			auswahl=getch();
			farbeWaehlen(6,0);
			switch(auswahl)
			{
				case '0': strcpy((*persPtr).erstesfach,"-");gotoxy(20,12);printf("-");break;
				case '1': strcpy((*persPtr).erstesfach,"Deutsch");gotoxy(20,12);printf("Deutsch");break;
				case '2': strcpy((*persPtr).erstesfach,"Englisch");gotoxy(20,12);printf("Englisch");break;
				case '3': strcpy((*persPtr).erstesfach,"Franzoesisch");gotoxy(20,12);printf("Franzoesisch");break;
				case '4': strcpy((*persPtr).erstesfach,"Spanisch");gotoxy(20,12);printf("Spanisch");break;
				case '5': strcpy((*persPtr).erstesfach,"Physik");gotoxy(20,12);printf("Physik");break;
				case '6': strcpy((*persPtr).erstesfach,"Mathe");gotoxy(20,12);printf("Mathe");break;
				default : strcpy((*persPtr).erstesfach,"-");gotoxy(20,12);printf("-");break;
			}
			gotoxy(20,13);		
			auswahl=getch();
			farbeWaehlen(6,0);	
			switch(auswahl)
			{
				case '0': strcpy((*persPtr).zweitesfach,"-");gotoxy(20,13);printf("-");break;
				case '1': strcpy((*persPtr).zweitesfach,"Deutsch");gotoxy(20,13);printf("Deutsch");break;
				case '2': strcpy((*persPtr).zweitesfach,"Englisch");gotoxy(20,13);printf("Englisch");break;
				case '3': strcpy((*persPtr).zweitesfach,"Franzoesisch");gotoxy(20,13);printf("Franzoesisch");break;
				case '4': strcpy((*persPtr).zweitesfach,"Spanisch");gotoxy(20,13);printf("Spanisch");break;
				case '5': strcpy((*persPtr).zweitesfach,"Physik");gotoxy(20,13);printf("Physik");break;
				case '6': strcpy((*persPtr).zweitesfach,"Mathe");gotoxy(20,13);printf("Mathe");break;
				default : strcpy((*persPtr).zweitesfach,"-");gotoxy(20,13);printf("-");break;
			}
			gotoxy(20,14);		
			auswahl=getch();
			farbeWaehlen(6,0);	
			switch(auswahl)
			{
				case '0': strcpy((*persPtr).drittesfach,"-");gotoxy(20,14);printf("-");break;
				case '1': strcpy((*persPtr).drittesfach,"Deutsch");gotoxy(20,14);printf("Deutsch");break;
				case '2': strcpy((*persPtr).drittesfach,"Englisch");gotoxy(20,14);printf("Englisch");break;
				case '3': strcpy((*persPtr).drittesfach,"Franzoesisch");gotoxy(20,14);printf("Franzoesisch");break;
				case '4': strcpy((*persPtr).drittesfach,"Spanisch");gotoxy(20,14);printf("Spanisch");break;
				case '5': strcpy((*persPtr).drittesfach,"Physik");gotoxy(20,14);printf("Physik");break;
				case '6': strcpy((*persPtr).drittesfach,"Mathe");gotoxy(20,14);printf("Mathe");break;
				default : strcpy((*persPtr).drittesfach,"-");gotoxy(20,14);printf("-");break;
			}
			gotoxy(20,15);strcpy((*persPtr).telefon,eingabeTextTab(15));
			gotoxy(20,16);strcpy((*persPtr).email,eingabeTextTab(MAX-1));
			gotoxy(26,21);farbeWaehlen(6,1);printf("\n\t\tEingabe speichern? (j/n)");farbeWaehlen(6,0);
			if((auswahl=getch())=='j') 
			{
				fwrite(persPtr, sizeof(struct personen), 1 , datenbank );
   				fclose(datenbank);
   			} else fclose(datenbank);
	}
}

void datenAuslesen(struct personen *persPtr)
{
	FILE *datenbank = fopen("datenbank.txt", "r");
	char temp,buchstabe=1,sektion=1,eingabe,eingabeBearb=0;
	int zaehler=1,size=0,struktur=1,anz=1;
	
	//Größe der DB ermitteln
	fseek(datenbank, 0, SEEK_END); // seek to end of file
	size = ftell(datenbank); // get current file pointer
	fseek(datenbank, 0, SEEK_SET); // seek back to beginning of file
	anz=size/sizeof(struct personen);

	if((datenbank=fopen("datenbank.txt","r+"))==NULL)
	{
		printf("Fehler beim lesen der Datenbank");
	}
	else
	{
		do
		{
		system("cls");
		datenLegende();
		gotoxy(24,7);
		fseek(datenbank,(struktur-1)*sizeof(struct personen),SEEK_SET);
		zaehler=0;sektion=1;buchstabe=1;
		printf("%d von %2d\n\t\t\t",struktur,anz);
			while(zaehler<sizeof(struct personen))
			{
			temp=fgetc(datenbank);
			zaehler++;
				if(sektion==9)
				{
					putch(temp);
					if(buchstabe>47) {buchstabe=1;printf("\n\t\t\t");sektion++;}
					else buchstabe++;				
				}
				if(sektion==8)
				{
					putch(temp);
					if(buchstabe>15) {buchstabe=1;printf("\n\t\t\t");sektion++;}
					else buchstabe++;				
				}
				if(sektion>4 && sektion<8)
				{	
					putch(temp);
	//				printf("(z%d i%d)\n",z,i);
					if(buchstabe>19) {buchstabe=1;printf("\n\t\t\t");sektion++;}
					else buchstabe++;
					
				}
				if(sektion==4)
				{
					putch(temp);
	//				printf("(z%d_i%d)\n",z,i);
					if(buchstabe>7) {buchstabe=1;printf("\n\t\t\t");sektion++;}
					else buchstabe++;
					
				}
				if(sektion>0 && sektion<4)
				{
					putch(temp);
	//				printf("(z%d_i%d)\n",z,i);
					if(buchstabe>47) {buchstabe=1;printf("\n\t\t\t");sektion++;}
					else buchstabe++;				
				}			
			}
			menue();
			if(struktur>1 && anz>1) {gotoxy(10,18);farbeWaehlen(6,0);printf("<< [v]");} else {gotoxy(10,18);farbeWaehlen(8,0);printf("<< [v]");} 
			if(struktur>=1 && struktur<anz) {gotoxy(51,18);farbeWaehlen(6,0);printf("[n] >>");} else {gotoxy(51,18);farbeWaehlen(8,0);printf("[n] >>");}
			gotoxy(26,18);farbeWaehlen(8,0);printf("[b] bearbeiten");farbeWaehlen(6,0);
			gotoxy(26,19);farbeWaehlen(8,0);printf("[ESC] beenden");farbeWaehlen(6,0);
			eingabe=getch();
				switch(eingabe)
				{
					case 80:break; //runter
					case 'v':if(struktur>1)struktur--;break; //links
					case 'n':if(struktur<anz)struktur++;break; //rechts
					case 'b':
//Daten bearbeiten
						gotoxy(26,18);
						farbeWaehlen(11,0); 
						printf("[b] bearbeiten");
						gotoxy(6,8);printf(">");
						gotoxy(20,22);printf("Diese Zeile bearbeiten? (j/n)");
						eingabeBearb=getch();
						if(eingabeBearb=='j') //Vorname
							{
								fseek(datenbank,(struktur-1)*sizeof(struct personen),SEEK_SET);
								gotoxy(24,8);
								fputs(eingabeTextTab(MAX-1),datenbank);
							}
						gotoxy(6,8);printf(" ");
						gotoxy(6,9);printf(">");
						eingabeBearb=getch();
						if(eingabeBearb=='j') //Nachname
							{
								fseek(datenbank,((struktur-1)*sizeof(struct personen))+48,SEEK_SET);
								gotoxy(24,9);
								fputs(eingabeTextTab(MAX-1),datenbank);
							}
						gotoxy(6,9);printf(" ");
						gotoxy(6,10);printf(">");
						eingabeBearb=getch();
						if(eingabeBearb=='j') //Adresse
							{
								fseek(datenbank,((struktur-1)*sizeof(struct personen))+48+48,SEEK_SET);
								gotoxy(24,10);
								fputs(eingabeTextTab(MAX-1),datenbank);
							}
						gotoxy(6,10);printf(" ");
						gotoxy(6,11);printf(">");
						eingabeBearb=getch();
						if(eingabeBearb=='j') //Geb.Datum
							{
								fseek(datenbank,((struktur-1)*sizeof(struct personen))+48+48+48,SEEK_SET);
								gotoxy(24,11);
								fputs(eingabeTextTab(8),datenbank);
							}
						gotoxy(6,11);printf(" ");
						gotoxy(6,12);printf(">");
						eingabeBearb=getch();
						if(eingabeBearb=='j') //Hauptfach
							{
								fseek(datenbank,((struktur-1)*sizeof(struct personen))+48+48+48+8,SEEK_SET);
								gotoxy(24,12);
								fputs(eingabeTextTab(20),datenbank);
							}
						gotoxy(6,12);printf(" ");
						gotoxy(6,13);printf(">");
						eingabeBearb=getch();
						if(eingabeBearb=='j') //Zweitfach
							{
								fseek(datenbank,((struktur-1)*sizeof(struct personen))+48+48+48+8+20,SEEK_SET);
								gotoxy(24,13);
								fputs(eingabeTextTab(20),datenbank);
							}
						gotoxy(6,13);printf(" ");
						gotoxy(6,14);printf(">");
						eingabeBearb=getch();
						if(eingabeBearb=='j') //Drittfach
							{
								fseek(datenbank,((struktur-1)*sizeof(struct personen))+48+48+48+8+20+20,SEEK_SET);
								gotoxy(24,14);
								fputs(eingabeTextTab(20),datenbank);
							}
						gotoxy(6,14);printf(" ");
						gotoxy(6,15);printf(">");
						eingabeBearb=getch();
						if(eingabeBearb=='j') //Telefon
							{
								fseek(datenbank,((struktur-1)*sizeof(struct personen))+48+48+48+8+20+20+20,SEEK_SET);
								gotoxy(24,15);
								fputs(eingabeTextTab(16),datenbank);
							}
						gotoxy(6,15);printf(" ");
						gotoxy(6,16);printf(">");
						eingabeBearb=getch();
						if(eingabeBearb=='j') //Email
							{
								fseek(datenbank,((struktur-1)*sizeof(struct personen))+48+48+48+8+20+20+20+16,SEEK_SET);
								gotoxy(24,16);
								fputs(eingabeTextTab(MAX-1),datenbank);
							}																				
						break; 
				}
		} while(eingabe!=27);
		fclose(datenbank);
	}	
	fclose(datenbank);			
}

void menue()
{
	farbeWaehlen(3,1);
	RahmenZeichnen(6,2,60,20);
	gotoxy(15,4);
	farbeWaehlen(6,1);
	printf("P E R S O N E N D A T E N B A N K");
	farbeWaehlen(6,0);
}

void datenLegende()
{
		gotoxy(8,7);
		farbeWaehlen(8,0);
		printf("Eintrag #");
		printf("\n\tVorname");
		printf("\n\tNachname");	
		printf("\n\tAdresse");
		printf("\n\tGeburtstag");
		printf("\n\tHauptfach");
		printf("\n\tNebenfach");
		printf("\n\tDrittfach");
		printf("\n\tTelefon");
		printf("\n\tEmail");				
		farbeWaehlen(6,0);
}

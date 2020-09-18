/*Projektni zadatak iz Programiranja
Iva Matetiæ, politehnika
projektni zadatak br.4,zadatak 3
*/


#include <iostream>
#include <string>
using namespace std;
const int MAX = 1000;

struct student{

	long int mbr_indeksa;
	string ime, prezime;
	int god_studija, ECTS;

};

//deklaracije funkcija
void unos(student X[], int n);
void i1(student X[], int n);
void i2(student X[], int n);
void i3(student X[], int n);
void i4(student X[], int n);
void i5(student X[], int n);


int main(){

	student A[MAX];
	int odabir = 1, n;

	cout << "Za koliko studenata unosite podatke? n= ";
	cin >> n;

	unos(A, n);

	do{
		cout << "IZBORNIK" << endl;
		cout << "1.Ispis svih podataka za studente" << endl;
		cout << "2.ispis broja studenata i prosjecnog broja ECTS bodova za studente odredene godine" << endl;
		cout << "3.Ispis imena i prezimena studenata s najanjim brojem ECTS bodova" << endl;
		cout << "4.Ispis prezimen studenata koji imaju više od 50 ECTS bodova posebno za 1.,2.,3.,4. i 5. god" << endl;
		cout << "5.Ispis prezimena i broja indeksa svih studenata ciji je broj bodova u odredenom segmentu[min,max] o studiraju na odredenoj godini" << endl;
		cout << "6.izlaz" << endl;
		cin >> odabir;

		switch (odabir){
		case 1:i1(A, n);
			break;
		case 2:i2(A, n);
			break;
		case 3:i3(A, n);
			break;
		case 4:i4(A, n);
			break;
		case 5:i5(A, n);
			break; 
		}
	} while (odabir != 6);

	system("pause");
	return 0;
}




void unos(student X[], int n){
	int i;

	cout << "Unesi podatke o studentima: " << endl;
	for (i = 0; i < n; i++)
	{
		cout << "Unesi podatke za " << i + 1 << ". studenta: " << endl;
		cout << "mbr indeksa: " << endl;
		cin >> X[i].mbr_indeksa;
		cout << "Ime: " << endl;
		cin >> X[i].ime;
		cout << "Prezime: " << endl;
		cin >> X[i].prezime;
		cout << "Godina studija: " << endl;
		cin >> X[i].god_studija;
		cout << "ECTS bodovi: " << endl;
		cin >> X[i].ECTS;

		cout << endl << endl;
	}

}


void i1(student X[], int n){
	int i;
	cout << "Ispis podataka o studentima: " << endl;
	for (i = 0; i < n; i++)
	{
		cout << "Podaci za " << i + 1 << ". studenta: " << endl;
		cout << "mbr indeksa: " << endl;
		cout << X[i].mbr_indeksa << endl;
		cout << "Ime: " << endl;
		cout << X[i].ime << endl;
		cout << "Prezime: " << endl;
		cout << X[i].prezime << endl;
		cout << "Godina studija: " << endl;
		cout << X[i].god_studija << endl;
		cout << "ECTS bodovi: " << endl;
		cout << X[i].ECTS << endl;

		cout << endl << endl;
	}

}

void i2(student X[], int n){
int i,godina,prosjek,suma=0,b=0;

cout << "Unesi godinu za koju zelis racunati prosjek i broj studenata: " << endl;
cin >> godina;

// petlja u kojoj se računa suma ects-a za sve studente za unesenu godinu 
for (i = 0; i < n; i++)
{
	if (X[i].god_studija == godina){
		suma = suma + X[i].ECTS;
		b++;
	}
}
prosjek = suma / b;
cout << "Broj studenata: " << b << endl;
cout << "Prosjecni broj ECTS bodova: " << prosjek << endl;
cout << endl;
}


void i3(student X[], int n){
	int i,indeks;
	int min=60;


	for (i = 0; i < n; i++)
	{
//provjerava se da li su bodovi studenta manji od min i u tom slučaju se min postavlja na bodove studenta
		if (X[i].ECTS < min)
			min = X[i].ECTS;
			indeks = i;
	}
	cout << "Najmanji broj ECTS bodova je: " << min << endl;
	cout << "Ime i prezime studenta: " << X[indeks].ime<<" "<<X[indeks].prezime<<endl;
	cout << endl;
	
}

void i4(student X[], int n){
	int i;

// unutar petlji ispisuju se prezimena studenata sa više od 50 ECTS-a za pojedine godine studija
	cout << "Studenti 1.god koji imaju vise od 50 ECTS-a: " << endl;
	for (i = 0; i < n; i++)
	{ 
		if (X[i].ECTS>50 && X[i].god_studija==1)
			cout << X[i].prezime;
		cout << endl << endl;
	}

	cout << "Studenti 2.god koji imaju vise od 50 ECTS-a: " << endl;
	for (i = 0; i < n; i++)
	{
		if (X[i].ECTS>50 && X[i].god_studija == 2)
			cout << X[i].prezime;

		cout << endl << endl;
	}

	cout << "Studenti 3.god koji imaju vise od 50 ECTS-a: " << endl;
	for (i = 0; i < n; i++)
	{
		if (X[i].ECTS>50 && X[i].god_studija == 3)
			cout << X[i].prezime;

		cout << endl << endl;
	}

	cout << "Studenti 4.god koji imaju vise od 50 ECTS-a: " << endl;
	for (i = 0; i < n; i++)
	{
		if (X[i].ECTS>50 && X[i].god_studija == 4)
			cout << X[i].prezime;

		cout << endl << endl;
	}

	cout << "Studenti 5.god koji imaju vise od 50 ECTS-a: " << endl;
	for (i = 0; i < n; i++)
	{
		if (X[i].ECTS>50 && X[i].god_studija == 5)
			cout << X[i].prezime;

		cout << endl << endl;
	}
}

void i5(student X[], int n){
	int i,min,max,godina;

//ispis studenata za uneseni segment i godinu	
	cout << "Unesi godinu studija: " << endl;
	cin >> godina;
	cout << "Unesi min: " << endl;
	cin >> min;
	cout << "Unesi max: " << endl;
	cin >> max;
	for (i = 0; i < n; i++)
	{
		if (X[i].ECTS >= min && X[i].ECTS <= max && X[i].god_studija == godina){
			cout << "Prezime: " << X[i].prezime << endl;
			cout << "Indeks: " << X[i].mbr_indeksa << endl;
		}
		cout << endl << endl;
	}

}
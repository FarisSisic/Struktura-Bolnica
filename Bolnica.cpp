#include <iostream>
using namespace std;
//Struktura za bolnicu
struct Bolnica{
	char naziv[50];
	char grad[50];
	int brZaposlenih;
};
//Struktura za odjel
struct Odjel{
	Bolnica bolnica;
	char naziv[50];
	float cijenaPoDanu;
};
//Struktura za pacijenta
struct Pacijent{
	char imePrezime[50];
	Odjel odjel;
	int godiste;
	bool osiguran;
};
	//Funkcija sa unosom podataka sa referencom na p
void unosPacijenta(Pacijent &p){
	cout << "Unijeti ime i prezime pacijenta: ";
	cin.getline(p.imePrezime, 50) ;
	cout << "Unesite naziv bolnice u kojoj je pacijent: ";
	cin.getline(p.odjel.bolnica.naziv, 50);
	cout << "Unesite grad u kojem je bolnica: ";
	cin >> p.odjel.bolnica.grad;
	cout << "Unesite broj zaposlenih u bolnicu: ";
	cin >> p.odjel.bolnica.brZaposlenih;
	cout << "Unesite naziv odjela na kojem je pacijent: ";
	cin >> p.odjel.naziv;
	cout << "Unesite cijenu lezanja jednog dana na odjelu: ";
	cin >> p.odjel.cijenaPoDanu;
	cout << "Unesite godiste pacijenta: ";
	cin >> p.godiste;
	cout << "Da li je osiguran pacijent: \n";
	cout << "0 = NE\n";
	cout << "1 = DA\n";
	cout << "Odabir: ";
	cin >> p.osiguran;
	cout << endl;
}
//Funkcija za ispis podataka koje smo unijeli u funkciju prije 
void ispisPacijenta(Pacijent p){
	cout << "-------------------------" << endl;
	cout << "Ime i prezime pacijenta: " << p.imePrezime << endl;
	cout << "Bolnica: " << p.odjel.bolnica.naziv << " iz grada " << p.odjel.bolnica.grad << ". (" << p.odjel.bolnica.brZaposlenih << ")" << endl;
	cout << "Odjel: " << p.odjel.naziv << " - " << p.odjel.cijenaPoDanu << "KM po danu." << endl;
	cout << "Godina: " << 2023 - p.godiste << endl;
	if(p.osiguran == 1){
		cout << "Osiguran: DA";
	}else if(p.osiguran == 0){
		cout << "Osiguran: NE";
	}
	cout << endl;
	cout << "-------------------------" << endl;
}

float cijena(Odjel odjel, int n){
	if(n==1){
		return odjel.cijenaPoDanu;
	}else{
		return 0.95 * cijena(odjel, n-1);
	}
}


int main(){
	Odjel odjel;
	//Pozivamo strukturu sa Pacijentima
	Pacijent p;
	//Pozivamo funkciju gdje moramo unijeti podatke u funkciju
	unosPacijenta(p);
	//Ispisuje nam podatke koje smo unijeli 
	ispisPacijenta(p);
	int dan;
	cout << "Unesite dan za koji zelite provjeriti cijenu: ";
	cin >> dan;
	float cijena_dana = cijena(odjel, dan);
	cout << "Cijena " << dan << ". dana iznosi: " << cijena_dana << endl;
	cout << endl;
	system("PAUSE");
	return 0;
}

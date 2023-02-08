#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

struct Varaus { // Structi, josta l�ytyy varaukseen liittyv�t tiedot.

	string varaaja;  // Varaajan nimi
	int yot;  // �iden m��r�
	int price;  // Hinta
	int huoneen_numero;  // Huoneen numero
	int huoneidenkokmaara; // Huoneiden kokonaism��r�
	int varausnumero;  // Varausnumero
};


Varaus varaukset[70];  // Taulukko, johon varaukset tallennetaan.
static int laskuri = 1; // Jotta laskuri ei resettaa, kun siirryt��n tekem��n uutta varausta funktiosta l�htemisen j�lkeen


Varaus tarkasteleVarauksia(int kaikki_huoneet) { // Varausten etsimiseen k�ytett�v� funktio.
	Varaus tarkastelu;
	int numero;   // K�ytt�j�n sy�tt�m� huoneen numero.
	int varaus;  // K�ytt�j�n sy�tt�m� varausnumero.
	char syote;  // K�ytt�j�n vastaus menussa.
	string nimi;  // K�ytt�j�n sy�tt�m� varaajan nimi.
	int counter;  // Laskuri, jota k�ytet��n varauksien etsinn�ss�.
	bool virhe;   // Tila, jolla virheest� ilmoitetaan.

	do { // Varausten etsimiseen k�ytett�v� menu.
		cout << "\n----------------------------------------" << endl << endl;
		cout << "*** ETSI VARAUSTA ***" << endl << endl;
		cout << "1. Etsi varaajan nimell�" << endl;
		cout << "2. Etsi huoneen numerolla" << endl;
		cout << "3. Etsi varausnumerolla" << endl;
		cout << "4. Palaa takaisin" << endl;
		cin >> syote;

		counter = 1;

		switch (syote) {

		case '1':

			cout << "\n----------------------------------------" << endl << endl;
			cout << "Syota varaajan nimi: ";
			cin.ignore();
			getline(cin, nimi);

			// Verrataan k�ytt�j�n sy�tt�m�� nime� varaajien nimiin.
			while (counter <= kaikki_huoneet) {
				if (varaukset[counter].varaaja == nimi) {
					cout << "\n----------------------------------------" << endl;
					cout << "\nVARAAJAN '" << nimi << "' TIEDOT:" << endl << endl;
					cout << "Huoneen numero: \t" << varaukset[counter].huoneen_numero << endl;
					cout << "Varausnumero: \t\t" << varaukset[counter].varausnumero << endl;
					cout << "�iden m��r�: \t\t" << varaukset[counter].yot << endl << endl;
					break;	// Jos vastaava nimi l�ytyy, ohjelma poistuu loopista.
				}
				else   // Kasvatetaan counteria yhdell�, kun aikaisempi taulukon paikka on testattu.
					counter++;
			}

			// Jos varauksista ei l�ytynyt vastaavaa varaajan nime�.
			if (varaukset[counter].varaaja != nimi) {
				cout << "\n----------------------------------------" << endl;
				cout << "\nNIMELL� EI L�YTYNYT YHT��N TULOSTA, TARKISTA OIKEINKIRJOITUS" << endl;
			}

			break;

		
		case '2':

			// Sy�tteen tarkistus, kun k�ytt�j�n sy�te ei ole luku tai on 0.
			do
			{
				virhe = false;
				cout << "\n----------------------------------------" << endl;
				cout << "\nSyota huoneen numero: ";
				cin >> numero;
				if (cin.fail() || numero == 0)
				{
					cout << "\n\nVirhe! Anna luku uudestaan." << endl << endl;
					virhe = true;
					cin.clear();
					cin.ignore(80, '\n');
				}
			} while (virhe);

			// Verrataan k�ytt�j�n sy�tt�m�� numeroa eri varausten huonenumeroihin.
			while (counter <= kaikki_huoneet) {
				if (varaukset[counter].huoneen_numero == numero) {
					cout << "\n----------------------------------------" << endl << endl;
					cout << "HUONEEN '" << numero << "' TIEDOT:" << endl << endl;
					cout << "Nimi: \t\t\t" << varaukset[counter].varaaja << endl;
					cout << "Varausnumero: \t\t" << varaukset[counter].varausnumero << endl;
					cout << "�iden m��r�: \t\t" << varaukset[counter].yot << endl;

					break;  // Jos vastaava numero l�ytyy, ohjelma poistuu loopista.
				}
				else  // Kasvatetaan counteria yhdell�, kun aikaisempi taulukon paikka on testattu.
					counter++;
			}
			// Jos huoneen numero on alle 1 tai suurempi kuin huoneiden kokonaism��r�.
			if (numero < 1 || numero > kaikki_huoneet) {
				cout << "\n----------------------------------------" << endl << endl;
				cout << "Virhe! Huonetta '" << numero << "' ei ole." << endl;
			}
			// Jos varauksista ei l�ytynyt vastaavaa huoneen numeroa.
			else if (varaukset[counter].huoneen_numero != numero) {
				cout << "\n----------------------------------------" << endl << endl;
				cout << "HUONE '" << numero << "' ON TYHJ�" << endl;
			}

			break;


		case '3':

			do {   // Sy�tteen tarkistus, jos k�ytt�j�n sy�tt�m� varausnumero ei ole luku tai on 0.
				virhe = false;
				cout << "\n----------------------------------------" << endl;
				cout << "\nSyota varausnumero: ";
				cin >> varaus;
				if (cin.fail() || varaus == 0)
				{
					cout << "\n\nVirhe! Anna luku uudestaan." << endl << endl;
					virhe = true;
					cin.clear();
					cin.ignore(80, '\n');
				}
			} while (virhe);

			// Verrataan k�ytt�j�n sy�tt�m�� numeroa eri varausten varausnumeroihin.
			while (counter <= kaikki_huoneet) {
				if (varaukset[counter].varausnumero == varaus) {
					cout << "\n----------------------------------------" << endl << endl;
					cout << "VARAUSNUMEROLLA '" << varaus << "' L�YDETYT TIEDOT: " << endl << endl;
					cout << "Nimi: \t\t\t" << varaukset[counter].varaaja << endl;
					cout << "Huoneen numero: \t" << varaukset[counter].huoneen_numero << endl;
					cout << "�iden m��r�: \t\t" << varaukset[counter].yot << endl;

					break;  // Jos vastaava numero l�ytyy, ohjelma poistuu loopista.
				}
				else // Kasvatetaan counteria yhdell�, kun aikaisempi taulukon paikka on testattu.
					counter++;
			}
			// Jos varausnumero ei ole v�lill� 10000-99999.
			if (varaus < 10000 || varaus > 99999) {
				cout << "\n----------------------------------------" << endl << endl;
				cout << "Virhe! Varausnumeroa ei ole." << endl;
			}
			// Jos varauksista ei l�ytynyt vastaavaa varausnumeroa.
			else if (varaukset[counter].varausnumero != varaus) {
				cout << "\n----------------------------------------" << endl << endl;
				cout << "VARAUSNUMEROLLA " << varaus << " EI L�YTYNYT VARAUKSIA" << endl;
			}

			break;

		
		case '4':	// Palataan takaisin aloitusvalikkoon.

			return tarkastelu;

			break;

		
		default:  // Kun k�ytt�j�n sy�te on virheellinen.
			cout << "\n\nVirhe! Anna vastaukseksi numero 1, 2, 3 tai 4" << endl << endl;
			
			break;
		}
	} while (syote);
}


// Varausten tekemiseen k�ytett�v� funktio.
Varaus teeVaraus(int hinnoitus, int roomamount) { // Hinnoitus on arvottu hinta/y� ja roomamount on huoneiden kokonaism��r�.

	Varaus satunnainen;
	char input;  // K�ytt�j�n sy�te menussa.
	bool virhe;   // Tila, jolla virheest� ilmoitetaan.

	do {
		cout << "\n----------------------------------------" << endl;
		cout << "\n*** HUONEEN VARAUS ***" << endl << endl;

		// Rajoitetaan huoneiden varaus (huoneiden kokonaism��r�n mukaan).
		// K�ytet��n t�ss�kin global laskuria, jonka arvo kertoo varausten m��r�n.
		if (laskuri > roomamount) {

			cout << "\n*** VALITETTAVASTI KAIKKI HUONEET OVAT VARATTUJA ***";
			return satunnainen;
		}

		srand(time(NULL));   // Tarvitaanotta numerot eiv�t olisi ennaltam��ritellyss� j�rjestyksess�.
		satunnainen.huoneen_numero = rand() % roomamount + 1;	// Satunnaisen huoneen numeron generointi.
		satunnainen.varausnumero = rand() % 89999 + 10000;		// Satunnaisen varausnumeron generointi.

		// Estet��n duplikaatit vertailemalla uutta huoneen numeroa ja varausnumeroa taulukosta l�ytyviin numeroihin.
		for (int h = 0; h <= roomamount; h++) {
			if (varaukset[h].huoneen_numero == satunnainen.huoneen_numero) {
				srand(time(NULL));
				satunnainen.huoneen_numero = rand() % roomamount + 1;
				h = 0;
			}
			if (varaukset[h].varausnumero == satunnainen.varausnumero) {
				srand(time(NULL));
				satunnainen.varausnumero = rand() % 89999 + 10000;
				h = 0;
			}

		}

		cout << "Huoneesi numero on " << satunnainen.huoneen_numero << "." << endl;
		cout << "Varausnumerosi on " << satunnainen.varausnumero << "." << endl;
		cout << "Hinta on " << hinnoitus << " euroa y�lt�." << endl << endl;

		cout << "Anna nimesi: ";
		cin.ignore();
		getline(cin, satunnainen.varaaja);

		// Sy�tteen tarkistus, jos sy�tet��n jokin merkki, joka ei ole numero tai sy�te on 0 tai pienempi.
		do
		{
			virhe = false;
			cout << "Anna �iden m��r� : ";
			cin >> satunnainen.yot;
			if (cin.fail() || satunnainen.yot <= 0)
			{
				cout << "\n\nVirhe! Anna luku uudestaan." << endl << endl << endl;
				virhe = true;
				cin.clear();
				cin.ignore(80, '\n');
			}
		} while (virhe);

		cout << "\nKokonaishinta on: " << satunnainen.yot * hinnoitus << " euroa." << endl << endl;

		do {
			// Voidaan jatkaa varaamista tai palata takaisin aloitusvalikkoon.
			cout << "----------------------------------------" << endl << endl;
			cout << "*** HALUATKO VARATA LIS�� HUONEITA? ***" << endl << endl;
			cout << "1. Kyll�" << endl;
			cout << "2. Ei (Palaa takaisin)" << endl;
			cin >> input;

			switch (input) {
			
			case '1':   // Kun k�ytt�j� haluaa jatkaa varaamista.
				cout << "\n----------------------------------------" << endl << endl;
				cout << "YHTEENVETO AIEMMASTA VARAUKSESTA:" << endl << endl;
				cout << "Varaaja: \t\t" << satunnainen.varaaja << endl;
				cout << "Varausnumero: \t\t" << satunnainen.varausnumero << endl;
				cout << "Huoneen numero: \t" << satunnainen.huoneen_numero << endl;
				cout << "�iden m��r�: \t\t" << satunnainen.yot << endl;
				cout << "Kokonaishinta: \t\t" << satunnainen.yot * hinnoitus << " euroa." << endl;

				varaukset[laskuri] = satunnainen;   // Sijoitetaan varauksen tiedot global laskurin paikalle taulukkoon.
				laskuri++;   // Kasvatetaan laskurin arvoa jokaisen varauksen yhteydess�.

				break;

			
			case '2':   // Kun k�ytt�j� ei halua jatkaa varausta.
				cout << "\n----------------------------------------" << endl << endl;
				cout << "YHTEENVETO:" << endl << endl;
				cout << "Varaaja: \t\t" << satunnainen.varaaja << endl;
				cout << "Varausnumero: \t\t" << satunnainen.varausnumero << endl;
				cout << "Huoneen numero: \t" << satunnainen.huoneen_numero << endl;
				cout << "�iden m��r�: \t\t" << satunnainen.yot << endl;
				cout << "Kokonaishinta: \t\t" << satunnainen.yot * hinnoitus << " euroa." << endl;

				varaukset[laskuri] = satunnainen;   // Sijoitetaan varauksen tiedot global laskurin paikalle taulukkoon.
				laskuri++;   // Kasvatetaan laskurin arvoa jokaisen varauksen yhteydess�.

				return satunnainen;
				
				break;

			
			default: // Ilmoitus virheest�, kun k�ytt�j� sy�tt�� v��r�n merkin.
				cout << "\n\nVirhe! Anna vastaukseksi numero 1 tai 2." << endl << endl << endl;
				
				break;
			}
		} while (input != '1');  // Kun k�ytt�j� sy�tt�� merkin 1, pienempi do-while looppi keskeytyy ja isompi alkaa alusta.

	} while (input != '2');

}



int main() {
	setlocale(LC_ALL, "FI_fi");   // ��kk�set k�ytt��n.
	Varaus varaus;
	char valinta;  // K�ytt�j�n sy�te menussa.


	// Arvotaan hinta ja huoneiden kokonaism��r�.

	srand(time(NULL));  // Tarvitaan, jotta arvotut numerot olisivat jokaisella suorituskerralla eri.
	varaus.price = rand() % 20 + 80;    // Arvotaan hinta per y� v�lilt� 80-100 euroa.
	varaus.huoneidenkokmaara = rand() % 40 + 30;  // Arvotaan huoneiden maksimim��r� v�lilt� 30-70.
	
	// Tallennetaan arvotut tiedot pysyviin muuttujiin.
	const int hinta = varaus.price;
	const int totalRoom = varaus.huoneidenkokmaara;


	cout << "TERVETULOA HOTELLIMME VARAUSOHJELMAAN!";  // Aloitusviesti.

	// Aloitusvalikko.

	do {
		cout << "\n----------------------------------------" << endl;
		cout << "\n*** MIT� HALUAT TEHD�? ***" << endl << endl;
		cout << "1. Tee varaus" << endl;
		cout << "2. Tarkastele varauksia" << endl;
		cout << "3. Huoneiden m��r�" << endl;
		cout << "4. Poistu" << endl;
		cin >> valinta;

			switch (valinta) {

			case '1':
				// Varausten tekemiseen k�ytett�v� funktio.
				// Vied��n mukana arvottu hinta ja huoneiden kokonaism��r�.
				teeVaraus(hinta, totalRoom);

				break;

			
			case '2':
				// Kutsutaan varausten tarkasteluun k�ytetty� funktiota.
				// Vied��n funktioon huoneiden arvottu kokon�ism��r�.
				tarkasteleVarauksia(totalRoom);

				break;

			
			case '3':
				// Lasketaan varattujen huoneiden m��r� laskurilla, joka kasvaa huoneita varatessa.
				// V�hennet��n 1, koska laskuri alkaa numerosta 1, vaikka varauksia ei olisi tehty.
				cout << "\n----------------------------------------" << endl << endl;
				cout << "HUONEITA ON VARATTAVISSA: " << (totalRoom - (laskuri - 1)) << " / " << totalRoom << endl;  

				break;

			
			case '4':

				cout << "\n----------------------------------------" << endl << endl;
				cout << "*** N�KEMIIN! ***" << endl << endl;   // Lopetusviesti.

				return 0;

			
			default: // Virheilmoitus, kun k�ytt�j�n sy�te on virheellinen eli aina, kun mik��n caseista ei toteudu.
				cout << "\n\nVirhe! Anna vastaukseksi numero 1, 2, 3 tai 4." << endl << endl;
				
				break;
			}

	} while (valinta != '4'); 

	return 0;
}

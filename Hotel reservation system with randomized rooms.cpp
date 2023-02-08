#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

struct Varaus { // Structi, josta löytyy varaukseen liittyvät tiedot.

	string varaaja;  // Varaajan nimi
	int yot;  // Öiden määrä
	int price;  // Hinta
	int huoneen_numero;  // Huoneen numero
	int huoneidenkokmaara; // Huoneiden kokonaismäärä
	int varausnumero;  // Varausnumero
};


Varaus varaukset[70];  // Taulukko, johon varaukset tallennetaan.
static int laskuri = 1; // Jotta laskuri ei resettaa, kun siirrytään tekemään uutta varausta funktiosta lähtemisen jälkeen


Varaus tarkasteleVarauksia(int kaikki_huoneet) { // Varausten etsimiseen käytettävä funktio.
	Varaus tarkastelu;
	int numero;   // Käyttäjän syöttämä huoneen numero.
	int varaus;  // Käyttäjän syöttämä varausnumero.
	char syote;  // Käyttäjän vastaus menussa.
	string nimi;  // Käyttäjän syöttämä varaajan nimi.
	int counter;  // Laskuri, jota käytetään varauksien etsinnässä.
	bool virhe;   // Tila, jolla virheestä ilmoitetaan.

	do { // Varausten etsimiseen käytettävä menu.
		cout << "\n----------------------------------------" << endl << endl;
		cout << "*** ETSI VARAUSTA ***" << endl << endl;
		cout << "1. Etsi varaajan nimellä" << endl;
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

			// Verrataan käyttäjän syöttämää nimeä varaajien nimiin.
			while (counter <= kaikki_huoneet) {
				if (varaukset[counter].varaaja == nimi) {
					cout << "\n----------------------------------------" << endl;
					cout << "\nVARAAJAN '" << nimi << "' TIEDOT:" << endl << endl;
					cout << "Huoneen numero: \t" << varaukset[counter].huoneen_numero << endl;
					cout << "Varausnumero: \t\t" << varaukset[counter].varausnumero << endl;
					cout << "Öiden määrä: \t\t" << varaukset[counter].yot << endl << endl;
					break;	// Jos vastaava nimi löytyy, ohjelma poistuu loopista.
				}
				else   // Kasvatetaan counteria yhdellä, kun aikaisempi taulukon paikka on testattu.
					counter++;
			}

			// Jos varauksista ei löytynyt vastaavaa varaajan nimeä.
			if (varaukset[counter].varaaja != nimi) {
				cout << "\n----------------------------------------" << endl;
				cout << "\nNIMELLÄ EI LÖYTYNYT YHTÄÄN TULOSTA, TARKISTA OIKEINKIRJOITUS" << endl;
			}

			break;

		
		case '2':

			// Syötteen tarkistus, kun käyttäjän syöte ei ole luku tai on 0.
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

			// Verrataan käyttäjän syöttämää numeroa eri varausten huonenumeroihin.
			while (counter <= kaikki_huoneet) {
				if (varaukset[counter].huoneen_numero == numero) {
					cout << "\n----------------------------------------" << endl << endl;
					cout << "HUONEEN '" << numero << "' TIEDOT:" << endl << endl;
					cout << "Nimi: \t\t\t" << varaukset[counter].varaaja << endl;
					cout << "Varausnumero: \t\t" << varaukset[counter].varausnumero << endl;
					cout << "Öiden määrä: \t\t" << varaukset[counter].yot << endl;

					break;  // Jos vastaava numero löytyy, ohjelma poistuu loopista.
				}
				else  // Kasvatetaan counteria yhdellä, kun aikaisempi taulukon paikka on testattu.
					counter++;
			}
			// Jos huoneen numero on alle 1 tai suurempi kuin huoneiden kokonaismäärä.
			if (numero < 1 || numero > kaikki_huoneet) {
				cout << "\n----------------------------------------" << endl << endl;
				cout << "Virhe! Huonetta '" << numero << "' ei ole." << endl;
			}
			// Jos varauksista ei löytynyt vastaavaa huoneen numeroa.
			else if (varaukset[counter].huoneen_numero != numero) {
				cout << "\n----------------------------------------" << endl << endl;
				cout << "HUONE '" << numero << "' ON TYHJÄ" << endl;
			}

			break;


		case '3':

			do {   // Syötteen tarkistus, jos käyttäjän syöttämä varausnumero ei ole luku tai on 0.
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

			// Verrataan käyttäjän syöttämää numeroa eri varausten varausnumeroihin.
			while (counter <= kaikki_huoneet) {
				if (varaukset[counter].varausnumero == varaus) {
					cout << "\n----------------------------------------" << endl << endl;
					cout << "VARAUSNUMEROLLA '" << varaus << "' LÖYDETYT TIEDOT: " << endl << endl;
					cout << "Nimi: \t\t\t" << varaukset[counter].varaaja << endl;
					cout << "Huoneen numero: \t" << varaukset[counter].huoneen_numero << endl;
					cout << "Öiden määrä: \t\t" << varaukset[counter].yot << endl;

					break;  // Jos vastaava numero löytyy, ohjelma poistuu loopista.
				}
				else // Kasvatetaan counteria yhdellä, kun aikaisempi taulukon paikka on testattu.
					counter++;
			}
			// Jos varausnumero ei ole välillä 10000-99999.
			if (varaus < 10000 || varaus > 99999) {
				cout << "\n----------------------------------------" << endl << endl;
				cout << "Virhe! Varausnumeroa ei ole." << endl;
			}
			// Jos varauksista ei löytynyt vastaavaa varausnumeroa.
			else if (varaukset[counter].varausnumero != varaus) {
				cout << "\n----------------------------------------" << endl << endl;
				cout << "VARAUSNUMEROLLA " << varaus << " EI LÖYTYNYT VARAUKSIA" << endl;
			}

			break;

		
		case '4':	// Palataan takaisin aloitusvalikkoon.

			return tarkastelu;

			break;

		
		default:  // Kun käyttäjän syöte on virheellinen.
			cout << "\n\nVirhe! Anna vastaukseksi numero 1, 2, 3 tai 4" << endl << endl;
			
			break;
		}
	} while (syote);
}


// Varausten tekemiseen käytettävä funktio.
Varaus teeVaraus(int hinnoitus, int roomamount) { // Hinnoitus on arvottu hinta/yö ja roomamount on huoneiden kokonaismäärä.

	Varaus satunnainen;
	char input;  // Käyttäjän syöte menussa.
	bool virhe;   // Tila, jolla virheestä ilmoitetaan.

	do {
		cout << "\n----------------------------------------" << endl;
		cout << "\n*** HUONEEN VARAUS ***" << endl << endl;

		// Rajoitetaan huoneiden varaus (huoneiden kokonaismäärän mukaan).
		// Käytetään tässäkin global laskuria, jonka arvo kertoo varausten määrän.
		if (laskuri > roomamount) {

			cout << "\n*** VALITETTAVASTI KAIKKI HUONEET OVAT VARATTUJA ***";
			return satunnainen;
		}

		srand(time(NULL));   // Tarvitaanotta numerot eivät olisi ennaltamääritellyssä järjestyksessä.
		satunnainen.huoneen_numero = rand() % roomamount + 1;	// Satunnaisen huoneen numeron generointi.
		satunnainen.varausnumero = rand() % 89999 + 10000;		// Satunnaisen varausnumeron generointi.

		// Estetään duplikaatit vertailemalla uutta huoneen numeroa ja varausnumeroa taulukosta löytyviin numeroihin.
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
		cout << "Hinta on " << hinnoitus << " euroa yöltä." << endl << endl;

		cout << "Anna nimesi: ";
		cin.ignore();
		getline(cin, satunnainen.varaaja);

		// Syötteen tarkistus, jos syötetään jokin merkki, joka ei ole numero tai syöte on 0 tai pienempi.
		do
		{
			virhe = false;
			cout << "Anna öiden määrä : ";
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
			cout << "*** HALUATKO VARATA LISÄÄ HUONEITA? ***" << endl << endl;
			cout << "1. Kyllä" << endl;
			cout << "2. Ei (Palaa takaisin)" << endl;
			cin >> input;

			switch (input) {
			
			case '1':   // Kun käyttäjä haluaa jatkaa varaamista.
				cout << "\n----------------------------------------" << endl << endl;
				cout << "YHTEENVETO AIEMMASTA VARAUKSESTA:" << endl << endl;
				cout << "Varaaja: \t\t" << satunnainen.varaaja << endl;
				cout << "Varausnumero: \t\t" << satunnainen.varausnumero << endl;
				cout << "Huoneen numero: \t" << satunnainen.huoneen_numero << endl;
				cout << "Öiden määrä: \t\t" << satunnainen.yot << endl;
				cout << "Kokonaishinta: \t\t" << satunnainen.yot * hinnoitus << " euroa." << endl;

				varaukset[laskuri] = satunnainen;   // Sijoitetaan varauksen tiedot global laskurin paikalle taulukkoon.
				laskuri++;   // Kasvatetaan laskurin arvoa jokaisen varauksen yhteydessä.

				break;

			
			case '2':   // Kun käyttäjä ei halua jatkaa varausta.
				cout << "\n----------------------------------------" << endl << endl;
				cout << "YHTEENVETO:" << endl << endl;
				cout << "Varaaja: \t\t" << satunnainen.varaaja << endl;
				cout << "Varausnumero: \t\t" << satunnainen.varausnumero << endl;
				cout << "Huoneen numero: \t" << satunnainen.huoneen_numero << endl;
				cout << "Öiden määrä: \t\t" << satunnainen.yot << endl;
				cout << "Kokonaishinta: \t\t" << satunnainen.yot * hinnoitus << " euroa." << endl;

				varaukset[laskuri] = satunnainen;   // Sijoitetaan varauksen tiedot global laskurin paikalle taulukkoon.
				laskuri++;   // Kasvatetaan laskurin arvoa jokaisen varauksen yhteydessä.

				return satunnainen;
				
				break;

			
			default: // Ilmoitus virheestä, kun käyttäjä syöttää väärän merkin.
				cout << "\n\nVirhe! Anna vastaukseksi numero 1 tai 2." << endl << endl << endl;
				
				break;
			}
		} while (input != '1');  // Kun käyttäjä syöttää merkin 1, pienempi do-while looppi keskeytyy ja isompi alkaa alusta.

	} while (input != '2');

}



int main() {
	setlocale(LC_ALL, "FI_fi");   // Ääkköset käyttöön.
	Varaus varaus;
	char valinta;  // Käyttäjän syöte menussa.


	// Arvotaan hinta ja huoneiden kokonaismäärä.

	srand(time(NULL));  // Tarvitaan, jotta arvotut numerot olisivat jokaisella suorituskerralla eri.
	varaus.price = rand() % 20 + 80;    // Arvotaan hinta per yö väliltä 80-100 euroa.
	varaus.huoneidenkokmaara = rand() % 40 + 30;  // Arvotaan huoneiden maksimimäärä väliltä 30-70.
	
	// Tallennetaan arvotut tiedot pysyviin muuttujiin.
	const int hinta = varaus.price;
	const int totalRoom = varaus.huoneidenkokmaara;


	cout << "TERVETULOA HOTELLIMME VARAUSOHJELMAAN!";  // Aloitusviesti.

	// Aloitusvalikko.

	do {
		cout << "\n----------------------------------------" << endl;
		cout << "\n*** MITÄ HALUAT TEHDÄ? ***" << endl << endl;
		cout << "1. Tee varaus" << endl;
		cout << "2. Tarkastele varauksia" << endl;
		cout << "3. Huoneiden määrä" << endl;
		cout << "4. Poistu" << endl;
		cin >> valinta;

			switch (valinta) {

			case '1':
				// Varausten tekemiseen käytettävä funktio.
				// Viedään mukana arvottu hinta ja huoneiden kokonaismäärä.
				teeVaraus(hinta, totalRoom);

				break;

			
			case '2':
				// Kutsutaan varausten tarkasteluun käytettyä funktiota.
				// Viedään funktioon huoneiden arvottu kokonäismäärä.
				tarkasteleVarauksia(totalRoom);

				break;

			
			case '3':
				// Lasketaan varattujen huoneiden määrä laskurilla, joka kasvaa huoneita varatessa.
				// Vähennetään 1, koska laskuri alkaa numerosta 1, vaikka varauksia ei olisi tehty.
				cout << "\n----------------------------------------" << endl << endl;
				cout << "HUONEITA ON VARATTAVISSA: " << (totalRoom - (laskuri - 1)) << " / " << totalRoom << endl;  

				break;

			
			case '4':

				cout << "\n----------------------------------------" << endl << endl;
				cout << "*** NÄKEMIIN! ***" << endl << endl;   // Lopetusviesti.

				return 0;

			
			default: // Virheilmoitus, kun käyttäjän syöte on virheellinen eli aina, kun mikään caseista ei toteudu.
				cout << "\n\nVirhe! Anna vastaukseksi numero 1, 2, 3 tai 4." << endl << endl;
				
				break;
			}

	} while (valinta != '4'); 

	return 0;
}

#include "Tyontekija.hpp"

/*	Santeri Hetekivi 1202466 13I220B
 * 	Olio-ohjelmointi 5G00BM44-3002
  */

//Rakentajat
Tyontekija::Tyontekija() :
Henkilo(), palkka_(0.00), tunnus_("")
{
	cout << "Tyontekijan oletusrakentaja" << endl;
}

Tyontekija::Tyontekija(string etunimi, string sukunimi, string osoite, string puhelinnumero, double palkka, string tunnus) :
Henkilo(etunimi,sukunimi,osoite,puhelinnumero), palkka_(palkka), tunnus_(tunnus)
{
	cout << "Tyontekijan parametrillista rakentaja" << endl;
}

Tyontekija::Tyontekija(const Tyontekija &tyontekija) : 
Henkilo(tyontekija), palkka_(tyontekija.palkka_), tunnus_(tyontekija.tunnus_)
{
	cout << "Tyontekijan kopiorakentaja" << endl;
}

//Purkaja
Tyontekija::~Tyontekija()
{
	cout << "Tyontekijan purkaja" << endl;
}

// Sijoitusoperaattori
Tyontekija& Tyontekija::operator =(const Tyontekija& vanha)
{
	if (this != &vanha)
	{ // Jos ei sijoiteta itseen
		Henkilo::operator = (vanha);
		tunnus_ = vanha.tunnus_; // Sijoita
		palkka_ = vanha.palkka_;
	}
	return *this;
}

//Setterit ja Getterit
void Tyontekija::asetaPalkka(double palkka)
{
	palkka_ = palkka;
}

double Tyontekija::annaPalkka() const
{
	return palkka_;
}

void Tyontekija::asetaTunnus(string tunnus)
{
	tunnus_ = tunnus;
}

string Tyontekija::annaTunnus() const
{
	return tunnus_;
}

//Julkiset funktiot
void Tyontekija::kysyTiedot()	//Kysytään käyttäjältä tiedot
{
	Henkilo::kysyTiedot();
	cout << "Palkka:           ";
	palkka_ = hankiDouble_();
	cout << "Tunnus:           ";
	getline(cin, tunnus_);
}

void Tyontekija::tulosta() const	//Tulostetaan tiedot
{
	Henkilo::tulosta();
	cout << "Palkka:           " << palkka_ << endl;
	cout << "Tunnus:           " << tunnus_ << endl;
}

//Yksityiset funktiot
double Tyontekija::hankiDouble_() const	//Hankitaan käyttäjältä double
{
	//Määritetään string ja double muuttujat
	string sisaantulo = "";
	double numero = 0.00;
	while (true)
	{
		//Hankitaan string käyttäjältä
		getline(cin, sisaantulo);
		// Muutetaan string numeroksi turvallisesti
		stringstream myStream(sisaantulo);
		if (myStream >> numero)
		{
			break;
		}
		//Ilmoitetaan virheellisetä numerosta
		cout << "Virheellinen Numero !" << endl;
		cout << "Uudelleen:         ";
	}
	return numero;
}


#include "Opiskelija.hpp"

/*	Santeri Hetekivi 1202466 13I220B
 * 	Olio-ohjelmointi 5G00BM44-3002
  */

//Rakentajat
Opiskelija::Opiskelija() :
Henkilo(), opiskelijanumero_("")
{
	cout << "Opiskelijan oletusrakentaja" << endl;
}

Opiskelija::Opiskelija(string etunimi, string sukunimi, string osoite, string puhelinnumero, string opiskelijanumero) :
Henkilo(etunimi, sukunimi, osoite, puhelinnumero), opiskelijanumero_(opiskelijanumero)
{
	cout << "Opiskelijan parametrillista rakentaja" << endl;
}

Opiskelija::Opiskelija(const Opiskelija &opiskelija) :
Henkilo(opiskelija),opiskelijanumero_(opiskelija.opiskelijanumero_)
{
	cout << "Opiskelijan kopiorakentaja" << endl;
}

//Purkaja
Opiskelija::~Opiskelija()
{
	cout << "Opiskelijan purkaja" << endl;
}

// Sijoitusoperaattori
Opiskelija& Opiskelija::operator =(const Opiskelija& vanha)
{
	if (this != &vanha)
	{ // Jos ei sijoiteta itseen
		Henkilo::operator = (vanha);
		opiskelijanumero_ = vanha.opiskelijanumero_; // Sijoita
	}
	return *this;
}

//Setterit ja Getterit
void Opiskelija::asetaOpiskelijanumero(string opiskelijanumero)
{
	opiskelijanumero_ = opiskelijanumero;
}

string Opiskelija::annaOpiskelijanumero() const
{
	return opiskelijanumero_;
}

//Julkiset funktiot
void Opiskelija::kysyTiedot()	//Kysytään käyttäjältä tiedot
{
	Henkilo::kysyTiedot();
	cout << "Opiskelijanumero: ";
	getline(cin, opiskelijanumero_);
}

void Opiskelija::tulosta() const	//Tulostetaan tiedot
{
	Henkilo::tulosta();
	cout << "Opiskelijanumero: " << opiskelijanumero_ << endl;
}


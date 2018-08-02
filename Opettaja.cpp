#include "Opettaja.hpp"

/*	Santeri Hetekivi 1202466 13I220B
 * 	Olio-ohjelmointi 5G00BM44-3002
  */

//Rakentajat
Opettaja::Opettaja() :
Tyontekija(),opetusala_("")
{
	cout << "Opettajan oletusrakentaja" << endl;
}

Opettaja::Opettaja(string etunimi, string sukunimi, string osoite, string puhelinnumero, double palkka, string tunnus, string opetusala) :
Tyontekija(etunimi, sukunimi, osoite, puhelinnumero, palkka, tunnus), opetusala_(opetusala)
{
	cout << "Opettajan parametrillista rakentaja" << endl;
}

Opettaja::Opettaja(const Opettaja &opettaja):
Tyontekija(opettaja), opetusala_(opettaja.opetusala_)
{
	cout << "Opettajan kopiorakentaja" << endl;
}

Opettaja::~Opettaja()
{
	cout << "Opettajan purkaja" << endl;
}

// Sijoitusoperaattori
Opettaja& Opettaja::operator =(const Opettaja& vanha)
{
	if (this != &vanha)
	{ // Jos ei sijoiteta itseen
		Tyontekija::operator = (vanha);
		opetusala_ = vanha.opetusala_; // Sijoita
	}
	return *this;
}

//Setterit ja Getterit
void Opettaja::asetaOpetusala(string opetusala)
{
	opetusala_ = opetusala;
}

string Opettaja::annaOpetusala() const
{
	return opetusala_;
}

//Julkiset funtiot
void Opettaja::kysyTiedot()	//Kysytään käyttäjältä tiedot
{
	Tyontekija::kysyTiedot();
	cout << "Opetusala:        ";
	getline(cin, opetusala_);
}

void Opettaja::tulosta() const	//Tulostetaan tiedot
{
	Tyontekija::tulosta();
	cout << "Opetusala:        " << opetusala_ << endl;
}


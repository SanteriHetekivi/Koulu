#include "Henkilo.hpp"
#include <locale.h> 


/*	Santeri Hetekivi 1202466 13I220B
 * 	Olio-ohjelmointi 5G00BM44-3002
  */

//Rakentajat
Henkilo::Henkilo() :
etunimi_(""), sukunimi_(""), osoite_(""), puhelinnumero_("")
{
	cout << "Henkilon oletusrakentaja" << endl;
}

Henkilo::Henkilo(string etunimi, string sukunimi, string osoite, string puhelinnumero) :
etunimi_(etunimi), sukunimi_(sukunimi), osoite_(osoite), puhelinnumero_(puhelinnumero)
{
	cout << "Henkilon parametrillista rakentaja" << endl;
}

Henkilo::Henkilo(const Henkilo &henkilo) :
etunimi_(henkilo.etunimi_), sukunimi_(henkilo.sukunimi_), osoite_(henkilo.osoite_), puhelinnumero_(henkilo.puhelinnumero_)
{
	cout << "Henkilon kopiorakentaja" << endl;
}

//Purkaja
Henkilo::~Henkilo()
{
	cout << "Henkilon purkaja" << endl;
}

// Sijoitusoperaattori
Henkilo& Henkilo::operator =(const Henkilo& vanha)
{
	if (this != &vanha)
	{ // Jos ei sijoiteta itseen
		etunimi_ = vanha.etunimi_; // Sijoita
		sukunimi_ = vanha.sukunimi_;
		osoite_ = vanha.osoite_;
		puhelinnumero_ = vanha.puhelinnumero_;
	}
	return *this;
}
//Setterit ja Getterit
void Henkilo::asetaEtunimi(string etunimi)
{
	etunimi_ = etunimi;
}

string Henkilo::annaEtunimi() const
{
	return etunimi_;
}

void Henkilo::asetaSukunimi(string sukunimi)
{
	sukunimi_ = sukunimi;
}

string Henkilo::annaSukunimi() const
{
	return sukunimi_;
}

void Henkilo::asetaOsoite(string osoite)
{
	osoite_ = osoite;
}

string Henkilo::annaOsoite() const
{
	return osoite_;
}

void Henkilo::asetaPuhelinnumero(string puhelinnumero)
{
	puhelinnumero_ = puhelinnumero;
}

string Henkilo::annaPuhelinnumero() const
{
	return puhelinnumero_;
}

//Julkiset funtiot
void Henkilo::kysyTiedot()	//Kysytään käyttäjältä tiedot
{
	cout << "Etunimi:          ";
	getline(cin, etunimi_);
	cout << "Sukunimi:         ";
	getline(cin, sukunimi_);
	cout << "Osoite:           ";
	getline(cin, osoite_);
	cout << "Puhelinnumero:    ";
	getline(cin, puhelinnumero_);

}

void Henkilo::tulosta() const	//Tulostetaan tiedot
{
	cout << "Etunimi:          " << etunimi_ << endl;
	cout << "Sukunimi:         " << sukunimi_ << endl;
	cout << "Osoite:           " << osoite_ << endl;
	cout << "Puhelinnumero:    " << puhelinnumero_ << endl;

}

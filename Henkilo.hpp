#ifndef HENKILO_HPP
#define HENKILO_HPP

#include <iostream>
#include <string>
#include <sstream>

/*	Santeri Hetekivi 1202466 13I220B
 * 	Olio-ohjelmointi 5G00BM44-3002
  */

using std::string;
using std::cout;
using std::endl;
using std::getline;
using std::cin;
using std::stringstream;

class Henkilo
{
public:
	//Rakentajat
	Henkilo();
	Henkilo(string, string, string, string);
	Henkilo(const Henkilo &);
	//Purkaja
	~Henkilo();
	//Sioitusoperaattori
	Henkilo& operator =(const Henkilo&);
	//Setterit ja Getterit
	void asetaEtunimi(string);
	string annaEtunimi() const;
	void asetaSukunimi(string);
	string annaSukunimi() const;
	void asetaOsoite(string);
	string annaOsoite() const;
	void asetaPuhelinnumero(string);
	string annaPuhelinnumero() const;
	//Julkiset funktiot
	void kysyTiedot();
	void tulosta() const;
private:
	//Yksityiset muuttujat
	string etunimi_;
	string sukunimi_;
	string osoite_;
	string puhelinnumero_;
};
#endif


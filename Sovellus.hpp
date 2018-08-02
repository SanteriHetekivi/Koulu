#ifndef SOVELLUS_HPP
#define SOVELLUS_HPP

#include "Koulu.hpp"

/*	Santeri Hetekivi 1202466 13I220B
 * 	Olio-ohjelmointi 5G00BM44-3002
  */

class Sovellus
{
public:
	//Raketajat
	Sovellus();
	Sovellus(string);
	Sovellus(const Sovellus &);
	Sovellus& operator =(const Sovellus&); 	// Sioitusoperaattori
	~Sovellus();	//Purkaja
	//Setterit ja getterit
	void asetaNimi(string);
	string annaNimi() const;
	void aja();	//Julkinen funktio
	
private:
	string nimi_;	//Yksityinen muuttuja
	//Yksityisiä funktioita
	void tulostaValikko(string) const;
	int hankiInt() const;
	void odota() const;
	void puhdista() const;
	void kirjoita() const;
	Koulu lue() const;
	Koulu koulu_;

};
#endif


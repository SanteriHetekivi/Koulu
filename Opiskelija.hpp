#ifndef OPISKELIJA_HPP
#define OPISKELIJA_HPP

#include "Henkilo.hpp"

/*	Santeri Hetekivi 1202466 13I220B
 * 	Olio-ohjelmointi 5G00BM44-3002
  */
  
class Opiskelija : public Henkilo
{
public:
	//Rakentajat
	Opiskelija();
	Opiskelija(string, string, string, string, string);
	Opiskelija(const Opiskelija &);
	~Opiskelija();	//Purkaja
	Opiskelija& operator =(const Opiskelija&);	// Sioitusoperaattori
	//Setterit ja getterit
	void asetaOpiskelijanumero(string);
	string annaOpiskelijanumero() const;
	void kysyTiedot();
	void tulosta() const;
	
private:
	string opiskelijanumero_;
};
#endif

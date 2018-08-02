#ifndef OPETTAJA_HPP
#define OPETTAJA_HPP

#include "Tyontekija.hpp"

/*	Santeri Hetekivi 1202466 13I220B
 * 	Olio-ohjelmointi 5G00BM44-3002
  */
  
class Opettaja : public Tyontekija
{
public:
	//Rakentajat
	Opettaja();
	Opettaja(string, string, string, string, double, string, string);
	Opettaja(const Opettaja &);
	//Purkaja
	~Opettaja();
	//Sioitusoperaattori
	Opettaja& operator =(const Opettaja&);
	//Setterit ja Getterit
	void asetaOpetusala(string);
	string annaOpetusala() const;
	//Funktiot
	void kysyTiedot();
	void tulosta() const;
private:
	//Muuttujat
	string opetusala_;
};
#endif


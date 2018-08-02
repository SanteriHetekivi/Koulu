#ifndef TYONTEKIJA_HPP	
#define TYONTEKIJA_HPP

#include "Henkilo.hpp"

/*	Santeri Hetekivi 1202466 13I220B
 * 	Olio-ohjelmointi 5G00BM44-3002
  */

class Tyontekija : public Henkilo
{
public:
	//Rakentajat
	Tyontekija();
	Tyontekija(string,string,string,string,double,string);
	Tyontekija(const Tyontekija &);
	~Tyontekija();
	// Sioitusoperaattori
	Tyontekija& operator =(const Tyontekija&);
	//Setterit ja Getterit
	void asetaPalkka(double);
	double annaPalkka() const;
	void asetaTunnus(string);
	string annaTunnus() const;
	//Julkisia funktioita
	void kysyTiedot();
	void tulosta() const;
private:
	//Yksityisiä muuttujia
	string tunnus_;
	double palkka_;
	double hankiDouble_() const;	//Yksityinen funktio
};
#endif

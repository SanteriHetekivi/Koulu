#ifndef KOULUTUSOHJELMA_HPP
#define KOULUTUSOHJELMA_HPP

#include "Opiskelija.hpp"
#include "Opettaja.hpp"
#include <vector>

/*	Santeri Hetekivi 1202466 13I220B
 * 	Olio-ohjelmointi 5G00BM44-3002
  */

using std::vector;

class Koulutusohjelma
{
public:
	
	//Rakentajat
	Koulutusohjelma();
	Koulutusohjelma(string, vector <Opiskelija>, vector <Opettaja>);
	Koulutusohjelma(const Koulutusohjelma &);
	~Koulutusohjelma();	//Purkaja
	Koulutusohjelma& operator =(const Koulutusohjelma&);	//Sioitusoperaattori
	//Sioitusoperaattorit
	void asetaNimi(string);
	string annaNimi() const;
	void muutaNimi();
	void muutaOpiskelijanTiedot();
	void muutaOpettajanTiedot();
	void asetaOpiskelijat(vector <Opiskelija>);
	vector <Opiskelija> annaOpiskelijat() const;
	void asetaOpettajat(vector <Opettaja>);
	vector <Opettaja> annaOpettajat() const;
	//Julkisia funtioita
	void lisaaOpettaja();
	void lisaaOpiskelija();
	void lisaaOppilas(Opiskelija);
	void lisaaOpe(Opettaja);
	void tulostaOpettajat() const;
	void tulostaOpiskelijat() const;
	void tulostaNimi() const;
	void tulostaOpettajienMaara () const;
	void tulostaOppilaidenMaara () const;
	int hankiOpiskelijanNumero() const;
	int hankiOpettajanNumero() const;
	void tulostaOpettajanNimi(unsigned int) const;
	void tulostaOpettajienNimet() const;
	void tulostaOpiskelijanNimi(unsigned int) const;
	void tulostaOpiskelijienNimet() const;
	void poistaOpiskelija();
	void poistaOpettaja();

private:
	//Yksityisiä muuttujia
	string nimi_;
	vector <Opiskelija> opiskelijat_;
	vector <Opettaja> opettajat_;
};
#endif


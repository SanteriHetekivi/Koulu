#ifndef KOULU_HPP
#define KOULU_HPP

#include "Koulutusohjelma.hpp"

/*	Santeri Hetekivi 1202466 13I220B
 * 	Olio-ohjelmointi 5G00BM44-3002
  */

class Koulu
{
public:
	//Rakentajat
	Koulu();
	Koulu(string, vector <Koulutusohjelma>);
	Koulu(const Koulu &);
	Koulu& operator =(const Koulu&);
	~Koulu();	//Purkaja
	//Setterit ja getterit
	void asetaNimi(string);
	string annaNimi() const;
	void asetaKoulutusohjelmat(vector <Koulutusohjelma>);
	vector <Koulutusohjelma> annaKoulutusohjelmat() const;
	//Julkisia funktioita
	void asetaKoulutusohjelma(Koulutusohjelma);
	int annaKoulutusohjelmienMaara() const;
	void lisaaKoulutusohjelma();
	void tulostaKoulutusohjelmat() const;
	void kysyTiedot();
	void tulosta() const;
	void tulostaKoulutusohjelmienMaara () const;   
	void tulostaKoulutusohjelmanOpettajat() const;
	void tulostaKoulutusohjelmanOpiskelijat() const;
	void lisaaKoulutusohjelmaanOpettaja();
	void lisaaKoulutusohjelmaanOpiskelija();
	void lisaaOppilasKoulutusohjelmaan(string nimi, Opiskelija lisays);
	void lisaaOpettajaKoulutusohjelmaan(string nimi, Opettaja lisays);
	void poistaKoulutusohjelma();
	void poistaKoulutusohjelmanOpiskelija();
	void poistaKoulutusohjelmanOpettaja();
	void muutaKoulutusohjelmanNimi();
	void muutaKoulutusohjelmanOpiskelijanTiedot();
	void muutaKoulutusohjelmanOpettajanTiedot();

private:
	//Yksityisiä muuttujia
	string nimi_;
	vector <Koulutusohjelma> koulutusohjelmat_;
	//Yksityisiä funktioita
	int hankiKoulutusohjelmannumero() const;
	int hankiKoulutusohjelmannumeroNimesta(string) const;


};
#endif


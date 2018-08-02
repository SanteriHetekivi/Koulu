#include "Koulutusohjelma.hpp"

/*	Santeri Hetekivi 1202466 13I220B
 * 	Olio-ohjelmointi 5G00BM44-3002
  */

//Rakentajat
Koulutusohjelma::Koulutusohjelma() :
nimi_("")
{
	cout << "Koulutusohjelman oletusrakentaja" << endl;
}

Koulutusohjelma::Koulutusohjelma(string nimi, vector <Opiskelija> opiskelijat, vector <Opettaja> opettajat) :
nimi_(nimi), opiskelijat_(opiskelijat), opettajat_(opettajat)
{
	cout << "Koulutusohjelman parametrillista rakentaja" << endl;
}

Koulutusohjelma::Koulutusohjelma(const Koulutusohjelma &koulutusohjelma) :
nimi_(koulutusohjelma.nimi_), opiskelijat_(koulutusohjelma.opiskelijat_), opettajat_(koulutusohjelma.opettajat_)
{
	cout << "Koulutusohjelman kopiorakentaja" << endl;
}

//Purkaja
Koulutusohjelma::~Koulutusohjelma()
{
	cout << "Koulutusohjelman purkaja" << endl;
}

// Sijoitusoperaattori
Koulutusohjelma& Koulutusohjelma::operator =(const Koulutusohjelma& vanha)
{
	if (this != &vanha)
	{ // Jos ei sijoiteta itseen
		nimi_ = vanha.nimi_; // Sijoita
		opiskelijat_ = vanha.opiskelijat_;
		opettajat_ = vanha.opettajat_;
	}
	return *this;
}

//Setterit ja Getterit
void Koulutusohjelma::asetaNimi(string nimi)
{
	nimi_ = nimi;
}

string Koulutusohjelma::annaNimi() const
{
	return nimi_;
}

void Koulutusohjelma::muutaNimi()
{
	cout << "Koulutusohjelman nimi: ";
	getline(cin, nimi_);
}

void Koulutusohjelma::asetaOpiskelijat(vector <Opiskelija> opiskelijat)
{
	opiskelijat_.swap(opiskelijat);
}

vector <Opiskelija> Koulutusohjelma::annaOpiskelijat() const
{
	return opiskelijat_;
}

void Koulutusohjelma::asetaOpettajat(vector <Opettaja> opettajat)
{
	opettajat_.swap(opettajat);
}

vector <Opettaja> Koulutusohjelma::annaOpettajat() const
{
	return opettajat_;
}

//Julkiset funktiot
void Koulutusohjelma::lisaaOpettaja()
{
	Opettaja lisays;
	lisays.kysyTiedot();
	opettajat_.push_back(lisays);
}
void Koulutusohjelma::lisaaOpiskelija()
{
	Opiskelija lisays;
	lisays.kysyTiedot();
	opiskelijat_.push_back(lisays);
}

void Koulutusohjelma::lisaaOppilas(Opiskelija lisays)
{
	opiskelijat_.push_back(lisays);
}

void Koulutusohjelma::lisaaOpe(Opettaja lisays)
{
	opettajat_.push_back(lisays);
}

void Koulutusohjelma::tulostaOpettajat() const
{
	for (vector<Opettaja>::const_iterator i = opettajat_.begin(); i != opettajat_.end(); ++i)
	{
		i->tulosta();
		cout << endl;
	}
}

void Koulutusohjelma::tulostaOpiskelijat() const
{
	for (vector<Opiskelija>::const_iterator i = opiskelijat_.begin(); i != opiskelijat_.end(); ++i)
	{
		i->tulosta();
		cout << endl;
	}
}

void Koulutusohjelma::tulostaNimi() const
{
	cout << nimi_ << endl;
}

void Koulutusohjelma::tulostaOpettajienMaara () const
{
	cout << opettajat_.size() << endl;
}

void Koulutusohjelma::tulostaOppilaidenMaara () const
{
	cout << opiskelijat_.size() << endl;
}

void Koulutusohjelma::poistaOpiskelija()
{
	int valinta = Koulutusohjelma::hankiOpiskelijanNumero();
	opiskelijat_.erase(opiskelijat_.begin() + valinta);
}

void  Koulutusohjelma::poistaOpettaja()
{
	int valinta = Koulutusohjelma::hankiOpettajanNumero();
	opettajat_.erase(opettajat_.begin() + valinta);
}


int Koulutusohjelma::hankiOpiskelijanNumero() const
{
	Koulutusohjelma::tulostaOpiskelijienNimet();
	string Opiskelijanumero;
	cout << "Opiskelijanumero: ";
	getline(cin, Opiskelijanumero);
	for (unsigned int i = 0; i < opiskelijat_.size(); ++i)
	{
		if(opiskelijat_[i].annaOpiskelijanumero() == Opiskelijanumero)
		{
			Koulutusohjelma::tulostaOpettajanNimi(i);
			return i;
		}
	}
	cout << "Virheellinen opiskelijanumero" << endl;
	return -1;
}

int Koulutusohjelma::hankiOpettajanNumero() const
{
	Koulutusohjelma::tulostaOpettajienNimet();
	string opettajanTunnus;
	cout << "Opettajan Tunnus: ";
	getline(cin, opettajanTunnus);
	for (unsigned int i = 0; i < opettajat_.size(); ++i)
	{
		if(opettajat_[i].annaTunnus() == opettajanTunnus)
		{
			Koulutusohjelma::tulostaOpettajanNimi(i);
			return i;
		}
	}
	cout << "Virheellinen tunnus" << endl;
	return -1;
}

void Koulutusohjelma::tulostaOpiskelijienNimet() const
{
	for (vector<Opiskelija>::const_iterator i = opiskelijat_.begin(); i != opiskelijat_.end(); ++i)
	{
		cout << i->annaOpiskelijanumero() << ": " << i->annaEtunimi() << " " << i->annaSukunimi() << endl;
	}
}

void Koulutusohjelma::tulostaOpettajienNimet() const
{
	for (vector<Opettaja>::const_iterator i = opettajat_.begin(); i != opettajat_.end(); ++i)
	{
		cout << i->annaTunnus() << ": " << i->annaEtunimi() << " " << i->annaSukunimi() << endl;
	}
}

void Koulutusohjelma::tulostaOpettajanNimi(unsigned int i) const
{
	cout << opettajat_[i].annaEtunimi() << " " << opettajat_[i].annaSukunimi() << endl;
}

void Koulutusohjelma::tulostaOpiskelijanNimi(unsigned int i) const
{
	cout << opiskelijat_[i].annaOpiskelijanumero() << ": " << opiskelijat_[i].annaEtunimi() << " " << opiskelijat_[i].annaSukunimi() << endl;
}

void Koulutusohjelma::muutaOpiskelijanTiedot()
{
	int valinta = Koulutusohjelma::hankiOpiskelijanNumero();
	opiskelijat_[valinta].kysyTiedot();
}

void Koulutusohjelma::muutaOpettajanTiedot()
{
	int valinta = Koulutusohjelma::hankiOpettajanNumero();
	opettajat_[valinta].kysyTiedot();
}


#include "Koulu.hpp"

/*	Santeri Hetekivi 1202466 13I220B
 * 	Olio-ohjelmointi 5G00BM44-3002
  */

//Rakentajat
Koulu::Koulu() :
nimi_("")
{
	cout << "Koulun oletusrakentaja" << endl;
}

Koulu::Koulu(string nimi, vector <Koulutusohjelma> koulutusohjelmat) :
nimi_(nimi), koulutusohjelmat_(koulutusohjelmat)
{
	cout << "Koulun parametrillista rakentaja" << endl;
}

//Purkaja
Koulu::Koulu(const Koulu &koulu) :
nimi_(koulu.nimi_), koulutusohjelmat_(koulu.koulutusohjelmat_)
{
	cout << "Koulun kopiorakentaja" << endl;
}

Koulu::~Koulu()
{
	cout << "Koulun purkaja" << endl;
}
Koulu& Koulu::operator =(const Koulu& vanha)
{
	if (this != &vanha)
	{ // Jos ei sijoiteta itseen
		nimi_ = vanha.nimi_; // Sijoita
		koulutusohjelmat_ = vanha.koulutusohjelmat_;
	}
	return *this;
}
//Setterit ja Getterit
void Koulu::asetaNimi(string nimi)
{
	nimi_ = nimi;
}

string Koulu::annaNimi() const
{
	return nimi_;
}

void Koulu::asetaKoulutusohjelmat(vector <Koulutusohjelma> koulutusohjelmat)
{
	koulutusohjelmat_.swap(koulutusohjelmat);
}

vector <Koulutusohjelma> Koulu::annaKoulutusohjelmat() const
{
	return koulutusohjelmat_;
}

//Julkiset funtiot
int Koulu::annaKoulutusohjelmienMaara() const
{
	return koulutusohjelmat_.size();
}
void Koulu::lisaaKoulutusohjelma()
{
	string koulutusohjelma;
	cout << "Koulutusohjelman nimi: ";
	getline(cin, koulutusohjelma);
	Koulutusohjelma lisays;
	lisays.asetaNimi(koulutusohjelma);
	koulutusohjelmat_.push_back(lisays);
}

void Koulu::asetaKoulutusohjelma(Koulutusohjelma lisays)
{
	koulutusohjelmat_.push_back(lisays);
}


void Koulu::tulostaKoulutusohjelmat() const
{
	for (vector<Koulutusohjelma>::const_iterator i = koulutusohjelmat_.begin(); i != koulutusohjelmat_.end(); ++i)
	{
		i->tulostaNimi();
	}
}
void Koulu::kysyTiedot()	//Kysyt‰‰n k‰ytt‰j‰lt‰ tiedot
{
	cout << "Koulun Nimi:      ";
	getline(cin, nimi_);
}

void Koulu::tulosta() const	//Tulostetaan tiedot
{
	cout << "Koulun Nimi:      " << nimi_ << endl;
}

void Koulu::tulostaKoulutusohjelmienMaara () const
{
	cout << koulutusohjelmat_.size() << endl;
}

void Koulu::tulostaKoulutusohjelmanOpettajat() const
{
	int i = Koulu::hankiKoulutusohjelmannumero();
	if(i >= 0)
	{
		koulutusohjelmat_[i].tulostaOpettajat();
	}
}

void Koulu::tulostaKoulutusohjelmanOpiskelijat() const
{
	int i = Koulu::hankiKoulutusohjelmannumero();
	if(i >= 0)
	{
		koulutusohjelmat_[i].tulostaOpiskelijat();
	}
}

void Koulu::lisaaKoulutusohjelmaanOpettaja()
{
	int i = Koulu::hankiKoulutusohjelmannumero();
	if(i >= 0)
	{
		koulutusohjelmat_[i].lisaaOpettaja();
	}
}

void Koulu::lisaaKoulutusohjelmaanOpiskelija()
{
	int i = Koulu::hankiKoulutusohjelmannumero();
	if(i >= 0)
	{
		koulutusohjelmat_[i].lisaaOpiskelija();
	}
}

void Koulu::poistaKoulutusohjelma()
{
	int valinta = Koulu::hankiKoulutusohjelmannumero();
	if (valinta >= 0){ koulutusohjelmat_.erase(koulutusohjelmat_.begin() + valinta); }
}

void Koulu::poistaKoulutusohjelmanOpiskelija()
{
	int valinta = Koulu::hankiKoulutusohjelmannumero();
	if(valinta >= 0)
	{
		koulutusohjelmat_[valinta].poistaOpiskelija();
	}
}
void Koulu::poistaKoulutusohjelmanOpettaja()
{
	int valinta = Koulu::hankiKoulutusohjelmannumero();
	if(valinta >= 0)
	{
		koulutusohjelmat_[valinta].poistaOpettaja();
	}
}

void Koulu::muutaKoulutusohjelmanNimi()
{
	int valinta = Koulu::hankiKoulutusohjelmannumero();
	if(valinta >= 0)
	{
		koulutusohjelmat_[valinta].muutaNimi();
	}
}

void Koulu::lisaaOppilasKoulutusohjelmaan(string nimi, Opiskelija lisays)
{
	int i = Koulu::hankiKoulutusohjelmannumeroNimesta(nimi);
	if(i >= 0){ koulutusohjelmat_[i].lisaaOppilas(lisays);}
}

void Koulu::lisaaOpettajaKoulutusohjelmaan(string nimi, Opettaja lisays)
{
	int i = Koulu::hankiKoulutusohjelmannumeroNimesta(nimi);
	if(i >= 0){ koulutusohjelmat_[i].lisaaOpe(lisays);}
}

void Koulu::muutaKoulutusohjelmanOpiskelijanTiedot()
{
	int valinta = Koulu::hankiKoulutusohjelmannumero();
	if(valinta >= 0)
	{
		koulutusohjelmat_[valinta].muutaOpiskelijanTiedot();
	}
}

void Koulu::muutaKoulutusohjelmanOpettajanTiedot()
{
	int valinta = Koulu::hankiKoulutusohjelmannumero();
	if(valinta >= 0)
	{
		koulutusohjelmat_[valinta].muutaOpettajanTiedot();
	}
}

//Yksityiset funktiot
int Koulu::hankiKoulutusohjelmannumeroNimesta(string nimi) const
{
	for (unsigned int i = 0; i < koulutusohjelmat_.size(); ++i)
	{
		if(koulutusohjelmat_[i].annaNimi() == nimi)
		{
			return i;
		}
	}
	return -1;
}

int Koulu::hankiKoulutusohjelmannumero() const
{
	Koulu::tulostaKoulutusohjelmat();
	string koulutusohjelmanNimi;
	cout << "Koulutusohjelman Nimi: ";
	getline(cin, koulutusohjelmanNimi);
	for (unsigned int i = 0; i < koulutusohjelmat_.size(); ++i)
	{
		if(koulutusohjelmat_[i].annaNimi() == koulutusohjelmanNimi)
		{
			koulutusohjelmat_[i].tulostaNimi();
			return i;
		}
	}
	cout << "Virheellinen nimi" << endl;
	return -1;
}

#include "Sovellus.hpp"
#include <limits>
#include <iostream>
#include <fstream>
#include <stdlib.h>

/*	Santeri Hetekivi 1202466 13I220B
 * 	Olio-ohjelmointi 5G00BM44-3002
  */

//Rakentajat
Sovellus::Sovellus() :
nimi_()
{
	cout << "Sovelluksen oletusrakentaja" << endl;
}

Sovellus::Sovellus(string nimi) :
nimi_(nimi)
{
	cout << "Sovelluksen parametrillista rakentaja" << endl;
}

Sovellus::Sovellus(const Sovellus &sovellus) : 
nimi_(sovellus.nimi_)
{
	cout << "Sovelluksen kopiorakentaja" << endl;
}

//Purkaja
Sovellus::~Sovellus()
{
	cout << "Sovelluksen purkaja" << endl;
}

// Sijoitusoperaattori
Sovellus& Sovellus::operator =(const Sovellus& vanha)
{
	if (this != &vanha)
	{ // Jos ei sijoiteta itseen
		nimi_ = vanha.nimi_;
	}
	return *this;
}

//Setterit ja Getterit
void Sovellus::asetaNimi(string nimi)
{
	nimi_ = nimi;
}

string Sovellus::annaNimi() const
{
	return nimi_;
}


//Ajofunktio
void Sovellus::aja()
{
	//Asetetaan muuttuja ja koulun nimi
	bool poistu = false;
	koulu_.asetaNimi(nimi_);
	//Pysytään valikossa kunnes muutetaan poistu true:ksi
	while(poistu == false)
	{
		Sovellus::tulostaValikko(koulu_.annaNimi());	
		int valinta = Sovellus::hankiInt();
		Sovellus::puhdista();
		if(valinta == 0)
		{
			poistu = true;
		}
		else if(valinta == 1)
		{
			koulu_.lisaaKoulutusohjelma();
		}
		else if(valinta == 2)
		{
			koulu_.tulostaKoulutusohjelmat();
		}
		else if(valinta == 3)
		{
			koulu_.tulostaKoulutusohjelmienMaara();
		}
		else if(valinta == 4)
		{
			koulu_.lisaaKoulutusohjelmaanOpettaja();
		}
		else if(valinta == 5)
		{
			koulu_.tulostaKoulutusohjelmanOpettajat();
		}
		else if(valinta == 6)
		{
			koulu_.lisaaKoulutusohjelmaanOpiskelija();
		}
		else if(valinta == 7)
		{
			koulu_.tulostaKoulutusohjelmanOpiskelijat();
		}
		else if(valinta == 8)
		{
			koulu_.poistaKoulutusohjelma();
		}
		else if(valinta == 9)
		{
			koulu_.poistaKoulutusohjelmanOpettaja();
		}
		else if(valinta == 10)
		{
			koulu_.poistaKoulutusohjelmanOpiskelija();
		}
		else if(valinta == 11)
		{
			koulu_.muutaKoulutusohjelmanNimi();
		}
		else if(valinta == 12)
		{
			koulu_.muutaKoulutusohjelmanOpettajanTiedot();
		}
		else if(valinta == 13)
		{
			koulu_.muutaKoulutusohjelmanOpiskelijanTiedot();
		}
		else if(valinta == 14)
		{
			koulu_=Sovellus::lue();
		}
		else if(valinta == 15)
		{
			Sovellus::kirjoita();
		}
		Sovellus::odota();
		Sovellus::puhdista();
	}
}

int Sovellus::hankiInt() const
{
	//Määritetään string ja int muuttujat
	string sisaantulo = "";
	int numero = 0;
	while (true)
	{
		//Hankitaan string käyttäjältä
		getline(cin, sisaantulo);
		// Muutetaan string numeroksi turvallisesti
		stringstream myStream(sisaantulo);
		if (myStream >> numero && numero >= 0 && numero < 16)
		{
			break;
		}
		//Ilmoitetaan virheellisetä numerosta
		cout << "Virheellinen Numero !" << endl;
		cout << "Uudelleen: ";
	}
	cin.clear();
	return numero;
}

void Sovellus::tulostaValikko(string nimi) const
{
	cout << "Koulu " << nimi << endl;
	cout << "1) Lis\x84\x84 koulutusohjelma" << endl;
	cout << "2) Tulosta koulutusohjelmien nimet" << endl;
	cout << "3) Tulosta koulutusohjelmien m\x84\x84r\x84" << endl;
	cout << "4) Lis\x84\x84 koulutusohjelmaan opettaja" << endl;
	cout << "5) Tulosta koulutusohjelman opettajat" << endl;
	cout << "6) Lis\x84\x84 koulutusohjelmaan opiskelija" << endl;
	cout << "7) Tulosta koulutusohjelman opiskelijat" << endl;
	cout << "8) Poista koulutusohjelma" << endl;
	cout << "9) Poista opettaja" << endl;
	cout << "10) Poista opiskelija" << endl;
	cout << "11) P\x84ivit\x84 koulutusohjelman nimi" << endl;
	cout << "12) P\x84ivit\x84 opettajan tiedot" << endl;
	cout << "13) P\x84ivit\x84 opiskelijan tiedot" << endl;
	cout << "14) Lue tiedot" << endl;
	cout << "15) Tallenna tiedot" << endl;
	cout << "0. Poistu" << endl;
	cout << "Valitse: ";
}

void Sovellus::odota() const
{
	cout << "Paina ENTER jatkaaksesi!";
	cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}

void Sovellus::puhdista() const
{
	for (int n = 0; n < 50; n++)
	{
      cout << endl;
	}
}

void Sovellus::kirjoita() const
{
	vector <Koulutusohjelma> koulutusohjelmat = koulu_.annaKoulutusohjelmat();	
	std::ofstream oppilas ("oppilas.csv");
	std::ofstream opettaja ("opettaja.csv");
	std::ofstream koulutusohjelma ("koulutusohjelma.csv");
	if (koulutusohjelma.is_open())
	{
		//Kirjoitetaan koulutusohjelmat tiedostoon
		for (unsigned int i = 0; i < koulutusohjelmat.size(); ++i)
		{
			koulutusohjelma << koulutusohjelmat[i].annaNimi() << ";";
			//Kirjoitetaan Oppilaat tiedostoon
			if (oppilas.is_open())
			{
				vector <Opiskelija> opiskelijat = koulutusohjelmat[i].annaOpiskelijat();
				for (unsigned int y = 0; y < opiskelijat.size(); ++y)
				{
					oppilas << koulutusohjelmat[i].annaNimi() << ";" << opiskelijat[y].annaEtunimi() << ";" << opiskelijat[y].annaSukunimi() << ";" << opiskelijat[y].annaOsoite() << ";" << opiskelijat[y].annaPuhelinnumero() << ";" << opiskelijat[y].annaOpiskelijanumero() << ";" << endl;
				}
			}
			//Kirjoitetaan opettajat tiedostoon
			if (opettaja.is_open())
			{
				vector <Opettaja> opettajat = koulutusohjelmat[i].annaOpettajat();
				for (unsigned int x = 0; x < opettajat.size(); ++x)
				{
					opettaja << koulutusohjelmat[i].annaNimi() << ";" << opettajat[x].annaEtunimi() << ";" << opettajat[x].annaSukunimi() << ";" << opettajat[x].annaOsoite() << ";" << opettajat[x].annaPuhelinnumero() << ";" << opettajat[x].annaPalkka() << ";" << opettajat[x].annaTunnus() << ";" << opettajat[x].annaOpetusala() << ";" << endl;
				}
			}
		}
	}
	oppilas.close();
	opettaja.close();
	koulutusohjelma.close();
}

Koulu Sovellus::lue() const
{
	//Luodaan väliaikainen Koulu olio
	Koulu koulu;
	vector <Koulutusohjelma> koulutusohjelmat;
	std::ifstream oppilas ("oppilas.csv");
	std::ifstream opettaja ("opettaja.csv");
	std::ifstream koulutusohjelma ("koulutusohjelma.csv");
	string nimi;
	string teksti;
	//Lisätään koulutusohjelmat väliaikaiseen Koulu olioon
	if (koulutusohjelma.is_open())
	{
		Koulutusohjelma lisaysKoulutusohjelma;
		while (koulutusohjelma.good())
		{
			 getline(koulutusohjelma,teksti, ';');
			 if(!teksti.empty())
			 {
				lisaysKoulutusohjelma.asetaNimi(teksti);
				koulu.asetaKoulutusohjelma(lisaysKoulutusohjelma);
			}
		}
		//Lisätään oppilaat väliaikkaisiin Koulutusohjelmat olioihin
		if (oppilas.is_open())
		{
			Opiskelija lisaysOppilas;
			while (oppilas.good())
			{
				 getline(oppilas,nimi, ';');
				 if(!nimi.empty())
				 {
					getline(oppilas,teksti, ';');
					lisaysOppilas.asetaEtunimi(teksti);
					getline(oppilas,teksti, ';');
					lisaysOppilas.asetaSukunimi(teksti);
					getline(oppilas,teksti, ';');
					lisaysOppilas.asetaOsoite(teksti);
					getline(oppilas,teksti, ';');
					lisaysOppilas.asetaPuhelinnumero(teksti);
					getline(oppilas,teksti, ';');
					lisaysOppilas.asetaOpiskelijanumero(teksti);
					koulu.lisaaOppilasKoulutusohjelmaan(nimi, lisaysOppilas);
					getline(oppilas,teksti);
				}
			}
			oppilas.close();
		}
		//Lisätään opettajat väliaikkaisiin Koulutusohjelmat olioihin
		if (opettaja.is_open())
		{
			Opettaja lisaysOpettaja;
			double palkka;
			while (opettaja.good())
			{
				 getline(opettaja,nimi, ';');
				 if(!nimi.empty())
				 {
					getline(opettaja,teksti, ';');
					lisaysOpettaja.asetaEtunimi(teksti);
					getline(opettaja,teksti, ';');
					lisaysOpettaja.asetaSukunimi(teksti);
					getline(opettaja,teksti, ';');
					lisaysOpettaja.asetaOsoite(teksti);
					getline(opettaja,teksti, ';');
					lisaysOpettaja.asetaPuhelinnumero(teksti);
					getline(opettaja,teksti, ';');
					palkka = atof(teksti.c_str());
					lisaysOpettaja.asetaPalkka(palkka);
					getline(opettaja,teksti, ';');
					lisaysOpettaja.asetaTunnus(teksti);
					getline(opettaja,teksti, ';');
					lisaysOpettaja.asetaOpetusala(teksti);
					koulu.lisaaOpettajaKoulutusohjelmaan(nimi, lisaysOpettaja);
					getline(opettaja,teksti);
				}
			}
			opettaja.close();
		}
	koulutusohjelma.close();
	}
	else
	{
		cout << "Tarkista tiedostot. Hakeminen ei onnistunut." << endl;
	}
	return koulu;	//Palautetaan Koulu olio
}

#include "Sovellus.hpp"
#include <typeinfo>
/*	Santeri Hetekivi 1202466 13I220B
 * 	Olio-ohjelmointi 5G00BM44-3002
  */

int main()
{
	try
	{
		//Luodaan ja ajetaan sovellus
		Sovellus sovellus("TAMK");
		sovellus.aja();
	}
	catch(const std::exception& virhe)
	{
		//Tulostetaan kaapatun virheen tiedot
		std::cerr << "Virhe: " << virhe.what() << endl;
		std::cerr << "Tyyppi: " << typeid(virhe).name() << endl;
		return 1;
	}
	catch(...)
	{
		//Tulostetaan tieto tuntemattomasta virheestä
		std::cerr << "Tuntematon virhe!" << endl;
		return 1;
	}
	return 0;
}

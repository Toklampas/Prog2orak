#include <vector>
#include <iostream>

template <typename T1, typename T2>
class AdatPar {
	T1 elso;
	T2 masodik;

public:
	AdatPar(T1 elso, T2 masodik) : elso(elso), masodik(masodik) {}
	T1 getElso() const { return elso; }
	T2 getMasodik() const { return masodik; }
};

template <typename P>
class AdatTarolo {
	std::vector<P> adatok;

public:
	const std::vector<P>& getAdatok() const { return adatok; }
	void hozzaad(const P& adat) { adatok.push_back(adat); }
};

template <typename P>
void feldolgoz(AdatTarolo<P>& adattarolo)
{
	std::vector<P> tarolo = adattarolo.getAdatok();
	for (int i = 0; i < tarolo.size(); i++)
	{
		std::cout << "feldolgozas alatt: " << tarolo[i].getElso() << " " << tarolo[i].getMasodik() << std::endl;
	}
}

int main() {
	AdatTarolo<AdatPar<int, std::string>> adattarolo;
	adattarolo.hozzaad(AdatPar<int, std::string>(1, "Alma"));
	adattarolo.hozzaad(AdatPar<int, std::string>(2, "Korte"));
	adattarolo.hozzaad(AdatPar<int, std::string>(3, "Eper"));
	feldolgoz(adattarolo);
	return 0;
}
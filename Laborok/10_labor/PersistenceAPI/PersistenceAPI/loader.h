#pragma once
#include <string>
#include <fstream>
#include "serializable.h"

namespace PersistenceAPI
{
	class Loader
	{
		std::string inFileName;
		std::ifstream ifs;
	public:
		// inFileName: annak a fájlnak az elérési útvonala, ahonnan betölti az item-et.
		Loader(std::string inFileName);

		// Meghívja a paraméterül kapott item deserialize(...) metódusát.
		bool load(Serializable& item);

		// Lezárja az ifs-t.
		void close();
	};
}
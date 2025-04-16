#pragma once
#include <string>
#include <fstream>
#include "serializable.h"

namespace PersistenceAPI
{
	class Saver
	{
		std::string outFileName;
		std::ofstream ofs;
	public:
		// outFileName: annak a fájlnak az elérési útvonala, ahova lementi az item-et.
		Saver(std::string outFileName);

		// Meghívja a paraméterül kapott item serialize(...) metódusát.
		bool save(Serializable& item);

		// Lezárja az ofs-t.
		void close();
	};
}

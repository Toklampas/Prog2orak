#include "loader.h"

namespace PersistenceAPI 
{
	Loader::Loader(std::string inFileName) :inFileName(inFileName), ifs(inFileName)
	{
		if (!ifs)
			std::cerr << "PersistenceAPI# error opening input file: " << inFileName << std::endl;
	}
	
	bool Loader::load(Serializable& item)
	{
		item.deserialize(ifs);
		return !ifs;
	}

	void Loader::close()
	{
		ifs.close();
	}
}
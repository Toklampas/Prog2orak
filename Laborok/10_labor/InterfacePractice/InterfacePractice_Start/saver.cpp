#include "saver.h"

namespace PersistenceAPI
{
	Saver::Saver(std::string outFileName) : outFileName(outFileName), ofs(outFileName)
	{
		if (!ofs)
			std::cerr << "PersistenceAPI# error opening output file: " << outFileName << std::endl;
	}

	bool Saver::save(Serializable& item)
	{
		item.serialize(ofs);
		return !ofs;
	}
	
	void Saver::close()
	{
		ofs.close();
	}
}
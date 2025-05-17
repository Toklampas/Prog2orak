//#define _CRTDBG_MAP_ALLOC
//#include <crtdbg.h>

#include "list.h"
#include "menuSystem.h"
#include <stdexcept>

int main()
{
    try
    {
        MenuSystem menu;
        menu.run();
        //_CrtDumpMemoryLeaks();
    }
    catch (const std::exception& ex)
    {
        std::cerr << "An error occurred: " << ex.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "An unknown error occurred!" << std::endl;
    }
	
    return 0;    
}
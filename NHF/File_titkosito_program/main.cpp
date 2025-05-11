#include "list.h"
#include "menuSystem.h"
#include <stdexcept>

int main()
{
    try
    {
        MenuSystem menu;
        menu.run();
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
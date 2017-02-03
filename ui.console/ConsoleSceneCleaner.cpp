#include "../ui/SceneCleaner.h"
#include <cstdlib>

class ConsoleSceneCleaner : public SceneCleaner
{
    virtual void clean()
    {
        std::system("clear");
    }
};
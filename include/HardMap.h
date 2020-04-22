#ifndef HARDMAP_H
#define HARDMAP_H
#include "Map.h"


class HardMap : public Map
{
    public:
        HardMap();
        virtual void generate();
        ~HardMap();

    protected:

    private:
};

#endif // HARDMAP_H

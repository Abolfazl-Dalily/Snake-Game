#ifndef MEDIUMMAP_H
#define MEDIUMMAP_H
#include "Map.h"


class MediumMap : public Map
{
    public:
        MediumMap();
        virtual void generate();
        ~MediumMap();

    protected:

    private:
};

#endif // MEDIUMMAP_H

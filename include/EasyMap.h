#ifndef EASYMAP_H
#define EASYMAP_H

#include "Map.h"

class EasyMap : public Map
{
public:
    EasyMap();
    virtual void generate();
    ~EasyMap();

protected:

private:
};

#endif // EASYMAP_H

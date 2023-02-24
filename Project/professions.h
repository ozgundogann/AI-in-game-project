#ifndef PROFESSIONS_H
#define PROFESSIONS_H

#include "properties.h"
#include <QMessageBox>

class Murderer: public Properties{
public:
    Murderer();
    virtual ~Murderer();
};

class Doctor: public Properties{
public:
    Doctor();
    virtual ~Doctor();
};

class Butcher: public Properties{
public:
    Butcher();
    virtual ~Butcher();
};

class Farmer: public Properties{
public:
    Farmer();
    virtual ~Farmer();
};

class Hunter:public Properties{
public:
    Hunter();
    virtual ~Hunter();
};

class Builder:public Properties{
public:
    Builder();
    virtual ~Builder();

};

class Mayor:public Properties{
public:
    Mayor();
    virtual ~Mayor();
};

#endif // PROFESSIONS_H

#include "properties.h"

Properties::Properties(){
    radioButton = new QRadioButton;
    label = new QLabel;
    name = "";
    point = 0;
    blood = false;
    knife = false;
    headMask = false;
    surgeryGloves = false;
    stench = false;
    farmerHat = false;
    harrow = false;
    mayorHat = false;
    pocketWatch = false;
    hammer = false;
    bow = false;
    arrow = false;
}
Properties::~Properties(){
    delete radioButton;
    delete label;
}

int Properties::getPoint() const
{
    return point;
}

void Properties::setPoint(int newPoint)
{
    point = newPoint;
}

bool Properties::getHeadMask() const
{
    return headMask;
}

void Properties::setHeadMask(bool newHeadMask)
{
    headMask = newHeadMask;
}

bool Properties::getArrow() const
{
    return arrow;
}

void Properties::setArrow(bool newArrow)
{
    arrow = newArrow;
}

bool Properties::getBlood() const
{
    return blood;
}

void Properties::setBlood(bool newBlood)
{
    blood = newBlood;
}

bool Properties::getKnife() const
{
    return knife;
}

void Properties::setKnife(bool newKnife)
{
    knife = newKnife;
}

bool Properties::getSurgeryGloves() const
{
    return surgeryGloves;
}

void Properties::setSurgeryGloves(bool newSurgeryGloves)
{
    surgeryGloves = newSurgeryGloves;
}

bool Properties::getStench() const
{
    return stench;
}

void Properties::setStench(bool newStench)
{
    stench = newStench;
}

bool Properties::getFarmerHat() const
{
    return farmerHat;
}

void Properties::setFarmerHat(bool newFarmerHat)
{
    farmerHat = newFarmerHat;
}

bool Properties::getHarrow() const
{
    return harrow;
}

void Properties::setHarrow(bool newHarrow)
{
    harrow = newHarrow;
}

bool Properties::getMayorHat() const
{
    return mayorHat;
}

void Properties::setMayorHat(bool newMayorHat)
{
    mayorHat = newMayorHat;
}

bool Properties::getPocketWatch() const
{
    return pocketWatch;
}

void Properties::setPocketWatch(bool newPocketWatch)
{
    pocketWatch = newPocketWatch;
}

bool Properties::getHammer() const
{
    return hammer;
}

void Properties::setHammer(bool newHammer)
{
    hammer = newHammer;
}

bool Properties::getBow() const
{
    return bow;
}

void Properties::setBow(bool newBow)
{
    bow = newBow;
}


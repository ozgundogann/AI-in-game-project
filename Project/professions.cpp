#include "professions.h"
#include "mainwindow.h"

Murderer::Murderer(){
    profession = "Murderer";
    setKnife(true);
    setBlood(true);
    setHeadMask(true);
    radioButton->setEnabled(false);
}

Murderer::~Murderer(){}

Doctor::Doctor(){
    profession = "Doctor";
    setKnife(true);
    setBlood(true);
    setSurgeryGloves(true);
}

Doctor::~Doctor(){}

Butcher::Butcher(){
    profession = "Butcher";
    setKnife(true);
    setStench(true);
    setBlood(true);
}

Butcher::~Butcher(){}

Farmer::Farmer(){
    profession = "Farmer";
    setHarrow(true);
    setFarmerHat(true);
}

Farmer::~Farmer(){}

Hunter::Hunter(){
    profession = "Hunter";
    setBow(true);
    setArrow(true);
}

Hunter::~Hunter(){}


Builder::Builder(){
    profession = "Builder";
    setHammer(true);
}

Builder::~Builder(){}


Mayor::Mayor(){
    profession = "Mayor";
    setPocketWatch(true);
    setMayorHat(true);
}

Mayor::~Mayor(){}

#include "agent.h"

Detective::Detective(){
    for(int i = 0; i < 20; i++)
        knowledgeBase[i] = new Properties;
}

Detective::~Detective(){
    for(int i = 0; i < 20; i++)
        delete knowledgeBase[i];
}

void Detective::examine(Properties* person, int index){

    if (person->getPoint() == -100)
        return;
    if(person->getPoint() == 0 && person->getKnife()){
        knowledgeBase[index]->setKnife(true);
        knowledgeBase[index]->setPoint(10);
        person->setPoint(10);

    }
    else if (person->getPoint() == 10 && person->getBlood()){
        knowledgeBase[index]->setBlood(true);
        knowledgeBase[index]->setPoint(20);
        person->setPoint(20);

    }
    else if (person->getPoint() == 20 && person->getHeadMask()){
        knowledgeBase[index]->setHeadMask(true);
        knowledgeBase[index]->setPoint(30);
        person->setPoint(30);
    }
    else if(person->getPoint() == 20 && person->getStench()){
        knowledgeBase[index]->setStench(true);
        knowledgeBase[index]->setPoint(-100);
        person->setPoint(-100);
    }

    else if(person->getPoint() == 20 && person->getSurgeryGloves()){
        knowledgeBase[index]->setSurgeryGloves(true);
        knowledgeBase[index]->setPoint(-100);
        person->setPoint(-100);
    }
    else if(person->getPoint() == 0 && person->getFarmerHat()){
        knowledgeBase[index]->setFarmerHat(true);
        knowledgeBase[index]->setPoint(10);
        person->setPoint(10);

    }
    else if (person->getPoint() == 10 && person->getHarrow()){
        knowledgeBase[index]->setHarrow(true);
        knowledgeBase[index]->setPoint(-100);
        person->setPoint(-100);
    }
    else if(person->getPoint() == 0 && person->getMayorHat()){
        knowledgeBase[index]->setMayorHat(true);
        knowledgeBase[index]->setPoint(10);
        person->setPoint(10);

    }
    else if (person->getPoint() == 10 && person->getPocketWatch()){
        knowledgeBase[index]->setPocketWatch(true);
        knowledgeBase[index]->setPoint(-100);
        person->setPoint(-100);
    }

    else if (person->getPoint() == 0 && person->getHammer()){
        knowledgeBase[index]->setHammer(true);
        knowledgeBase[index]->setPoint(-100);
        person->setPoint(-100);
    }
    else if (person->getPoint() == 0 && person->getBow()){
        knowledgeBase[index]->setBow(true);
        knowledgeBase[index]->setPoint(10);
        person->setPoint(10);
    }
    else if (person->getPoint() == 10 && person->getArrow()){
        knowledgeBase[index]->setArrow(true);
        knowledgeBase[index]->setPoint(-100);
        person->setPoint(-100);
    }
}

bool Detective::conclude(int index){
    if(knowledgeBase[index]->getPoint() == 30){
        delete knowledgeBase[index];
        knowledgeBase[index] = new Murderer;
        return true;
    }
    else if(knowledgeBase[index]->getKnife() && knowledgeBase[index]->getBlood() && knowledgeBase[index]->getSurgeryGloves()){
        delete knowledgeBase[index];
        knowledgeBase[index] = new Doctor;
        return true;
    }
    else if(knowledgeBase[index]->getKnife() && knowledgeBase[index]->getBlood() && knowledgeBase[index]->getStench()){
        delete knowledgeBase[index];
        knowledgeBase[index] = new Butcher;
        return true;
    }
    else if(knowledgeBase[index]->getArrow() && knowledgeBase[index]->getBow()){
        delete knowledgeBase[index];
        knowledgeBase[index] = new Hunter;
        return true;
    }
    else if(knowledgeBase[index]->getHammer()){
        delete knowledgeBase[index];
        knowledgeBase[index] = new Builder;
        return true;
    }
    else if(knowledgeBase[index]->getMayorHat() && knowledgeBase[index]->getPocketWatch()){
        delete knowledgeBase[index];
        knowledgeBase[index] = new Mayor;
        return true;
    }
    else if(knowledgeBase[index]->getHarrow() && knowledgeBase[index]->getFarmerHat()){
        delete knowledgeBase[index];
        knowledgeBase[index] = new Farmer;
        return true;
    }
    return false;

}

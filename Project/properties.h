#ifndef PROPERTIES_H
#define PROPERTIES_H

#include <QString>
#include <QPushButton>
#include <QPixmap>
#include <QIcon>
#include <QObject>
#include <QRadioButton>
#include <QLabel>


class Properties : public QObject{
private:
    bool blood;
    bool knife;
    bool headMask;
    bool surgeryGloves;
    bool stench;
    bool farmerHat;
    bool harrow;
    bool mayorHat;
    bool pocketWatch;
    bool hammer;
    bool bow;
    bool arrow;
    int point;

public:
    QString profession;
    QString name;
    QRadioButton* radioButton;
    QLabel* label;
    Properties();
    virtual ~Properties();

    bool getBlood() const;
    void setBlood(bool newBlood);
    bool getKnife() const;
    void setKnife(bool newKnife);
    bool getSurgeryGloves() const;
    void setSurgeryGloves(bool newSurgeryGloves);
    bool getStench() const;
    void setStench(bool newStench);
    bool getFarmerHat() const;
    void setFarmerHat(bool newFarmerHat);
    bool getHarrow() const;
    void setHarrow(bool newHarrow);
    bool getMayorHat() const;
    void setMayorHat(bool newMayorHat);
    bool getPocketWatch() const;
    void setPocketWatch(bool newPocketWatch);
    bool getHammer() const;
    void setHammer(bool newHammer);
    bool getBow() const;
    void setBow(bool newBow);
    bool getArrow() const;
    void setArrow(bool newArrow);
    bool getHeadMask() const;
    void setHeadMask(bool newHeadMask);
    int getPoint() const;
    void setPoint(int newPoint);

};

#endif // PROPERTIES_H

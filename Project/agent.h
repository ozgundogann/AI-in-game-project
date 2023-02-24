#ifndef AGENT_H
#define AGENT_H

#include "professions.h"

class Detective
{
public:
    Properties* knowledgeBase[20];
    Detective();
    ~Detective();
    void examine(Properties* person, int index);
    void timer();
    bool conclude(int index);
};

#endif // AGENT_H

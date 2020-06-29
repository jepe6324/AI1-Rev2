// DirtState.h

#ifndef DIRT_STATE_H_INCLUDED
#define DIRT_STATE_H_INCLUDED

#include "State.h"

struct Agent;

struct DirtState : State
{
   DirtState(Agent* agent);
   virtual void Update();
   virtual void Enter();
   virtual void Exit(State* nextState);
};

#endif // !DIRT_STATE_H_INCLUDED

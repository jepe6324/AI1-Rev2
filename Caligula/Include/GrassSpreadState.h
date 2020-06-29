// GrassSpreadState.h

#ifndef GRASS_SPREAD_STATE_H_INCLUDED
#define GRASS_SPREAD_STATE_H_INCLUDED

#include "State.h"
#include "Timer.h"

struct Agent;

struct GrassSpreadState : State
{
   Timer timer_;
   int spreadAttempts_;

   GrassSpreadState(Agent* agent);

   virtual void Update();
   virtual void Enter();
   virtual void Exit(State* nextState);
};

#endif // !GRASS_SPREAD_STATE_H_INCLUDED

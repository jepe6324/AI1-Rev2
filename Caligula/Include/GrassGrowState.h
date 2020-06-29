// GrassGrowState.h

#ifndef GRASS_GROW_STATE_H_INCLUDED
#define GRASS_GROW_STATE_H_INCLUDED

#include "State.h"
#include "Timer.h"

struct Agent;

struct GrassGrowState : State
{
   Timer timer_;
   int growthStage_;

   GrassGrowState(Agent* agent);

   virtual void Update();
   virtual void Enter();
   virtual void Exit(State* nextState);
};

#endif // !GRASS_GROW_STATE_H_INCLUDED

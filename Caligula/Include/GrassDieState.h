// GrassDieState.h

#ifndef GRASS_DIE_STATE_H_INCLUDED
#define GRASS_DIE_STATE_H_INCLUDED

#include "State.h"
#include "Timer.h"

struct Agent;

struct GrassDieState : State
{
   Timer timer_;

   GrassDieState(Agent* agent);

   virtual void Update();
   virtual void Enter();
   virtual void Exit(State* nextState);
};

#endif // !GRASS_DIE_STATE_H_INCLUDED

// State.h

#ifndef STATE_H_INCLUDED
#define STATE_H_INCLUDED

struct Agent;

struct State
{
   Agent* agent_;

   State(Agent* agent) : agent_(agent){};

   virtual void Update() = 0;
   virtual void Enter() = 0;
   virtual void Exit(State* nextState) = 0;
};

#endif // !STATE_H_INCLUDED

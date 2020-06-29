#include "..\Include\GrassDieState.h"
#include "Agent.h"
#include "Grass.h"

#include "DirtState.h"

GrassDieState::GrassDieState(Agent* agent)
   :State(agent)
   ,timer_(5.f, true)
{
}

void GrassDieState::Update() // basically just keeps the grass in this state for a while and then returns to dirt state
{
   if (timer_.IsDone())
   {
      Exit(new DirtState(agent_));
   }
}

void GrassDieState::Enter()
{
   timer_.Start();

   Grass* grass = (Grass*)agent_;
   grass->growthStage_ = 5;
}

void GrassDieState::Exit(State* nextState)
{
   agent_->state_ = nextState;
   nextState->Enter();
   agent_ == nullptr; // If we had a manager this could be the flag for destruction
   delete this;
}

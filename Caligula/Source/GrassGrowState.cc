#include "..\Include\GrassGrowState.h"
#include "Agent.h"
#include "Grass.h"
#include "GrassSpreadState.h"

GrassGrowState::GrassGrowState(Agent* agent)
   :State(agent)
   ,timer_(2.f)
{
}

void GrassGrowState::Update()
{
   Grass* grass = (Grass*)agent_;
   if (timer_.IsDone())
   {
      timer_.Reset();

      growthStage_++;
   }

   if (growthStage_ >= 0 && growthStage_ < 6)
   {
      grass->growthStage_ = growthStage_;
   }

   if (growthStage_ > 3)
   {
      Exit(new GrassSpreadState(agent_));
   }
}

void GrassGrowState::Enter()
{
   growthStage_ = 1;
   timer_.Reset();
}

void GrassGrowState::Exit(State* nextState)
{
   agent_->state_ = nextState;
   if (nextState != nullptr)
   {
      nextState->Enter();
   }
   agent_ == nullptr; // If we had a manager this could be the flag for destruction
   delete this;
}

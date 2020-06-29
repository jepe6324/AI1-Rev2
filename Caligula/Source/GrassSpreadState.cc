#include "..\Include\GrassSpreadState.h"
#include "Agent.h"
#include "Grass.h"

#include "GrassDieState.h"

#include "Service.h"
#include "GameHandler.h"

GrassSpreadState::GrassSpreadState(Agent* agent)
   :State(agent)
   ,timer_(2.f, true)
{
   spreadAttempts_ = 0;
}

void GrassSpreadState::Update()
{
   if (timer_.IsDone())
   {
      Grass* grass = (Grass*)agent_;
      if (Service<GameHandler>::Get()->SpreadGrass(agent_->pos_) == false)
      {
         if (spreadAttempts_ > 2)
         {
            Exit(new GrassDieState(agent_));
         }
         spreadAttempts_++;
      }
      timer_.Reset();
   }

   // Timer should be halted when trampled
   // If it fails spreading it resets the timer and tries again
   // Dies after a succeful attempt or 3 failures
}

void GrassSpreadState::Enter()
{
   timer_.Start();
   Grass* grass = (Grass*)agent_;
   grass->growthStage_ = 4;
}

void GrassSpreadState::Exit(State* nextState)
{
   agent_->state_ = nextState;
   nextState->Enter();
   agent_ == nullptr; // If we had a manager this could be the flag for destruction
   delete this;
}

#include "..\Include\DirtState.h"
#include "Agent.h"
#include "Grass.h"

DirtState::DirtState(Agent* agent)
   :State(agent)
{
}

void DirtState::Update()
{
}

void DirtState::Enter()
{
   Grass* grass = (Grass*)agent_;
   grass->growthStage_ = 0;
}

void DirtState::Exit(State* nextState)
{
   agent_->state_ = nextState;
   nextState->Enter();
   agent_ == nullptr; // If we had a manager this could be the flag for destruction
   delete this;
}

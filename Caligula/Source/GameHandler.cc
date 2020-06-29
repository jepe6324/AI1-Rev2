#include "..\Include\GameHandler.h"
#include <SDL.h>
#include <Agent.h>

#include "Grass.h"
#include "Vector.h"
#include "Config.h"
#include "Random.h"

// AgentStates
#include "GrassGrowState.h"
#include "DirtState.h"

GameHandler::GameHandler() // Create all gameobjects needed for simulation
{
   Vector2 tmpPos;
   Vector2 tmpSize = { 32,32 };

   for (int i = 0; i < ( Config::INTERNAL_WIDTH / Config::TILE_SIZE ); i++)
   {
      for (int j = 0; j < ( Config::INTERNAL_HEIGHT / Config::TILE_SIZE ); j++)
      {
         tmpPos = { float(i), float(j) };
         
         Grass* grass = new Grass(tmpPos, tmpSize);
         AddAgent(grass);

         if (Random::Rand(0, 100) == 100)
         {
            grass->state_ = new GrassGrowState(grass);
         }
         else
         {
            grass->state_ = new DirtState(grass);
         }
         grass->state_->Enter();

         grass = nullptr;
      }
   }
}

GameHandler::~GameHandler()
{
}

void GameHandler::Update()
{
   for (Agent* agent : agents_)
   {
      agent->Update();
   }
}

void GameHandler::Render(SDL_Renderer* renderer)
{
   for (Agent* agent : agents_)
   {
      agent->Render(renderer);
   }
}

void GameHandler::AddAgent(Agent* agent)
{
   agents_.push_back(agent);
}

void GameHandler::DeleteAgent()
{
}

Agent* GameHandler::FindAgentByPosition(Vector2 pos, Agent::Type type)
{
   for (Agent* agent : agents_)
   {
      if (agent->pos_ == pos && agent->type_ == type)
      {
         return agent;
      }
   }
   return nullptr;
}

bool GameHandler::SpreadGrass(Vector2 pos)
{
   for (int i = 0; i < 4; i++)
   {
      Vector2 lookPos = pos;
      lookPos.x_ += Random::Rand(-1, 1);
      lookPos.y_ += Random::Rand(-1, 1);

      Grass* grass = (Grass*)FindAgentByPosition(lookPos, Agent::Type::GRASS);
      if (grass != nullptr && grass != FindAgentByPosition(pos, Agent::Type::GRASS))
      {
         return grass->Spread();
      }
   }
   return false;
}

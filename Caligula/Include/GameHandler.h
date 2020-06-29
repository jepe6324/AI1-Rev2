// GameHandler.h

#ifndef GAME_HANDLER_H_INCLUDED
#define GAME_HANDLER_H_INCLUDED

#include <vector>
#include "Vector.h"
#include "Agent.h"

struct SDL_Renderer;

struct GameHandler
{
   std::vector<Agent*> agents_;

   GameHandler();
   ~GameHandler();

   void Update();
   void Render(SDL_Renderer* renderer);

   void AddAgent(Agent* agent);
   void DeleteAgent();

   Agent* FindAgentByPosition(Vector2 pos, Agent::Type type);

   bool SpreadGrass(Vector2 pos);
};

#endif // !GAME_HANDLER_H_INCLUDED

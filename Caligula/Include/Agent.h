// Agent.h

#ifndef AGENT_H_INCLUDED
#define AGENT_H_INCLUDED

#include "Vector.h"
#include "Sprite.h"

struct SDL_Renderer;
struct State;

struct Agent
{
   enum Type {
      GRASS,
      WOLF,
      SHEEP
   };

   Vector2 pos_;
   Type type_;
   
   Sprite* sprite_;
   SDL_Rect drawHelper_;

   State* state_;

   Agent();
   Agent(const char* filepath,
         Vector2 spriteSize,
         Vector2 startPos,
         State* state);
   ~Agent();

   virtual void Update();
   virtual void Render(SDL_Renderer * renderer);
};

#endif // !AGENT_H_INCLUDED

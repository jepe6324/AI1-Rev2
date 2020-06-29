// Grass.h

#ifndef GRASS_H_INCLUDED
#define GRASS_H_INCLUDED

#include "Agent.h"

struct Grass : Agent
{
   Sprite* sprites_[6];
   bool trampled_;
   int growthStage_;

   Grass(Vector2 pos, Vector2 spriteSize);

   virtual void Update();
   bool Spread();
};

#endif // !GRASS_H_INCLUDED

#include "..\Include\Grass.h"
#include "Sprite.h"
#include "Service.h"
#include "Spritehandler.h"
#include "Config.h"
#include "State.h"
#include "GrassGrowState.h"

Grass::Grass(Vector2 pos, Vector2 spriteSize)
{
   pos_ = pos;
   sprites_[0] = Service<SpriteHandler>::Get()->CreateSprite("../Assets/dirt.png", 0, 0, spriteSize.x_, spriteSize.y_);
   sprites_[1] = Service<SpriteHandler>::Get()->CreateSprite("../Assets/dirt1.png", 0, 0, spriteSize.x_, spriteSize.y_);
   sprites_[2] = Service<SpriteHandler>::Get()->CreateSprite("../Assets/dirt2.png", 0, 0, spriteSize.x_, spriteSize.y_);
   sprites_[3] = Service<SpriteHandler>::Get()->CreateSprite("../Assets/dirt3.png", 0, 0, spriteSize.x_, spriteSize.y_);
   sprites_[4] = Service<SpriteHandler>::Get()->CreateSprite("../Assets/dirt4.png", 0, 0, spriteSize.x_, spriteSize.y_);
   sprites_[5] = Service<SpriteHandler>::Get()->CreateSprite("../Assets/dirt5.png", 0, 0, spriteSize.x_, spriteSize.y_);
   sprite_ = sprites_[0];

   drawHelper_.x = 0;
   drawHelper_.y = 0;
   drawHelper_.w = spriteSize.x_;
   drawHelper_.h = spriteSize.y_;

   trampled_ = false;

   type_ = GRASS;
}

void Grass::Update()
{
   this->Agent::Update();

   if (growthStage_ >= 0 && growthStage_ <6)
   {
      sprite_ = sprites_[growthStage_];
   }
   // Something connected to a timer to check when it's being trampled aka sense
}

bool Grass::Spread()
{
   if (growthStage_ == 0 && trampled_ == false)
   {
      state_->Exit(new GrassGrowState(this));
      return true;
   }
   return false;
}

#include "Agent.h"
#include "Sprite.h"
#include "Service.h"
#include "Spritehandler.h"
#include "Config.h"
#include "State.h"

Agent::Agent()
{
   sprite_ = nullptr;
   state_ = nullptr;
}

Agent::Agent(const char* filepath, Vector2 spriteSize, Vector2 startPos, State* state)
{
   sprite_ = Service<SpriteHandler>::Get()->CreateSprite(filepath, 0, 0, spriteSize.x_, spriteSize.y_);
   drawHelper_.w = spriteSize.x_;
   drawHelper_.h = spriteSize.y_;

   state_ = state;
}

Agent::~Agent()
{
}

void Agent::Update()
{
   if (state_ != nullptr)
   {
      state_->Update();
   }

   drawHelper_.x = pos_.x_ * Config::TILE_SIZE;
   drawHelper_.y = pos_.y_ * Config::TILE_SIZE;
}

void Agent::Render(SDL_Renderer* renderer)
{
   SDL_RenderCopy(renderer, sprite_->GetTexture(), &sprite_->GetArea(), &drawHelper_);

   //SDL_SetRenderDrawColor(); // This is for drawing a border around sprites
   if (Config::DEBUGRENDER == TRUE)
   {
      SDL_RenderDrawRect(renderer, &drawHelper_);
   }
}
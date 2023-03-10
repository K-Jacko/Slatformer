//
// Created by Wake on 2/26/2023.
//

#ifndef SLATFORMER_KEYBOARDCOMPONENT_H
#define SLATFORMER_KEYBOARDCOMPONENT_H
#include "ECS.h"
#include "Game.h"
#include "Components.h"

class KeyboardComponent : public Component
{
public:
    TransformComponent *transform;
    SpriteComponent *spriteComponent;
    ColliderComponent* colliderComponent;
    bool cnt = false;

    void Init() override
    {
        transform = &entity->getComponent<TransformComponent>();
        spriteComponent = &entity->getComponent<SpriteComponent>();
        colliderComponent = &entity->getComponent<ColliderComponent>();
    }

    void Update() override
    {
        if(Game::event.type == SDL_MOUSEBUTTONDOWN)
        {
            if(!cnt)
            {
                cnt = true;
            }
        } else if(Game::event.type == SDL_MOUSEBUTTONUP)
        {
            spriteComponent->Play("resources/Character/_Idle.png");
            cnt = false;
        }
        if(Game::event.type == SDL_KEYDOWN)
        {
            switch (Game::event.key.keysym.sym) {
                case SDLK_w:
                    transform->velocity.y = -1;
                    break;
                case SDLK_s:
                    transform->velocity.y = 1;
                    break;
                case SDLK_a:
                    transform->velocity.x = -1;
                    spriteComponent->Play("resources/Character/_Run.png");
                    spriteComponent->flip = SDL_FLIP_HORIZONTAL;
                    break;
                case SDLK_d:
                    transform->velocity.x = 1;
                    spriteComponent->Play("resources/Character/_Run.png");
                    spriteComponent->flip = SDL_FLIP_NONE;
                    break;
                case SDLK_e:
                    spriteComponent->Play("resources/Character/_Attack2NoMovement.png");
                    break;
                case SDLK_SPACE:
                    Game::isDebug = true;
            }
        }
        if(Game::event.type == SDL_KEYUP)
        {
            switch (Game::event.key.keysym.sym) {
                case SDLK_w:
                    transform->velocity.y = 0;
                    break;
                case SDLK_s:
                    transform->velocity.y = 0;
                    break;
                case SDLK_a:
                    transform->velocity.x = 0;
                    spriteComponent->Play("resources/Character/_Idle.png");
                    break;
                case SDLK_d:
                    transform->velocity.x = 0;
                    spriteComponent->Play("resources/Character/_Idle.png");
                    break;
                case SDLK_e:
                    spriteComponent->Play("resources/Character/_Idle.png");
                case SDLK_SPACE:
                    Game::isDebug = false;
                    break;

            }
        }
    }
};


#endif //SLATFORMER_KEYBOARDCOMPONENT_H

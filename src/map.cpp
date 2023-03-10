#include "Map.h"
#include "TextureManager.h"


int Level1[16][27] = {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}

};
Map::Map()
{
    grass = TextureManager::LoadTexture("resources/Tileset.png");
    half = TextureManager::LoadTexture("resources/Tileset.png");
    background = TextureManager::LoadTexture("resources/Background.png");
    wall = TextureManager::LoadTexture("resources/Tileset.png");

    LoadMap(Level1);

    //Grass
    src.x = src.y = 0;
    src.w = dst.w = 48;
    src.h = dst.h = 48;
    dst.x = dst.y = 0;

    //Background
    bsrc.x = 0;
    bsrc.y = 0;
    bsrc.w = 928;
    bsrc.h = 793;
    bdst.x = 0;
    bdst.y = 0;
    bdst.w = 1280;
    bdst.h = 720;

    //HalfBlock
    dsrc.x = 48;
    dsrc.y = 32;
    ddst.x = ddst.y = 0;
    dsrc.w = 32;
    ddst.w = 48;
    dsrc.h = ddst.h = 16;

    //Wall
    wsrc.x = 48;
    wsrc.y = 48;
    wdst.x = wdst.y = 0;
    wsrc.w = 32;
    wdst.w = 48;
    wsrc.h = wdst.h = 46;

}

Map::~Map()
{
    SDL_DestroyTexture(grass);
    SDL_DestroyTexture(wall);
    SDL_DestroyTexture(half);
    SDL_DestroyTexture(background);
}

void Map::LoadMap(int arr[16][27])
{
    for(int row = 0; row < 16; ++row)
    {
        for (int col = 0; col < 27; ++col) {
            map[row][col] = arr[row][col];
        }
    }

}

void Map::DrawMap()
{
    int type = 0;
    TextureManager::Draw(background,bsrc,bdst);
    for(int row = 0; row < 16; ++row)
    {
        for (int col = 0; col < 27; ++col) {
            type = map[row][col];
            dst.x = ddst.x = wdst.x = col * 48;
            dst.y = ddst.y = wdst.y = row * 46;
            switch (type) {
                case 0:
                    break;
                case 1:
                    TextureManager::Draw(grass, src, dst);
                    break;
                case 2:
                    TextureManager::Draw(half, dsrc, ddst);
                    break;
                case 3:
                    TextureManager::Draw(wall,wsrc,wdst);
                    break;
                
            }
        }
    }
}
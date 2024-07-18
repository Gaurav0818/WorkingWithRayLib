#pragma once

#include <raylib.h>
#include <deque>

class Snake
{
public:
    Snake()
    {
        InitAudioDevice();
        eatSound = LoadSound("Sound/eat.mp3");
        hitSound = LoadSound("Sound/ImpactSound.ogg");
    }
    ~Snake()
    {
        UnloadSound(hitSound);
        UnloadSound(eatSound);
        CloseAudioDevice();
    }

    void Draw();
    void Update();
    void SetDirection(Vector2 dir) {_dir = dir; }

    bool CheckCollisionWithFood(Vector2 pos);
    bool ElementInDeque(Vector2 pos);
    void IncreaseSize();

    void Reset() {_body = {Vector2{7,9}, Vector2{6,9}, Vector2{5,9}};  _dir ={1,0};}

    bool CheckCollisionWithEdge();
    Sound eatSound;
    Sound hitSound;

private:
    std::deque<Vector2> _body = {Vector2{7,9}, Vector2{6,9}, Vector2{5,9}};
    Vector2 _dir = {1,0};
    double _lastUpdateInterval =0;
};



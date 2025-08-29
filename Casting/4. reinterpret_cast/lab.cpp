#include <iostream>
#include <string>
#include <cstring>

struct GameState
{
    int level;
    int health;
    int points;
    bool GameComplete;
    bool Bossfeated;
};

int main()
{
    GameState gm = {66, 999, 100, false, true};
    char bagOfbytes[sizeof(gm)];
    std::memcpy(bagOfbytes, &gm, sizeof(GameState));
    std::cout << *reinterpret_cast<int *>(bagOfbytes) << "\n";
    std::cout << *reinterpret_cast<int *>(bagOfbytes + 4) << "\n";
    std::cout << *reinterpret_cast<int *>(bagOfbytes + 8) << "\n";
    std::cout << *reinterpret_cast<bool *>(bagOfbytes + 12) << "\n";
    std::cout << *reinterpret_cast<bool *>(bagOfbytes + 13) << "\n";
}

#include <iostream>
#include <memory>  // For std::unique_ptr

class Game {
public:
    Game() {
        std::cout << "Game created!\n";
    }
    ~Game() {
        std::cout << "Game destroyed!\n";
    }
    void play() {
        std::cout << "Playing the game!\n";
    }
};

int main() {
    // Creating a unique pointer to a Game object
    std::unique_ptr<Game> gamePtr = std::make_unique<Game>();

    // Using the object
    gamePtr->play();  // Accessing the play function


    std::unique_ptr<Game> anotherGamePtr = std::move(gamePtr);
    if (!gamePtr) {
        std::cout << "gamePtr no longer owns the object!\n";
    }
    anotherGamePtr->play(); // This works because anotherGamePtr now owns the object.

    // When gamePtr goes out of scope, the Game object is automatically destroyed.
    return 0;
}
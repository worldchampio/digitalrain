#include <string>

class Raindrop{
public:
    Raindrop(int xPos);
    void update();
    int rng(int min=44, int max=123);
private:
    std::string int2Str(int i);
    int rate{0};
    int xPos{0};
    std::string str;
    std::string blank;
};
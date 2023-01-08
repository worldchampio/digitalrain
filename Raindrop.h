#include <string>

class Raindrop{
public:
    Raindrop(int xPosition, int refreshRate, int length);
    void update(int i, int rng);
private:
    std::string int2Str(int i);
    std::string str;
};
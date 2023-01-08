#include <string>

class Raindrop{
public:
    Raindrop(int xPos, bool startAsBlank);
    void update(int randomnum);
    int rng(int min=44, int max=123);
    void blankSpace(int length);
private:
    std::string int2Str(int i);
    int rate{0};
    int xPos{0};
    std::string str;
    std::string blank;
};
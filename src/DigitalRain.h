#include <string>
#include <vector> 

class Raindrop;

class DigitalRain{
public:
    DigitalRain(int iterations, int delay);
    ~DigitalRain();
private:
    std::vector<Raindrop*> rain;
};
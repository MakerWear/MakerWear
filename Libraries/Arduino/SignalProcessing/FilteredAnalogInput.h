#include <Arduino.h>
#include <math.h>

#define AVERAGE         0
#define HANNING         1

class FilteredAnalogInput
{
  private:
    static const int MAX_SIZE = 50;
    int qSize;
    int queue[MAX_SIZE];
    int qPush;
    int qPop;
    int pin_number;
    float hanning_weights[MAX_SIZE];
    float alpha;
    float beta;
    float hanning_sum;

    void push(int);
    int pop();
    void calculateHanningWeights();

  public:
    FilteredAnalogInput(int, int);
    int filteredAnalogRead(int);
};



float mapF()
{

}

int mapAndCut()
{

}

int cutAndMap()
{

}

#include <Arduino.h>
#include <math.h>

#define AVERAGE         0
#define HANNING         1

class SignalProcessing
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
    SignalProcessing(int, int);
    int filteredAnalogRead(int);
};

float mapF(float x, float in_min, float in_max, float out_min, float out_max);
long mapAndCut(long x, long in_min, long in_max, long out_min, long out_max);
long cutAndMap(long x, long in_min, long in_max, long out_min, long out_max);

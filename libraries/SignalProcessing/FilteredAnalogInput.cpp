#include "FilteredAnalogInput.h"

FilteredAnalogInput::FilteredAnalogInput(int pin_number, int window_size)
{
  if(window_size > MAX_SIZE)
    this->qSize = MAX_SIZE;
  else if(window_size <= 0)
    this->qSize = 1;
  else
    this->qSize = window_size;

  this->qPush = -1;
  this->qPop = -1;

  this->pin_number = pin_number;

  for(int i = 0; i < this->qSize; i++)
    this->queue[i] = 0;

  this->alpha = 0.54;
  this->beta = 0.46;
  calculateHanningWeights();
}


void FilteredAnalogInput::calculateHanningWeights()
{
  hanning_sum = 0;

  for(int i = 0; i < qSize; i++)
  {
    hanning_weights[i] = alpha - beta * (float)cos((2*3.14*i)/(qSize-1));
    hanning_sum += hanning_weights[i];
  }
}


int FilteredAnalogInput::filteredAnalogRead(int filter)
{
  int input_val = analogRead(this->pin_number);
  float avg_val = 0.0;

  if(this->qPush != this->qPop)
    //when the queue is still not full:
    push(input_val);
  else
  {
    pop();
    push(input_val);
  }

  if(filter == AVERAGE)
  {
    for(int i = 0; i < this->qSize; i++)
      avg_val += this->queue[i];

    return avg_val/this->qSize;
  }
  else if(filter == HANNING)
  {
    for(int i = 0; i < this->qSize; i++)
      avg_val += this->queue[i]*hanning_weights[i];

    return avg_val/this->hanning_sum;
  }
}

void FilteredAnalogInput::push(int x)
{
    qPush = (qPush + 1) % qSize;
    queue[qPush] = x;
}

int FilteredAnalogInput::pop()
{
    qPop = (qPop + 1) % qSize;
    return queue[qPop];
}

long mapAndCut(long x, long in_min, long in_max, long out_min, long out_max)
{
    long val = (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;

    if(val < out_min)
    {
      val = out_min;
    }
    else if(val > out_max)
    {
      val = out_max;
    }

    return val;
}

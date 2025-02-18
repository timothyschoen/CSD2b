#include "SynthClass.h"

class MoogFilter : public Synth
{
public:
MoogFilter();
void init();
void calc();
float process(float x);
~MoogFilter();
void setRes(float r);
protected:
float cutoff;
float res;
float fs;
float y1,y2,y3,y4;
float oldx;
float oldy1,oldy2,oldy3;
float x;
float r;
float p;
float k;
};

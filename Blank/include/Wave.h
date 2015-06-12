#ifndef WAVE_H
#define WAVE_H

class Wave
{
private:
	int basic, armoured, waveSize;
public:
	Wave();
	Wave(int basic, int armoured);
	int getBasic();
	int getArmoured();
	int getWaveSize();
};

#endif WAVE_H
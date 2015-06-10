#include "Wave.h"

Wave::Wave()
{
	waveSize = 0;
}

Wave::Wave(int waveSize)
{
	this->waveSize = waveSize;
}

int Wave::getWaveSize()
{
	return waveSize;
}
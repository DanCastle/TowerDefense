#include "Wave.h"

Wave::Wave()
{
	basic = 0;
	armoured = 0;
}

Wave::Wave(int basic, int armoured)
{
	this->basic = basic;
	this->armoured = armoured;

	waveSize = basic + armoured;
}

int Wave::getBasic()
{
	return basic;
}

int Wave::getArmoured()
{
	return armoured;
}

int Wave::getWaveSize()
{
	return waveSize;
}
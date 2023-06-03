#pragma once
#ifndef _VITALS_H
#define _VITALS_H

#include <iostream>


class Vitals{
public:
	
	Vitals(float bt, int bp, int hr, int rr, bool ioifl) :
		_bodyTemperature(bt),
		_bloodPressure(bp),
		_heartRate(hr),
		_respiratoryRate(rr),
		_isOnInitFileLoad(ioifl)
	{ }

	float BT() const { return _bodyTemperature; }
	int BP() const { return _bloodPressure; }
	int HR() const { return _heartRate; }
	int RR() const { return _respiratoryRate; }
	bool isOnInitFileLoad() const { return _isOnInitFileLoad; }

	friend std::ostream& operator<<(std::ostream& os, const Vitals& p);

protected:
	
	float _bodyTemperature;
	int _bloodPressure;
	int _heartRate;
	int _respiratoryRate;
	bool _isOnInitFileLoad;

};

#endif
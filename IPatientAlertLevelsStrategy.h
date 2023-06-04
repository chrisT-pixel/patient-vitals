#pragma once
#ifndef _IPATIENTALERTLEVELSSTRATEGY_H
#define _IPATIENTALERTLEVELSSTRATEGY_H
#include <iostream>
#include "Vitals.h"

//forward declare Patient
class Patient;

/*	alert levels for patient vitals
	green = 0, yellow = 1, orange = 2, red = 3 */
enum class AlertLevel { Green, Yellow, Orange, Red };

class IPatientAlertLevelsStrategy {
public:

	virtual AlertLevel calculateAlertLevels(const Patient& patient, const Vitals* v) const = 0;

};

#endif
#pragma once
#include <iostream>
#include "Vitals.h"

//forward declare Patient
class Patient;

// alert levels for patient vitals
enum class AlertLevel { Green, Yellow, Orange, Red };

class IPatientAlertLevelsStrategy {
public:

	virtual AlertLevel calculateAlertLevels(const Patient& patient, const Vitals* v) = 0;

};
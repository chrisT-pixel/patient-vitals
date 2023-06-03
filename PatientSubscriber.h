#pragma once
#ifndef _PATIENTSUBSCRIBER_H
#define  _PATIENTSUBSCRIBER_H

class Patient;

class PatientSubscriber {
public:
	
	virtual void alertLevelHasChanged(Patient* p) = 0;
};

#endif
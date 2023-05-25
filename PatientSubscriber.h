#pragma once

class Patient;

class PatientSubscriber {
public:
	virtual void alertLevelHasChanged(Patient* p) = 0;


};
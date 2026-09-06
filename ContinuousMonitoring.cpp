#include <iostream>
using namespace std;

#include "ContinuousMonitoring.h"
#include "Vet.h"
#include "Decorator.h"

ContinuousMonitoring::ContinuousMonitoring(Vet* patient, int interval) : Decorator(patient) {
	this->monitoringInterval = interval;
}

void ContinuousMonitoring::print() const {
	this->patient->print();
	cout << "Continuous Monitoring: -- " << this->monitoringInterval << " --" << endl;
}

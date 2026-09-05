#include <string>
using namespace std;

#ifndef INTREATMENT_H
#define INTREATMENT_H

#include "State.h"

class InTreatment: public State
{
	public:
		InTreatment();
		void handle(Patient* patient) override;
		~InTreatment();
		string getStateName() const override;
};

#endif

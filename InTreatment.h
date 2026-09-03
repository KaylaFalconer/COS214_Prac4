#include <string>
using namespace std;

#ifndef INTREATMENT_H
#define INTREATMENT_H

#include "State.h"

class InTreatment: public State
{
	public:
		void examine(Patient& patient) override;
		void treat(Patient& patient) override;
		void discharge(Patient& patient) override;
		
		string getStateName() const override;
};

#endif

#include <string>
using namespace std;

#ifndef DISCHARGED_H
#define DISCHARGED_H

#include "State.h"

class Discharged: public State
{
	public:
		void examine(Patient& patient) override;
		void treat(Patient& patient) override;
		void discharge(Patient& patient) override;
		
		string getStateName() const override;
};

#endif

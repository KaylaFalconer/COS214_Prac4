#include <string>
using namespace std;

#ifndef UNDEREXAMINATION_H
#define UNDEREXAMINATION_H

#include "State.h"

class UnderExamination: public State
{
	public:
		void examine(Patient& patient) override;
		void treat(Patient& patient) override;
		void discharge(Patient& patient) override;
		
		string getStateName() const override;
};

#endif

#include <string>
using namespace std;

#ifndef UNDEREXAMINATION_H
#define UNDEREXAMINATION_H

#include "State.h"

class UnderExamination: public State
{
	public:
		UnderExamination();
		void handle(Patient* patient) override;
		string getStateName() const override;
		~UnderExamination();
};

#endif

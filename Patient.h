#ifndef PATIENT_H
#define PATIENT_H

#include <string>
using namespace std;

#include "Vet.h"

class State;

class Patient: public Vet
{
	private:
		string id;
		string type;
		int age;
		State* state;

	public:
		Patient(const string& id, const string& name, const string& type, int age);

		void print() const override;
		void setState(State* state);
		void advance();

		string getStateName() const;
		string getId() const;
		string getName() const;
		void readmit();
		bool hasEmergencyPriority() const override;

		virtual ~Patient();
};

#endif

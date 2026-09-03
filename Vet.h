#ifndef VET_H
#define VET_H

#include <string>
using namespace std;

class Vet
{
	protected:
		string name;

	public:
		Vet(const string& name);

		string getName() const;
		virtual void print() const = 0;
		virtual bool hasEmergencyPriority() const = 0;

		virtual ~Vet();
};

#endif

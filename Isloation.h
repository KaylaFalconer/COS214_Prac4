#include <string>
using namespace std;

#ifndef ISOLATION_H
#define ISOLATION_H

#include "Decorator.h"

class Isolation: public Decorator
{
	private:
		string reason;

	public:
		Isolation(Vet* patient, const string& reason);

		void print() const override;
};

#endif

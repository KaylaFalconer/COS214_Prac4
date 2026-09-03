using namespace std;

#ifndef ITERATOR_H
#define ITERATOR_H

class Vet;

class Iterator
{
	public:
		virtual Vet* next() = 0;
		virtual bool hasNext() const = 0;

		virtual ~Iterator();
};

#endif

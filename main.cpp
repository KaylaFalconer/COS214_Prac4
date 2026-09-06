#include "VetSystem.h"
#include "Patient.h"
#include "Unit.h"

using namespace std;

int main() {
    Unit* vetHospital = new Unit("Veterinary Hospital");
    Unit* emergencyDep = new Unit("Emergency Department");
    Unit* treatment1 = new Unit("Treatment Room 1");
    Unit* treatment2 = new Unit("Treatment Room 2");
    Unit* surgeryDep = new Unit("Surgery Department");
    Unit* theatre1 = new Unit("Theatre 1");
    Unit* generalCare = new Unit("General Care");
    Unit* wardA = new Unit("Ward A");
    Patient* oreo = new Patient("010", "Oreo", "Canis lupus familiaris", 4);
    Patient* max = new Patient("011", "Max", "Felis catus", 2);
    Patient* buddy = new Patient("012", "Buddy", "Psittacus", 5);
    Patient* milo = new Patient("013", "Milo", "Canis lupus familiaris", 1);
    Patient* lucky = new Patient("014", "Lucky", "Felis catus", 3);

    treatment1->add(oreo);
    treatment1->add(max);
    treatment2->add(buddy);
    emergencyDep->add(treatment1);
    
    theatre1->add(milo);
    surgeryDep->add(theatre1);

    wardA->add(lucky);
    generalCare->add(wardA);

    vetHospital->add(emergencyDep);
    vetHospital->add(surgeryDep);
    vetHospital->add(generalCare);
    return 0;
}
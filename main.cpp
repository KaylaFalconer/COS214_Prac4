#include "Patient.h"
#include <iostream>

int main() {
    std::cout<<"----------PATIENT STATE CHANGES DEMO---------------"<<std::endl;
    // Create a patient
    Patient* oreo = new Patient("P001", "Oreo", "Dog", 3);
    oreo->print();

    std::cout << "\n--- Advancing through treatment ---\n";
    oreo->advance();   // Admitted to UnderExamination
    oreo->advance();   // UnderExamination to InTreatment
    oreo->advance();   // InTreatment to Discharged
    oreo->advance();   // Discharged to cannot advance

    std::cout << "\n--- Re‑admitting the patient ---\n";
    oreo->readmit();   // Discharged to Admitted
    oreo->print();

    std::cout << "\n--- Advancing again (new visit) ---\n";
    oreo->advance();   // Admitted to UnderExamination
    oreo->advance();   // UnderExamination to InTreatment
    oreo->advance();   // InTreatment to Discharged

    delete oreo;
    return 0;
}
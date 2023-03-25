#include "Advantages.h"

Hospital Advantages::find_nearest(Building *b)
{
    HospitalsBase hospitalB;
    Hospital nearest;
    Infrastructure h;
    vector<Hospital>hoV = hospitalB.getHospitals();
    nearest = hoV[0];
    for (int i = 0; i < hoV.size(); i++) {
        hoV[i].compiude_distanse(b);
        Hospital temp =hoV[i];
       
        if (temp.compiude_distanse(b) < nearest.compiude_distanse(b)) {
           nearest=temp;
        }
    }
    return nearest;
}

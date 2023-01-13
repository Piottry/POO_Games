#ifndef CENTRE_LOGISTIQUE_H
#define CENTRE_LOGISTIQUE_H

#include <vector>

class centre_logistique
{
public:
    centre_logistique(int);
    std::vector<double> direction;
    void random_();
    int step=0;



    void mutate();
};

#endif // CENTRE_LOGISTIQUE_H

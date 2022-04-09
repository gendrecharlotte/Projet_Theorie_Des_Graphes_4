#include"Perturbations.h"

///CONSTRUCTEURS/DESTRUCTEURS
Perturbation::Perturbation(){}
Perturbation::~Perturbation(){}





void Perturbation::init(AllAvions allavions, Coordonnees coord1, Coordonnees coord2)
{
    for(auto &a : (allavions.get_liste_avions()))
    {


        if(a->get_coo().get_x()>=coord1.get_x() && a->get_coo().get_x()<=coord2.get_x()
            && a->get_coo().get_y()>=coord1.get_y() && a->get_coo().get_y()>=coord2.get_y())
        {
            if((a->get_type()) == 1)
            {
                //vitesse et consommation reduite de 10%
                a->set_vitesse(a->get_vitesse() *0.9);
                a->set_consomation(a->get_consomation()*0.9);

            }
            else if((a->get_type()) == 2)
            {
                //vitesse et consommation reduite de 30%
                a->set_vitesse(a->get_vitesse() *0.7);
                a->set_consomation(a->get_consomation()*0.7);
            }
            else if((a->get_type()) == 3)
            {
                //vitesse et consommation reduite de 50%
                a->set_vitesse(a->get_vitesse() *0.5);
                a->set_consomation(a->get_consomation()*0.5);
            }
        }


    }

}

/**
 *  @file  Particles.cpp
 *  @brief  
 *
 *
 *  @author  Jean-Baptiste Sauvan <sauvan@llr.in2p3.fr>
 *
 *  @date    20/11/2015
 *
 *  @internal
 *     Created :  20/11/2015
 * Last update :  20/11/2015 13:50:51
 *          by :  JB Sauvan
 *
 * =====================================================================================
 */




#include "AnHiMaCMG/H2TausCommon/interface/Particles.h"


using namespace AnHiMa;


/*****************************************************************/
GenParticle::GenParticle():TLorentzVector()
/*****************************************************************/
{
}
/*****************************************************************/
GenParticle::~GenParticle()
/*****************************************************************/
{
}


/*****************************************************************/
void GenParticle::computeChargeFromPdgId()
/*****************************************************************/
{
    switch(abs(int(pdgId)))
    {
        case 1:
            charge = -1./3.;
            break;
        case 2:
            charge = 2./3.;
            break;
        case 3:
            charge = -1./3.;
            break;
        case 4:
            charge = 2./3.;
            break;
        case 5:
            charge = -1./3.;
            break;
        case 6:
            charge = 2./3.;
            break;
        case 11:
            charge = -1.;
            break;
        case 12:
            charge = 0.;
            break;
        case 13:
            charge = -1.;
            break;
        case 14:
            charge = 0.;
            break;
        case 15:
            charge = -1.;
            break;
        case 16:
            charge = 0.;
            break;
        case 21:
            charge = 0.;
            break;
        case 22:
            charge = 0.;
            break;
    };
    if(pdgId<0.) charge = -charge;
}


/*****************************************************************/
Muon::Muon():TLorentzVector()
/*****************************************************************/
{
}
/*****************************************************************/
Muon::~Muon()
/*****************************************************************/
{
}
/*****************************************************************/
Tau::Tau():TLorentzVector()
/*****************************************************************/
{
}
/*****************************************************************/
Tau::~Tau()
/*****************************************************************/
{
}

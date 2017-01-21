#ifndef Ar40NeutronGenerator_hh_
#define Ar40NeutronGenerator_hh_

class G4ParticleGun;
class G4Event;
class Protium::Math::Random;

namespace ar40
{

/*!
  \class Ar40NeutronGenerator
 
  \ingroup ar40
 
  \brief Code for defining the primary vertex of cosmic rays
 
      Energy and zenith angle defined for muons, neutrons, and nucleons.
      To save time, first pick a position on the x equals 0 plane near
      the detector plane_position, then use the zenith angle to pick a
      position outside the detector global_position aimed in to the
      plane_position.
 
  \author Kevin Wierman
 
  \version 1.0
 
  \date Oct 1, 2013
 
  \contact kevin.wierman@pnnl.gov

  \reference http://journals.aps.org/pr/pdf/10.1103/PhysRev.116.445
 
 */

  class Ar40NeutronGenerator : public G4ParticleGun {
    Random fDice;
  public:
    Ar40NeutronGenerator();
    virtual ~Ar40NeutronGenerator();
    virtual void GeneratePrimaryVertex(G4Event * evt);
    void SetNewSeed();

  protected:

  };

}
#endif

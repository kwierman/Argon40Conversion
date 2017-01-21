
#ifndef Ar40Hit_hh_
#define Ar40Hit_hh_

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"

namespace ar40
{

  class Ar40Hit : public G4VHit {
  private:

  public:

    Ar40Hit();
    ~Ar40Hit();
    Ar40Hit(const Ar40Hit &);
    const Ar40Hit & operator=(const Ar40Hit &);
    G4int operator==(const Ar40Hit &) const;

    inline void* operator  new(size_t);
    inline void operator  delete(void *);
  };

  typedef ::G4THitsCollection < Ar40Hit > Ar40HitsCollection;

  extern ::G4Allocator < Ar40Hit > Ar40HitAllocator;

}

#endif



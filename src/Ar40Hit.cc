#include "Ar40Hit.hh"

#include "G4UnitsTable.hh"
#include "G4VVisManager.hh"
#include "G4Circle.hh"
#include "G4Colour.hh"
#include "G4VisAttributes.hh"



namespace ar40{

  ::G4Allocator < Ar40Hit > Ar40HitAllocator;

  Ar40Hit::Ar40Hit()
  {
  }

  Ar40Hit::~Ar40Hit()
  {
  }

  Ar40Hit::Ar40Hit(const Ar40Hit&) : G4VHit()
  {
  }

  const Ar40Hit& Ar40Hit::operator=(const Ar40Hit&)
  {
    return *this;
  }

  G4int Ar40Hit::operator==(const Ar40Hit&) const
  {
    return 1;
  }

  inline void* Ar40Hit::operator  new(size_t)
  {
     void *aHit;
     aHit = (void *) Ar40HitAllocator.MallocSingle();
     return aHit;
  }

  inline void Ar40Hit::operator  delete(void *aHit)
  {
     Ar40HitAllocator.
         FreeSingle((Ar40Hit *) aHit);
  }
}
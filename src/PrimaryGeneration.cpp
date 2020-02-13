// -----------------------------------------------------------------------------
//  G4Basic | PrimaryGeneration.cpp
//
//  Class for the definition of the primary generation action.
//   * Author: Justo Martin-Albo
//   * Creation date: 14 Aug 2019
// -----------------------------------------------------------------------------

#include "PrimaryGeneration.h"

#include <G4ParticleDefinition.hh>
#include <G4SystemOfUnits.hh>
#include <G4IonTable.hh>
#include <G4PrimaryParticle.hh>
#include <G4PrimaryVertex.hh>
#include <G4Event.hh>
#include <G4Electron.hh>


PrimaryGeneration::PrimaryGeneration():
  G4VUserPrimaryGeneratorAction()
{

}


PrimaryGeneration::~PrimaryGeneration()
{
}


void PrimaryGeneration::GeneratePrimaries(G4Event* event)
{
  //G4ParticleDefinition* pdef = G4IonTable::GetIonTable()->GetIon(10, 20, 0.);
  G4ParticleDefinition* pdef = G4Electron::Definition();
  if (!pdef)
    G4Exception("SetParticleDefinition()", "[IonGun]",
                FatalException, " can not create ion ");

  G4PrimaryParticle* particle = new G4PrimaryParticle(pdef);
  particle->SetMomentumDirection(G4ThreeVector(0.,0.,1.));
  particle->SetKineticEnergy(100.*keV);

  G4PrimaryVertex* vertex = new G4PrimaryVertex(G4ThreeVector(), 0.);
  vertex->SetPrimary(particle);

  event->AddPrimaryVertex(vertex);
}

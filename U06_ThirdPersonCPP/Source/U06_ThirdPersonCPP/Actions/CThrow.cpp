#include "CThrow.h"
#include "Global.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"

ACThrow::ACThrow()
{
	CHelpers::CreateComponent(this, &Sphere, "Sphere");
	CHelpers::CreateComponent(this, &ThrowParticle, "ThrowParticle", Sphere);
	
	CHelpers::CreateActorComponent(this, &Projectile, "Projectile");

	InitialLifeSpan = 3.f;

	Projectile->InitialSpeed = 4000.f;
	Projectile->MaxSpeed = 8000.f;
	Projectile->ProjectileGravityScale = 0.f;
}

void ACThrow::BeginPlay()
{
	Super::BeginPlay();
	
}


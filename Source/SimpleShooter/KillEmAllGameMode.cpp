// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAllGameMode.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "ShooterAIController.h"

void AKillEmAllGameMode::PawnKilled(APawn* PawnKilled)
{
    Super::PawnKilled(PawnKilled);
    
    APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());

    if(PlayerController != nullptr)
    {
        EndGame(false);
    }
    //For loop over all ShooterAI in the world
    for(AShooterAIController* Controller : TActorRange<AShooterAIController>(GetWorld()))
    {
        //Check if is not dead
        if(!Controller->IsDead())
        {
            //Early return since they arent all dead
            return;
        }
    }
    //Didnt return in the for loop return true
    EndGame(true);
}

void AKillEmAllGameMode::EndGame(bool bIsPlayerWinner)
{
    for(AController* Controller : TActorRange<AController>(GetWorld()))
    {
        bool bIsWinner = Controller->IsPlayerController() == bIsPlayerWinner;
        Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);
    }
}
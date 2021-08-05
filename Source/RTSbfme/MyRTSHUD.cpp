

#include "MyRTSHUD.h"

void AMyRTSHUD::DrawHUD()
{
		if (bStartSelect)
		{
			if (FoundActors.Num() > 0)
			{
				for (int32 i = 0; i < FoundActors.Num(); i++)
				{
					FoundActors[i]->SetDeselected();
				}
			}
		
			FoundActors.Empty();
			CurrentPoint = GetMousePossition();

			DrawRect(FLinearColor(0, 0, 0,.20f), InitialPoint.X, InitialPoint.Y, CurrentPoint.X - InitialPoint.X, CurrentPoint.Y - InitialPoint.Y);
			GetActorsInSelectionRectangle<ARTSbfmeCharacter>(InitialPoint, CurrentPoint, FoundActors, false, false);

			if (FoundActors.Num() > 0)
			{
				for (int32 i = 0; i < FoundActors.Num(); i++)
				{
					FoundActors[i]->SetSelected();
				}
			}
		}
}

FVector2D AMyRTSHUD::GetMousePossition()
{
	float possitionX;
	float possitionY;
	GetOwningPlayerController()->GetMousePosition(possitionX, possitionY);

	return FVector2D(possitionX, possitionY);
}
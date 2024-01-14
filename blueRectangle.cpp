#include "blueRectangle.h"
#include "textureManager.h"

BlueRectangle::BlueRectangle(const char* filename, SDL_Renderer* ren, int bRow, int bColumn)
{
	renderer = ren;
	objectTexture = TextureManager::LoadTexture(filename, ren);

	boardRow = bRow;
	boardColumn = bColumn;
}

BlueRectangle::~BlueRectangle() {}

void BlueRectangle::calculateXY()
{
	xPosition = 300 + 53 + boardColumn * PIECES_X_DISTANCE;
	yPosition = 539 - (35 - 67 + boardRow * PIECES_Y_DISTANCE);
}

void BlueRectangle::update()
{
	calculateXY();

	sourceRect.h = PIECE_HEIGHT;
	sourceRect.w = PIECE_WIDTH;
	sourceRect.x = 0;
	sourceRect.y = 0;

	destinationRect.x = xPosition;
	destinationRect.y = yPosition;
	destinationRect.w = sourceRect.w;
	destinationRect.h = sourceRect.h;
}

void BlueRectangle::render()
{
	SDL_RenderCopy(renderer, objectTexture, &sourceRect, &destinationRect);
}
#pragma once

class ChessPiece
{
public:
	virtual void CanAttack() = 0;

private:
	virtual bool CanMoveTo() = 0;
};

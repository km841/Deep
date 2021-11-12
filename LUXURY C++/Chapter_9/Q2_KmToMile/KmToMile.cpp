#include "KmToMile.h"

KmToMile::KmToMile(double ratio) : Converter(ratio)
{
}

double KmToMile::convert(double src)
{
	return src / ratio;
}

string KmToMile::getSourceString()
{
	return "Km";
}

string KmToMile::getDestString()
{
	return "Mile";
}

KmToMile::~KmToMile()
{
}

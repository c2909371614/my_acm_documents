#include"Relation.h"
#include "stdafx.h"
string Relation_ship::dom()
{
	return toSetString(noSame(first));
}
string Relation_ship::ran()
{
	
	return toSetString(noSame(second));
}
string Relation_ship::fld()
{
	string ans(first.c_str());
	ans+=second;
	return toSetString(noSame(ans));
}


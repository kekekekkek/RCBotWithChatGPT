#include "Include.h"

int CUtils::IndexOf(string strText, string strValue)
{
	int iIndex = strText.find(strValue);

	if (iIndex >= 0 && iIndex != string::npos)
		return iIndex;

	return -1;
}
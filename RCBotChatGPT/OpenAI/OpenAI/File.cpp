#include "Include.h"

bool CFile::IsFileExists(string strFileName)
{
	WIN32_FIND_DATAA wndFindData;
	HANDLE hFile = FindFirstFileA((strFileName + "*").c_str(), &wndFindData);

	if (hFile != INVALID_HANDLE_VALUE)
	{
		FindClose(hFile);
		return true;
	}

	return false;
}

string CFile::ReadFile(string strFileName)
{
	string strOutput = "";

	if (IsFileExists(strFileName))
	{
		fstream fsStream(strFileName.c_str());

		if (fsStream.is_open())
		{
			while (!fsStream.eof())
			{
				char chBuffer[4096];
				fsStream.getline(chBuffer, sizeof(chBuffer));

				strOutput += chBuffer;
			}

			fsStream.close();
		}
	}

	return strOutput;
}

bool CFile::WriteFile(string strFileName, string strText)
{
	if (IsFileExists(strFileName))
	{
		ofstream osStream(strFileName.c_str());

		if (osStream.is_open())
		{
			osStream << strText;
			osStream.close();

			return true;
		}
	}

	return false;
}
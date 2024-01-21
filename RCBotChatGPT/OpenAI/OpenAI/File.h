#pragma once

class CFile
{
public:
	bool IsFileExists(string strFileName);
	string ReadFile(string strFileName);
	bool WriteFile(string strFileName, string strText);
};
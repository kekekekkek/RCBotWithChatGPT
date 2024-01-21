#pragma once

class COpenAI
{
public:
	void SetModel(string strValue);
	void SetEndPoint(string strValue);
	void SetOpenAIKey(string strValue);
	string ReceiveMessage(string strResult);
	string SendRequest(string strMessage, float fTemperature = 0.7f);

private:
	string strModel = "";
	string strEndPoint = "";
	string strOpenAIKey = "";
};
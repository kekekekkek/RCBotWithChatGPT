#include "Include.h"

void COpenAI::SetModel(string strValue) {
	strModel = strValue;
}

void COpenAI::SetEndPoint(string strValue) {
	strEndPoint = strValue;
}

void COpenAI::SetOpenAIKey(string strValue) {
	strOpenAIKey = strValue;
}

string COpenAI::ReceiveMessage(string strResult)
{
	if (g_Utils.IndexOf(strResult, "Failed") != -1
		|| strResult.empty())
		return strResult;

	if (g_Utils.IndexOf(strResult, "content") == -1)
		strResult = "Failed to extract the message.";
	else
	{
		for (int i = (g_Utils.IndexOf(strResult, "content") + 11); i < strResult.length(); i++)
		{
			if (strResult[i] == 34)
			{
				strResult.erase(0, (g_Utils.IndexOf(strResult, "content") + 11));
				strResult.erase(g_Utils.IndexOf(strResult, "\""), strResult.length());

				break;
			}
		}
	}

	return strResult;
}

string COpenAI::SendRequest(string strMessage, float fTemperature)
{
	string strResult = "";
	HINTERNET hConnect = InternetConnectA(InternetOpenA(NULL, NULL, NULL, NULL, NULL), "api.openai.com", INTERNET_DEFAULT_HTTPS_PORT, NULL, NULL, INTERNET_SERVICE_HTTP, NULL, NULL);

	if (hConnect)
	{
		HINTERNET hRequest = HttpOpenRequestA(hConnect, "POST", strEndPoint.c_str(), NULL, NULL, NULL, (INTERNET_FLAG_KEEP_CONNECTION | INTERNET_FLAG_SECURE), NULL);

		if (hRequest)
		{
			string strSetHeader = ("Content-Type: application/json\r\nAuthorization: Bearer " + strOpenAIKey);
			string strSetData = ("{\"model\": \"" + strModel + "\", \"messages\": [{\"role\": \"user\", \"content\": \"" + strMessage + "\"}], \"temperature\": " + to_string(fTemperature) + "}");

			if (HttpSendRequestA(hRequest, strSetHeader.c_str(), strSetHeader.length(), (void*)strSetData.c_str(), strSetData.length()))
			{
				char chContent[4096];
				DWORD dwBytesRead = NULL;

				if (InternetReadFile(hRequest, chContent, sizeof(chContent), &dwBytesRead))
					strResult = string(chContent);
				else
					strResult = "Failed to read file data!";
			}
			else
				strResult = "Failed to execute request!";

			InternetCloseHandle(hConnect);
			InternetCloseHandle(hRequest);
		}
		else
			strResult = "Failed to open request!";
	}
	else
		strResult = "Failed to connect!";

	return strResult;
}
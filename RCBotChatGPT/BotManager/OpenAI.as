class COpenAI
{
	COpenAI() { };
	COpenAI(string strText, bool bEndLine) { 
		SavePrompt(strText, bEndLine);
	};
	
	string ReadAnswer()
	{
		string strOutput = "";	
		File@ fFile = g_FileSystem.OpenFile("scripts/plugins/store/Prompt.txt", OpenFile::READ);
		
		if (fFile.IsOpen())
		{
			while (!fFile.EOFReached())
			{
				string strCurLine = "";
				fFile.ReadLine(strCurLine);
				
				strOutput += strCurLine;
			}
			
			fFile.Close();
		}
		
		return strOutput;
	}

	int SavePrompt(string strText, bool bEndLine)
	{
		if (strText.IsEmpty())
			return -1;
				
		File@ fFile = g_FileSystem.OpenFile("scripts/plugins/store/Prompt.txt", OpenFile::WRITE);
		
		if (fFile.IsOpen())
		{
			fFile.Write((bEndLine ? (strText + " - {Prompt}\n") : (strText + " - {Prompt}")));
			fFile.Close();
			
			return 1;
		}
		
		return 0;
	}
	
	void WaitAnswer(CBasePlayer@ pPlayer)
	{
		if (pPlayer !is null)
		{
			string strAnswer = ReadAnswer();
			
			if (!strAnswer.IsEmpty())
			{		
				if (strAnswer.Find(" - {Answer}") != String::INVALID_INDEX)
				{
					strAnswer = strAnswer.Replace(" - {Answer}", "");
					PlayerSay(pPlayer, strAnswer);
				
					g_FileSystem.RemoveFile("scripts/plugins/store/Prompt.txt");
					g_Scheduler.RemoveTimer(g_Scheduler.GetCurrentFunction());
					
					@pPlayer = null;
				}
			}
		}
	}
	
	void PlayerSay(CBaseEntity@ pEntity, string strMsg)
	{
		NetworkMessage NetMsg(MSG_ALL, NetworkMessages::NetworkMessageType(74));
		
		NetMsg.WriteByte(pEntity.entindex());
		NetMsg.WriteByte(2);
		NetMsg.WriteString("" + pEntity.pev.netname + ": " + strMsg + "\n");
		
		NetMsg.End();
	}
	
	string strSaveText = "";
	CBasePlayer@ pSavePlayer = null;
}
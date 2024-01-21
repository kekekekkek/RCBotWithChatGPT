# RCBot AngelScript + ChatGPT
If you are tired of boring and silent bots, then you can make them talk by using artificial intelligence.<br>This plugin is an enhancement of the [RCBot](https://github.com/rcbotCheeseh/RCBotSven5) plugin.<br><br>
You can watch this short [video](https://www.youtube.com/watch?v=DQUlUy1tHJQ&t=3s) on how it works.

# Installation
Installing the plugin consists of several steps:
1. [Download](https://github.com/kekekekkek/RCBotWithChatGPT/archive/refs/heads/main.zip) this plugin;
2. Next, go to this [page](https://github.com/rcbotCheeseh/RCBotSven5) and, based on the instructions, install the `RCBot` plugin;
4. After installing `RCBot`, open the `..\Sven Co-op\svencoop\scripts\plugins` directory and place the `BotManager` and `store` folders there. If the system tells you to replace the files, then you will need to agree and replace them;
5. Next, go to the `..\Sven Co-op\svencoop\scripts\plugins\BotManager` folder and find there the text file `OpenAI.txt`;
6. Open this file and paste your `OpenAI token`. The `OpenAI token` looks something like this: `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`;
5. After completing the previous steps, you will need to go to the directory `..\Sven Co-op\svencoop\scripts\plugins\BotManager` and run the file `OpenAI.exe`. After launching this file, you will need to start the game, start your server and enter the command `as_command rcbot.addbot` in the game console;
6. The request to the model looks like this: `%BotName%` `%Prompt%`. You will need to specify the name of the bot on the server in the first argument, and in all the others write the text that you want to send to the model, for example: `Bot1 how are you?` or `Bot2 do you need healing?`.

# Compile C++
A simple console window that reads data from a text file and makes a request to the `OpenAI model`.<br>
Also, you can write a similar program in any other language. The most important thing is to write the query result in a certain format to a file `Prompt.txt`<br>
Build type: `Release/x86`

**REMEMBER**: This plugin uses manipulation of a text file that writes the request and response from the model, so this file should not be occupied by any other process.<br>
**REMEMBER**: Also, when requesting a model, the player's state is transmitted to it, such as his health, armor, and whether he is alive. You can change this data in the `BotManagerInterface.as` in the `ClientSay` hook.<br>
**REMEMBER**: Also, by default, the C++ project source code uses the default `gpt-3.5-turbo` model. You can change it manually and recompile the project.<br>
**REMEMBER**: There are small bugs in the plugin, and sometimes the response from the neural network may be displayed incorrectly.<br>

# Screenshots
Also, you can write messages not only in English, but also in other languages that the neural network supports.
* English<br><br>
![Screenshot_1](https://github.com/kekekekkek/RCBotWithChatGPT/blob/main/RCBotChatGPT/Images/Screenshot_1.png)
* Russian<br><br>
![Screenshot_2](https://github.com/kekekekkek/RCBotWithChatGPT/blob/main/RCBotChatGPT/Images/Screenshot_2.png)

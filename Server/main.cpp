#include "Chat.h"

int main()
{
	
	std::string login;
	char operation_menu;
	std::string str;
	Chat chat;
	
	Network netConnect;
	auto connectNet = netConnect.connectServerOpen();
	std::cout << "Соединение... "  << std::endl;
	if (connectNet == -1)
	{
		std::cout << "Сбой сети." << std::endl;
		exit(-1);
	}

	chat.connectMySQL();
	
	do
	{
		str = netConnect.reseiveMessage(connectNet);
		
		if(strncmp("1", str.c_str(), 1) == 0) 
		{
			operation_menu = '1';
		}	
		if(strncmp("2", str.c_str(), 1) == 0) 
		{
			operation_menu = '2';
		}	
		if(strncmp("3", str.c_str(), 1) == 0) 
		{
			operation_menu = '3';
		}		
		
		if (operation_menu == '1')
		{
			login = chat.registration(connectNet);
			
			if (login != "error")
			{
				chat.showMessageMenu(connectNet, login);
			}
		}
		if (operation_menu == '2')
		{
			auto loginIn = chat.signUp(connectNet);
			
			if (loginIn != "error")
			{
				chat.showMessageMenu(connectNet, loginIn);
			}
		}
	} while (operation_menu != '3');
	
	chat.disconnectMySQL();
	netConnect.connectClose(connectNet);

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "admin.h"
#include "menuc.h"
#include "tool.h"
#include "struct.h"
#include "supermanager.h"
#include "manager.h"



int main()
{
	ss=time(NULL)+3600*8;
	list_m = create_list();
	list_s = create_list();
	init();
	
	while(1)
	{
		major_menu();
		switch(get_cmd('0','2'))
		{
			case '1': super_admin();break;
			case '2': manager_admin();break;
			case '0': quit();return 0;
		}
	}
}






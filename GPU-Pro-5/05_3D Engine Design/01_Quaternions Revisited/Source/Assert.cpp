/****************************************************************************

  GPU Pro 5 : Quaternions revisited - sample code
  All sample code written from scratch by Sergey Makeev specially for article.

  Copyright (c) 2013, Sergey Makeev

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software.

  2. If you use this software in a non-commercial product, an acknowledgment
     in the product documentation would be appreciated but is not required.

  3. If you use this software in a commercial product you requried to credit
     the author.

  4. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.

  5. This notice may not be removed or altered from any source distribution.
    

   Please let me know if you use the code in your products or have any questions or suggestions.

   e-mail: sergeymakeev@inbox.ru
   http://linkedin.com/in/sergeymakeev/

****************************************************************************/
#include <windows.h>
#include "Assert.h"
#include "Utils.h"

void AssertionFailed(const char* expression, const char* message, const char* file, int line)
{
	int result = MessageBoxA(NULL,
		                     Utils::StringFormat(
		                     "File : %s\n" 
		                     "Line : %d\n\n"
		                     "Expression : %s\n\n"
		                     "Message : %s\n\n\n"
		                     "Press 'Abort' to abort the application\n"
		                     "Press 'Retry' to debug the application\n"
		                     "Press 'Ignore' to continue the application\n", file, line, expression, message), "Assertion failed", MB_ABORTRETRYIGNORE | MB_ICONERROR | MB_DEFBUTTON2);
	if (result == IDRETRY)
	{
		DebugBreak();
	} else
	{
		if (result == IDABORT)
		{
			exit(0);
		}
	}
}


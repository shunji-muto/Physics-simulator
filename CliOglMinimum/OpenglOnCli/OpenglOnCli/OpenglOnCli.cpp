#include "stdafx.h"
#include "MainForm.h"

#include <iostream>

using namespace System;
using namespace OpenglOnCli;











[STAThreadAttribute]
int main()
{
  std::cout << "hello, world\n"; 
  MainForm::GetInst()->ShowDialog();
  return 0;
}





<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: TaskList - Win32 (WCE x86) Debug--------------------
</h3>
<h3>Command Lines</h3>
Creating temporary file "C:\DOCUME~1\ADMINI~1\LOCALS~1\Temp\RSP90.tmp" with contents
[
/nologo /W3 /Zi /Od /D "DEBUG" /D "_i386_" /D UNDER_CE=300 /D _WIN32_WCE=300 /D "WIN32_PLATFORM_PSPC=310" /D "UNICODE" /D "_UNICODE" /D "_X86_" /D "x86" /D "_WIN32_WCE_CEPC" /D "_AFXDLL" /FR"X86Dbg/" /Fp"X86Dbg/TaskList.pch" /Yu"stdafx.h" /Fo"X86Dbg/" /Fd"X86Dbg/" /Gs8192 /GF /c 
"D:\工作项目\EVC编程入门及项目开发\例子程序\5\TaskList\TaskListDlg.cpp"
]
Creating command line "cl.exe @C:\DOCUME~1\ADMINI~1\LOCALS~1\Temp\RSP90.tmp" 
Creating temporary file "C:\DOCUME~1\ADMINI~1\LOCALS~1\Temp\RSP91.tmp" with contents
[
toolhelp.lib /nologo /base:"0x00010000" /stack:0x10000,0x1000 /entry:"wWinMainCRTStartup" /incremental:yes /pdb:"X86Dbg/TaskList.pdb" /debug /out:"X86Dbg/TaskList.exe" /subsystem:windowsce,3.00 /MACHINE:IX86 
".\X86Dbg\StdAfx.obj"
".\X86Dbg\TaskList.obj"
".\X86Dbg\TaskListDlg.obj"
".\X86Dbg\TaskList.res"
]
Creating command line "link.exe @C:\DOCUME~1\ADMINI~1\LOCALS~1\Temp\RSP91.tmp"
<h3>Output Window</h3>
Compiling...
TaskListDlg.cpp
D:\工作项目\EVC编程入门及项目开发\例子程序\5\TaskList\TaskListDlg.cpp(64) : warning C4244: 'argument' : conversion from 'double' to 'int', possible loss of data
D:\工作项目\EVC编程入门及项目开发\例子程序\5\TaskList\TaskListDlg.cpp(65) : warning C4244: 'argument' : conversion from 'double' to 'int', possible loss of data
D:\工作项目\EVC编程入门及项目开发\例子程序\5\TaskList\TaskListDlg.cpp(66) : warning C4244: 'argument' : conversion from 'double' to 'int', possible loss of data
D:\工作项目\EVC编程入门及项目开发\例子程序\5\TaskList\TaskListDlg.cpp(273) : warning C4018: '<' : signed/unsigned mismatch
Linking...
Creating command line "bscmake.exe /nologo /o"X86Dbg/TaskList.bsc"  ".\X86Dbg\StdAfx.sbr" ".\X86Dbg\TaskList.sbr" ".\X86Dbg\TaskListDlg.sbr""
Creating browse info file...
<h3>Output Window</h3>



<h3>Results</h3>
TaskList.exe - 0 error(s), 4 warning(s)
</pre>
</body>
</html>

<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: CECLOCK - Win32 (WCE x86) Release--------------------
</h3>
<h3>Command Lines</h3>
Creating temporary file "C:\DOCUME~1\wb\LOCALS~1\Temp\RSP2A.tmp" with contents
[
/nologo /W3 /D "_i386_" /D UNDER_CE=300 /D _WIN32_WCE=300 /D "WIN32_PLATFORM_PSPC=310" /D "UNICODE" /D "_UNICODE" /D "_X86_" /D "x86" /D "NDEBUG" /D "_WIN32_WCE_CEPC" /D "_AFXDLL" /D "_AFXEXT" /FR"X86Rel/" /Fp"X86Rel/CECLOCK.pch" /Yu"stdafx.h" /Fo"X86Rel/" /Gs8192 /GF /Oxs /c 
"E:\工作项目\EVC编程入门及项目开发\例子程序\8\CECLOCK\CECLOCK.cpp"
"E:\工作项目\EVC编程入门及项目开发\例子程序\8\CECLOCK\ClockST.cpp"
]
Creating command line "cl.exe @C:\DOCUME~1\wb\LOCALS~1\Temp\RSP2A.tmp" 
Creating temporary file "C:\DOCUME~1\wb\LOCALS~1\Temp\RSP2B.tmp" with contents
[
/nologo /W3 /D "_i386_" /D UNDER_CE=300 /D _WIN32_WCE=300 /D "WIN32_PLATFORM_PSPC=310" /D "UNICODE" /D "_UNICODE" /D "_X86_" /D "x86" /D "NDEBUG" /D "_WIN32_WCE_CEPC" /D "_AFXDLL" /D "_AFXEXT" /FR"X86Rel/" /Fp"X86Rel/CECLOCK.pch" /Yc"stdafx.h" /Fo"X86Rel/" /Gs8192 /GF /Oxs /c 
"E:\工作项目\EVC编程入门及项目开发\例子程序\8\CECLOCK\StdAfx.cpp"
]
Creating command line "cl.exe @C:\DOCUME~1\wb\LOCALS~1\Temp\RSP2B.tmp" 
<h3>Output Window</h3>
Compiling...
StdAfx.cpp
Compiling...
CECLOCK.cpp
ClockST.cpp
E:\工作项目\EVC编程入门及项目开发\例子程序\8\CECLOCK\ClockST.cpp(65) : warning C4244: '=' : conversion from 'double' to 'long', possible loss of data
E:\工作项目\EVC编程入门及项目开发\例子程序\8\CECLOCK\ClockST.cpp(66) : warning C4244: '=' : conversion from 'double' to 'long', possible loss of data
E:\工作项目\EVC编程入门及项目开发\例子程序\8\CECLOCK\ClockST.cpp(68) : warning C4244: '=' : conversion from 'double' to 'long', possible loss of data
E:\工作项目\EVC编程入门及项目开发\例子程序\8\CECLOCK\ClockST.cpp(69) : warning C4244: '=' : conversion from 'double' to 'long', possible loss of data
E:\工作项目\EVC编程入门及项目开发\例子程序\8\CECLOCK\ClockST.cpp(46) : warning C4101: 'pOldBrush' : unreferenced local variable
E:\工作项目\EVC编程入门及项目开发\例子程序\8\CECLOCK\ClockST.cpp(121) : warning C4244: '=' : conversion from 'double' to 'long', possible loss of data
E:\工作项目\EVC编程入门及项目开发\例子程序\8\CECLOCK\ClockST.cpp(122) : warning C4244: '=' : conversion from 'double' to 'long', possible loss of data
E:\工作项目\EVC编程入门及项目开发\例子程序\8\CECLOCK\ClockST.cpp(153) : warning C4244: '=' : conversion from 'double' to 'long', possible loss of data
E:\工作项目\EVC编程入门及项目开发\例子程序\8\CECLOCK\ClockST.cpp(154) : warning C4244: '=' : conversion from 'double' to 'long', possible loss of data
E:\工作项目\EVC编程入门及项目开发\例子程序\8\CECLOCK\ClockST.cpp(185) : warning C4244: '=' : conversion from 'double' to 'long', possible loss of data
E:\工作项目\EVC编程入门及项目开发\例子程序\8\CECLOCK\ClockST.cpp(186) : warning C4244: '=' : conversion from 'double' to 'long', possible loss of data
Generating Code...
Creating temporary file "C:\DOCUME~1\wb\LOCALS~1\Temp\RSP2C.tmp" with contents
[
/nologo /base:"0x00100000" /stack:0x10000,0x1000 /entry:"_DllMainCRTStartup" /dll /incremental:no /pdb:"X86Rel/CECLOCK.pdb" /def:".\CECLOCK.def" /out:"X86Rel/CECLOCK.dll" /implib:"X86Rel/CECLOCK.lib" /subsystem:windowsce,3.00 /MACHINE:IX86 
".\X86Rel\CECLOCK.obj"
".\X86Rel\ClockST.obj"
".\X86Rel\StdAfx.obj"
".\X86Rel\CECLOCK.res"
]
Creating command line "link.exe @C:\DOCUME~1\wb\LOCALS~1\Temp\RSP2C.tmp"
<h3>Output Window</h3>
Linking...
   Creating library X86Rel/CECLOCK.lib and object X86Rel/CECLOCK.exp
Creating command line "bscmake.exe /nologo /o"X86Rel/CECLOCK.bsc"  ".\X86Rel\StdAfx.sbr" ".\X86Rel\CECLOCK.sbr" ".\X86Rel\ClockST.sbr""
Creating browse info file...
<h3>Output Window</h3>




<h3>Results</h3>
CECLOCK.dll - 0 error(s), 11 warning(s)
</pre>
</body>
</html>

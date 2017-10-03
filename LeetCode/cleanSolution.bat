FOR /F "tokens=*" %%G IN ('DIR /B /AD /S *x64*') DO RMDIR /S /Q %%G
FOR /F "tokens=*" %%G IN ('DIR /B /AD /S *debug*') DO RMDIR /S /Q %%G
FOR /F "tokens=*" %%G IN ('DIR /B /AD /S *release*') DO RMDIR /S /Q %%G
FOR /F "tokens=*" %%G IN ('DIR /B /S *.ncb*') DO DEL %%G
FOR /F "tokens=*" %%G IN ('DIR /B /S *.sdf*') DO DEL %%G
FOR /F "tokens=*" %%G IN ('DIR /B /S *.db*') DO DEL %%G

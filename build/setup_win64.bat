@echo off


mkdir %1-win64
cd %1-win64
cmake -G "Visual Studio 15 2017 Win64" ../../src/ga1-core
cd ..
goto end



:end

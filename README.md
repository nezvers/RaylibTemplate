# Raylib Template with CMake
Prepared for Windows and Linux.    
Works with VS Code and Visual Studio.    

Set project name in `CMakeLists.txt` and if using VS Code, int `.vscode/settings.json`    

For compiling HTML5 use `build_web` scripts, requires emscriptem to be set in your operating system's PATH.    
To run HTML5 localy you need to use some kind of server from `build-emc` directory:    
- `python -m http.server -d ./build-emc -b 127.0.0.1` and open `http://localhost:8000/RaylibTemplate.html`    
More info on [Raylib wiki](https://github.com/raysan5/raylib/wiki/Working-for-Web-(HTML5)#6-test-raylib-game-on-web)
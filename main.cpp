#include <SDL3/SDL.h>
#include <iostream>

//Globals
int gScreenHeight = 480;
int gScreenWidth  = 640;
SDL_Window* gGraphicsApplicationWindow = nullptr;
SDL_GLContext gOpenGLContext = nullptr;

bool gQuit = false; // if true we quit

using namespace std;

void InitializeProgram(){
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        cout << "SDL3 coudnt initialize video subsystem\n";
        exit(1);
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    gGraphicsApplicationWindow = SDL_CreateWindow("OpenGl Window", gScreenWidth, gScreenHeight, SDL_WINDOW_OPENGL);

    if(gGraphicsApplicationWindow==nullptr){
        cout << "SDL_Window was not able to run\n";
        exit(1);
    }

    gOpenGLContext = SDL_GL_CreateContext(gGraphicsApplicationWindow);

    if(gOpenGLContext == nullptr){
        cout << "gOpenGlContext not Available\n";
        exit(1);
    }
};
void Input(){
    SDL_Event e;
    while(SDL_PollEvent(&e) !=0)
    if(e.type == SDL_EVENT_QUIT){
        cout << "Good bye!";
        gQuit = true;
    }
};

void PreDraw(){

};

void Draw(){

};

void MainLoop(){
    while(!gQuit){
        Input();

        PreDraw();
        
        Draw();
        //update the screen
        SDL_GL_SwapWindow(gGraphicsApplicationWindow);

    }
};
void CleanUp(){
    SDL_DestroyWindow(gGraphicsApplicationWindow);
    SDL_Quit();
};
int main(){
    InitializeProgram();

    MainLoop();

    CleanUp();

    return 0;
}
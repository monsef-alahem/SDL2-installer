/*************************************
 *  AUTHOR  :   alahem monsef
 *  EMAIL   :   m.alahem09@gmail.com
 *  VERSION :   __
 *  DATE    :   1-feb-2019
 *
 *************************************/


//utiliser sdl2
#include <SDL2/SDL.h>

//ouvrir des images a part bmp avec sdl2
#include <SDL2/SDL_image.h>

//lire sons et musiques avec sdl2
#include <SDL2/SDL_mixer.h>

//afficher du text avec sdl2
#include <SDL2/SDL_ttf.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

    //variables globales
    SDL_Window* window;
    SDL_Renderer* renderer;
    Mix_Chunk *wave;
    Mix_Music *music;
    TTF_Font* font;
    int font_size = 20;
    int diag_idx = 0;
    SDL_Event event;

//boite de dialogue dynamique pseudo-tapé
#include "ui.h"


int main( int argc, char* args[] )
{


    //demmarer sdl2
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO);

    //initialiser l'affichage du texte et choix police
    TTF_Init();
    font = TTF_OpenFont("arial.ttf", font_size);

    //initiliser audio
    Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );

    //contruire une fenêtre
    window = SDL_CreateWindow( "SDL2 template", 500, 300, 640, 480, 0 );
    //flag = SDL_WINDOW_FULLSCREEN for full screen
    Uint32 flag = 0;
    SDL_SetWindowFullscreen(window, flag);

    //création de l'ecran de dessin dans la fenêtre
    renderer = SDL_CreateRenderer( window, -1, 0 );
    SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );

    //ouvrir un fichier son et musique
    wave = Mix_LoadWAV("CSI_Open.wav");
    music = Mix_LoadMUS("under_moon.ogg");

    //jouer son et musique
    Mix_PlayMusic( music, -1);
    Mix_PlayChannel(-1, wave, 0);

    //création du sprit a dessinner sur l'ecran
    SDL_Surface *s_ply = IMG_Load("shadow_ui.png");
    SDL_Texture *t_ply= SDL_CreateTextureFromSurface(renderer, s_ply);
    SDL_Rect rs_ply = {0,0,97,85};
    SDL_Rect rd_ply = {0,0,97,85};

    //création du dialogue auto-tapant
    init_dialog();

    int loop = 1;

    while ( loop )
    {
        //efface l'ecran de dessin avec le noir (r,v,b,a) a = alpha la transparence
        SDL_SetRenderDrawColor( renderer,0,0,0,255);
        SDL_RenderClear( renderer );

        //entrée de clavier
        while ( SDL_PollEvent( &event ) ) {
            if ( event.type == SDL_QUIT ) {                
                    loop = 0;
            } 
            else if ( event.type == SDL_KEYDOWN ) {
                switch ( event.key.keysym.sym )
                {
                //devinez !
                case SDLK_RIGHT:
                    rd_ply.x+=15;
                    break;
                case SDLK_LEFT:
                    rd_ply.x-=15;
                    break;
                case SDLK_DOWN:
                    rd_ply.y+=15;
                    break;
                case SDLK_UP:
                    rd_ply.y-=15;
                    break;
                case SDLK_SPACE:
                    break;
                case SDLK_ESCAPE:
                    loop = 0;
                    break;
                case SDLK_c:
                    if (diag_idx < 3)
                        diag_idx++;
                    break;
                case SDLK_p:
                        wave = Mix_LoadWAV("frappe.wav");
                        Mix_PlayChannel(-1, wave, 0);
                    break;
                default :
                    break;
                }
            }
        }

        //ajoute des mots dans chaque boucle
        update_dialog();
        //redessine la boite de dialogue
        draw_dialog();

        //dessine le sprit
        SDL_RenderCopy(renderer, t_ply, &rs_ply, &rd_ply);

        //affiche l'ecran de dessin sur la fenetre
        SDL_RenderPresent( renderer);

        //pause de 16 millisecondes avant de recommencer la boucle "while"
        SDL_Delay( 16 );
    }

    //quand on quitte le programme (la boucle while) on detruit ce qu'on a crée
    //pour éviter les fuites de mémoire sur l'ordinateur
    SDL_FreeSurface(s_ply);
    SDL_DestroyTexture(t_ply);
    Mix_FreeChunk(wave);
    Mix_FreeMusic(music);
    Mix_CloseAudio();
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();

}
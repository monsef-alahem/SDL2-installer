/*************************************
 *  taped dialog box
 *  AUTHOR  :   alahem monsef
 *  EMAIL   :   m.alahem09@gmail.com
 *  VERSION :   __
 *  DATE    :   1-feb-2019
 *  
 *  
 *
 *************************************/

struct label
{
    int col_r;
    int col_g;
    int col_b;
    int col_a;
    SDL_Rect r;
    SDL_Surface* sm;
    SDL_Texture* m;
    char text[1000];
};

typedef struct label label;

//place to declare struct


label dial_box0 = {
    0,0,0,0,
    {30,440-90,370,190},
    NULL,NULL,"",
    };
label dial_box1 = {
    0,0,0,0,
    {30,440-60,370,190},
    NULL,NULL,"",
    };
label dial_box2 = {
    0,0,0,0,
    {30,440-30,370,190},
    NULL,NULL,"",
    };

SDL_Rect r1 = {20,340,600,120};
SDL_Rect txt_cursor = {8,20,10,20};

//texts of game
char test_text[250] = "felicitations ! SDL2 et ses extensions ont ete installes avec succes. appuie sur c pour continuer";
char test_text1[250] = "controle le sprit avec les fleches du clavier, appuie sur p pour frapper.";
char test_text2[250] = "appuie sur echap pour sortir de la demo.";
char test_text3[250] = "bla bla bla bla bla tu vas sortir a la fin >:( .";
char *diag_ptr[4] = {test_text,test_text1,test_text2,test_text3};

//place for contruct list

const int tot_btn = 2;
label *dial_box[3] = {&dial_box0,&dial_box1,&dial_box2};
SDL_Color text_color = {255, 255, 255};


void init_dialog()
{

    int i = 0;
    for (;i<3;i++) {
        dial_box[i]->sm = TTF_RenderText_Solid(font, dial_box[i]->text, text_color);
        dial_box[i]->m = SDL_CreateTextureFromSurface(renderer, dial_box[i]->sm);
    }

}

void init_ui()
{
    init_dialog();
}

void update_dialog()
{

    //line_idx
    //char_idx

    static int line_idx,char_idx = 0;
    static int mk_empty = 0;
    static int prev_diag_idx = 0;


    //clean old dialogue if next dialogue trigered
    if (prev_diag_idx != diag_idx)
    {
        line_idx = char_idx = 0;
        memset(dial_box[0]->text,0,50);
        memset(dial_box[1]->text,0,50);
        memset(dial_box[2]->text,0,50);
        prev_diag_idx = diag_idx;
    }

    dial_box[line_idx]->text[char_idx-line_idx*50] = *(diag_ptr[diag_idx]+char_idx);
    //printf("%d\n", strlen(tb_idx[idt]));
    if (char_idx < strlen(diag_ptr[diag_idx]) && line_idx < 3 ){
        char_idx++;
        Mix_PlayChannel(1, wave, 0);
        if (char_idx == 50 || char_idx == 100) {
            line_idx++;
        }
    }

    
    
    int i,w,h = 0;


    for (i = 0;i<3;i++) {
        SDL_Color text_color = {0, 255, 240};
        dial_box[i]->sm = TTF_RenderText_Solid(font, dial_box[i]->text, text_color);
        dial_box[i]->m = SDL_CreateTextureFromSurface(renderer, dial_box[i]->sm);
        SDL_QueryTexture(dial_box[i]->m, NULL, NULL, &w, &h);
        dial_box[i]->r.w = w;
        dial_box[i]->r.h = h;
    }

    txt_cursor.x = 30 + 10 + w;
    txt_cursor.y = 350 + line_idx*30;

}


void update_ui()
{
    update_dialog();
}

void draw_dialog()
{

    SDL_Rect re = {20-5,340-5,600+10,120+10};
    SDL_SetRenderDrawColor( renderer,0,255,100,255); 
    SDL_RenderFillRect( renderer, &re);
    
    SDL_Rect r = {20,340,600,120};
    SDL_SetRenderDrawColor( renderer,0,0,0,255); 
    SDL_RenderFillRect( renderer, &r);


    int i = 0;
    for (;i<3;i++) {        
        SDL_SetRenderDrawColor( renderer, dial_box[i]->col_r, dial_box[i]->col_g, dial_box[i]->col_b, dial_box[i]->col_a ); 
        //SDL_RenderFillRect( renderer, &dial_box[i]->r);
        SDL_RenderCopy(renderer, dial_box[i]->m, NULL, (&dial_box[i]->r));
    }

    if (SDL_GetTicks()/500 % 2 == 0) {
        SDL_SetRenderDrawColor( renderer,0,255,100,255); 
        SDL_RenderFillRect( renderer, &txt_cursor);
    }

}


void draw_ui()
{
    draw_dialog();
}
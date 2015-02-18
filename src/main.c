#include "SDL2/SDL.h"

#include "list.h"

int main(int argc, char* argv[])
{
        SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

        SDL_Quit();

        // LIST TEST, RUN THIS TO MAKE SURE LIST FUNCTIONS PROPERLY!
        struct list* list = list_create(10, sizeof(int));

        printf("max: %d\n", list->max);
        printf("size: %d\n", list->size);

        for (int i = 0; i < 20; i++)
                list_push(list, &i);

        printf("max: %d\n", list->max);
        printf("size: %d\n", list->size);

        int a = 123321;
        int b;
        list_set(list, 17, &a);
        list_get(list, 17, &b);

        printf("10 element: %d\n", b);

        for (int i = 0; i < 16; i++){
                int a;
                list_pop(list, &a);
                printf("%d\n", a);
        }

        return 0;
}
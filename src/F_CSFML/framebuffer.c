/*
** EPITECH PROJECT, 2020
** frammebuffer
** File description:
** frammebuffer
*/

#include "my_rpg.h"

sfUint8 *create_framebuffer(int w, int h, unsigned char const px[4])
{
    unsigned int len = h * w * 4;
    sfUint8 *fb = (sfUint8 *)malloc(len);

    if (!fb) return (NULL);
    for (unsigned int i = 0; i < len; i += 4) {
        fb[i] = px[0];
        fb[i + 1] = px[1];
        fb[i + 2] = px[2];
        fb[i + 3] = px[3];
    }
    return (fb);
}

void replace_framebuffer(sfUint8 **fb, unsigned char const px[4], u_int32_t len)
{
    for (unsigned int i = 0; i < len; i += 4) {
        (*fb)[i] = px[0];
        (*fb)[i + 1] = px[1];
        (*fb)[i + 2] = px[2];
        (*fb)[i + 3] = px[3];
    }
}

void clear_fb(sfUint8 **fb, unsigned char const px[4], u_int32_t len)
{
    for (unsigned int y = 0; y < len; y += 4) {
        (*fb)[y] = px[0];
        (*fb)[y + 1] = px[1];
        (*fb)[y + 2] = px[2];
        (*fb)[y + 3] = px[3];
    }
}

void change_fb(sfUint8 **fb, unsigned char const px[4], u_int32_t len)
{
    for (unsigned int i = 0; i < len; i += 4) {
        (*fb)[i] += px[0];
        (*fb)[i + 1] += px[1];
        (*fb)[i + 2] += px[2];
        (*fb)[i + 3] += px[3];
    }
}

void my_ppl(sfUint8 **fb, sfVector2f *a, window_t *win, unsigned char const px[4])
{
    int y = a->y;
    int x = a->x;

    if (y <= win->resolution.y && y >= 0 && x >= 0 && x <= win->resolution.x) {
        (*fb)[(y * win->resolution.x + x) * 4] = px[0];
        (*fb)[(y * win->resolution.x + x) * 4 + 1] = px[1];
        (*fb)[(y * win->resolution.x + x) * 4 + 2] = px[2];
        (*fb)[(y * win->resolution.x + x) * 4 + 3] = px[3];
    }
}

void my_pc(sfUint8 **fb, sfVector2f a, window_t *win, unsigned char const px[4])
{
    sfVector2f p = a;
    float y = 0;

    for (y = 0; y <= 360; y += 0.01) {
        p.x = a.x + cos(y) * win->radius;
        p.y = a.y + sin(y) * win->radius;
        my_ppl(fb, &p, win, px);
    }
}

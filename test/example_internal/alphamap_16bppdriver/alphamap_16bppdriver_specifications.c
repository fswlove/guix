/*******************************************************************************/
/*  This file is auto-generated by Azure RTOS GUIX Studio. Do not edit this    */
/*  file by hand. Modifications to this file should only be made by running    */
/*  the Azure RTOS GUIX Studio application and re-generating the application   */
/*  specification file(s). For more information please refer to the Azure RTOS */
/*  GUIX Studio User Guide, or visit our web site at azure.com/rtos            */
/*                                                                             */
/*  GUIX Studio Revision 6.2.0.1                                               */
/*  Date (dd.mm.yyyy): 31.10.2022   Time (hh:mm): 14:08                        */
/*******************************************************************************/


#define GUIX_STUDIO_GENERATED_FILE
#include <stddef.h>
#include "alphamap_16bppdriver_resources.h"
#include "alphamap_16bppdriver_specifications.h"

static GX_WIDGET *gx_studio_nested_widget_create(GX_BYTE *control, GX_CONST GX_STUDIO_WIDGET *definition, GX_WIDGET *parent);
WINDOW_CONTROL_BLOCK window;
GX_DISPLAY display_1_control_block;
GX_WINDOW_ROOT display_1_root_window;
GX_CANVAS  display_1_canvas_control_block;
ULONG      display_1_canvas_memory[153600];

extern GX_CONST GX_THEME *display_1_theme_table[];
extern GX_CONST GX_STRING *display_1_language_table[];

GX_STUDIO_DISPLAY_INFO alphamap_16bppdriver_display_table[1] =
{
    {
    "display_1",
    "display_1_canvas",
    display_1_theme_table,
    display_1_language_table,
    DISPLAY_1_THEME_TABLE_SIZE,
    DISPLAY_1_LANGUAGE_TABLE_SIZE,
    DISPLAY_1_STRING_TABLE_SIZE,
    640,                                     /* x resolution                   */
    480,                                     /* y resolution                   */
    &display_1_control_block,
    &display_1_canvas_control_block,
    &display_1_root_window,
    display_1_canvas_memory,                 /* canvas memory area             */
    614400,                                  /* canvas memory size in bytes    */
    0                                        /* rotation angle                 */
    }
};


UINT gx_studio_icon_button_create(GX_CONST GX_STUDIO_WIDGET *info, GX_WIDGET *control_block, GX_WIDGET *parent)
{
    UINT status;
    GX_ICON_BUTTON *button = (GX_ICON_BUTTON *) control_block;
    GX_ICON_BUTTON_PROPERTIES *props = (GX_ICON_BUTTON_PROPERTIES *) info->properties;
    status = gx_icon_button_create(button, info->widget_name, parent, props->pixelmap_id, info->style, info->widget_id, &info->size);
    return status;
}

UINT gx_studio_pixelmap_button_create(GX_CONST GX_STUDIO_WIDGET *info, GX_WIDGET *control_block, GX_WIDGET *parent)
{
    UINT status;
    GX_PIXELMAP_BUTTON *button = (GX_PIXELMAP_BUTTON *) control_block;
    GX_PIXELMAP_BUTTON_PROPERTIES *props = (GX_PIXELMAP_BUTTON_PROPERTIES *) info->properties;
    status = gx_pixelmap_button_create(button, info->widget_name, parent,
               props->normal_pixelmap_id,
               props->selected_pixelmap_id,
               props->disabled_pixelmap_id,
               info->style, info->widget_id, &info->size);
    return status;
}

UINT gx_studio_icon_create(GX_CONST GX_STUDIO_WIDGET *info, GX_WIDGET *control_block, GX_WIDGET *parent)
{
    UINT status;
    GX_ICON *icon = (GX_ICON *) control_block;
    GX_ICON_PROPERTIES *props = (GX_ICON_PROPERTIES *) info->properties;
    status = gx_icon_create(icon, info->widget_name, parent, props->normal_pixelmap_id, info->style, info->widget_id, info->size.gx_rectangle_left, info->size.gx_rectangle_top);
    if (props->selected_pixelmap_id)
    {
        gx_icon_pixelmap_set(icon, props->normal_pixelmap_id, props->selected_pixelmap_id);
    }
    else
    {
        gx_widget_resize((GX_WIDGET *)icon, (GX_RECTANGLE *)&info->size);
    }
    return status;
}

UINT gx_studio_pixelmap_slider_create(GX_CONST GX_STUDIO_WIDGET *info, GX_WIDGET *control_block, GX_WIDGET *parent)
{
    UINT status;
    GX_PIXELMAP_SLIDER *slider = (GX_PIXELMAP_SLIDER *) control_block;
    GX_PIXELMAP_SLIDER_PROPERTIES *props = (GX_PIXELMAP_SLIDER_PROPERTIES *) info->properties;
    GX_PIXELMAP_SLIDER_INFO pixelmap_info;
    GX_SLIDER_INFO slider_info;
    slider_info.gx_slider_info_min_val = props->min_val;
    slider_info.gx_slider_info_max_val = props->max_val;
    slider_info.gx_slider_info_current_val = props->current_val;
    slider_info.gx_slider_info_increment = props->increment;
    slider_info.gx_slider_info_min_travel = props->min_travel;
    slider_info.gx_slider_info_max_travel = props->max_travel;
    slider_info.gx_slider_info_needle_width = props->needle_width;
    slider_info.gx_slider_info_needle_height = props->needle_height;
    slider_info.gx_slider_info_needle_inset = props->needle_inset;
    slider_info.gx_slider_info_needle_hotspot_offset = props->needle_hotspot;
    pixelmap_info.gx_pixelmap_slider_info_lower_background_pixelmap = props->lower_pixelmap;
    pixelmap_info.gx_pixelmap_slider_info_upper_background_pixelmap = props->upper_pixelmap;
    pixelmap_info.gx_pixelmap_slider_info_needle_pixelmap = props->needle_pixelmap;
    status = gx_pixelmap_slider_create(slider,
                    info->widget_name,
                    parent,
                    &slider_info,
                    &pixelmap_info,
                    info->style,
                    info->widget_id,
                    &info->size);
    return status;
}

UINT gx_studio_prompt_create(GX_CONST GX_STUDIO_WIDGET *info, GX_WIDGET *control_block, GX_WIDGET *parent)
{
    UINT status;
    GX_PROMPT *prompt = (GX_PROMPT *) control_block;
    GX_PROMPT_PROPERTIES *props = (GX_PROMPT_PROPERTIES *) info->properties;
    status = gx_prompt_create(prompt, info->widget_name, parent, props->string_id, info->style, info->widget_id, &info->size);
    if (status == GX_SUCCESS)
    {
        gx_prompt_font_set(prompt, props->font_id);
#if defined(GUIX_5_4_0_COMPATIBILITY)
        gx_prompt_text_color_set(prompt, props->normal_text_color_id, props->selected_text_color_id);
#else
        gx_prompt_text_color_set(prompt, props->normal_text_color_id, props->selected_text_color_id, props->disabled_text_color_id);
#endif
    }
    return status;
}

UINT gx_studio_pixelmap_prompt_create(GX_CONST GX_STUDIO_WIDGET *info, GX_WIDGET *control_block, GX_WIDGET *parent)
{
    UINT status;
    GX_PIXELMAP_PROMPT *pix_prompt = (GX_PIXELMAP_PROMPT *) control_block;
    GX_PROMPT *prompt = (GX_PROMPT *) pix_prompt;
    GX_PIXELMAP_PROMPT_PROPERTIES *props = (GX_PIXELMAP_PROMPT_PROPERTIES *) info->properties;
    status = gx_pixelmap_prompt_create(pix_prompt, info->widget_name, parent,
               props->string_id,
               props->fill_map_id,
               info->style, info->widget_id, &info->size);

    if (status == GX_SUCCESS)
    {
        gx_pixelmap_prompt_pixelmap_set(pix_prompt,
                                        props->left_map_id,
                                        props->fill_map_id,
                                        props->right_map_id,
                                        props->selected_left_map_id,
                                        props->selected_fill_map_id,
                                        props->selected_right_map_id);
        gx_prompt_font_set(prompt, props->font_id);
#if defined(GUIX_5_4_0_COMPATIBILITY)
        gx_prompt_text_color_set(prompt, props->normal_text_color_id, props->selected_text_color_id);
#else
        gx_prompt_text_color_set(prompt, props->normal_text_color_id, props->selected_text_color_id, props->disabled_text_color_id);
#endif
    }
    return status;
}

UINT gx_studio_window_create(GX_CONST GX_STUDIO_WIDGET *info, GX_WIDGET *control_block, GX_WIDGET *parent)
{
    UINT status;
    GX_WINDOW *window = (GX_WINDOW *) control_block;
    GX_WINDOW_PROPERTIES *props = (GX_WINDOW_PROPERTIES *) info->properties;
    status = gx_window_create(window, info->widget_name, parent, info->style, info->widget_id, &info->size);
    if (status == GX_SUCCESS)
    {
        if (props->wallpaper_id)
        {
            gx_window_wallpaper_set(window, props->wallpaper_id, info->style & GX_STYLE_TILE_WALLPAPER);
        }
    }
    return status;
}
GX_WINDOW_PROPERTIES window_properties =
{
    GX_PIXELMAP_ID_RED_APPLE                 /* wallpaper pixelmap id          */
};
GX_PIXELMAP_BUTTON_PROPERTIES window_pixelmap_button_1_properties =
{
    GX_PIXELMAP_ID_RED_APPLE,                /* normal pixelmap id             */
    GX_PIXELMAP_ID_RED_APPLE,                /* selected pixelmap id           */
    0                                        /* disabled pixelmap id           */
};
GX_ICON_BUTTON_PROPERTIES window_icon_button_1_properties =
{
    GX_PIXELMAP_ID_RED_APPLE                 /* pixelmap id                    */
};
GX_ICON_PROPERTIES window_icon_2_properties =
{
    GX_PIXELMAP_ID_RED_APPLE,                /* normal pixelmap id             */
    0                                        /* selected pixelmap id           */
};
GX_PIXELMAP_PROMPT_PROPERTIES window_prompt_1_properties =
{
    GX_STRING_ID_STRING_5,                   /* string id                      */
    GX_FONT_ID_PROMPT,                       /* font id                        */
    GX_COLOR_ID_TEXT,                        /* normal text color              */
    GX_COLOR_ID_SELECTED_TEXT,               /* selected text color            */
    GX_COLOR_ID_TEXT,                        /* disabled text color            */
    GX_PIXELMAP_ID_RED_APPLE,                /* left pixelmap id               */
    0,                                       /* fill pixelmap id               */
    GX_PIXELMAP_ID_RED_APPLE,                /* right pixelmap id              */
    0,                                       /* selected left pixelmap id      */
    0,                                       /* selected fill pixelmap id      */
    0                                        /* selected right pixelmap id     */
};
GX_PIXELMAP_SLIDER_PROPERTIES window_pixelmap_slider_1_properties =
{
    0,                                       /* minimum value                  */
    100,                                     /* maximum value                  */
    50,                                      /* current value                  */
    10,                                      /* increment                      */
    0,                                       /* minimum travel                 */
    0,                                       /* maximum travel                 */
    5,                                       /* needle width                   */
    10,                                      /* needle height                  */
    5,                                       /* needle inset                   */
    2,                                       /* needle hotspot                 */
    GX_PIXELMAP_ID_RED_APPLE,                /* lower pixelmap id              */
    GX_PIXELMAP_ID_RED_APPLE,                /* upper pixelmap id              */
    GX_PIXELMAP_ID_RED_APPLE                 /* needle pixelmap id             */
};
GX_PROMPT_PROPERTIES window_prompt_2_properties =
{
    GX_STRING_ID_STRING_2,                   /* string id                      */
    GX_FONT_ID_PROMPT,                       /* font id                        */
    GX_COLOR_ID_TEXT,                        /* normal text color              */
    GX_COLOR_ID_SELECTED_TEXT,               /* selected text color            */
    GX_COLOR_ID_TEXT                         /* disabled text color            */
};
GX_PROMPT_PROPERTIES window_prompt_3_properties =
{
    GX_STRING_ID_STRING_3,                   /* string id                      */
    GX_FONT_ID_PROMPT,                       /* font id                        */
    GX_COLOR_ID_TEXT,                        /* normal text color              */
    GX_COLOR_ID_SELECTED_TEXT,               /* selected text color            */
    GX_COLOR_ID_TEXT                         /* disabled text color            */
};
GX_PROMPT_PROPERTIES window_prompt_4_properties =
{
    GX_STRING_ID_STRING_4,                   /* string id                      */
    GX_FONT_ID_PROMPT,                       /* font id                        */
    GX_COLOR_ID_TEXT,                        /* normal text color              */
    GX_COLOR_ID_SELECTED_TEXT,               /* selected text color            */
    GX_COLOR_ID_TEXT                         /* disabled text color            */
};
GX_PROMPT_PROPERTIES window_prompt_5_properties =
{
    GX_STRING_ID_STRING_6,                   /* string id                      */
    GX_FONT_ID_PROMPT,                       /* font id                        */
    GX_COLOR_ID_TEXT,                        /* normal text color              */
    GX_COLOR_ID_SELECTED_TEXT,               /* selected text color            */
    GX_COLOR_ID_TEXT                         /* disabled text color            */
};

GX_CONST GX_STUDIO_WIDGET window_prompt_5_define =
{
    "prompt_5",
    GX_TYPE_PROMPT,                          /* widget type                    */
    GX_ID_NONE,                              /* widget id                      */
    #if defined(GX_WIDGET_USER_DATA)
    0,                                       /* user data                      */
    #endif
    GX_STYLE_BORDER_THIN|GX_STYLE_ENABLED|GX_STYLE_TEXT_CENTER,   /* style flags */
    GX_STATUS_ACCEPTS_FOCUS,                 /* status flags                   */
    sizeof(GX_PROMPT),                       /* control block size             */
    GX_COLOR_ID_WIDGET_FILL,                 /* normal color id                */
    GX_COLOR_ID_SELECTED_FILL,               /* selected color id              */
    GX_COLOR_ID_WIDGET_FILL,                 /* disabled color id              */
    gx_studio_prompt_create,                 /* create function                */
    GX_NULL,                                 /* drawing function override      */
    GX_NULL,                                 /* event function override        */
    {434, 453, 574, 476},                    /* widget size                    */
    GX_NULL,                                 /* no next widget                 */
    GX_NULL,                                 /* no child widgets               */ 
    offsetof(WINDOW_CONTROL_BLOCK, window_prompt_5), /* control block          */
    (void *) &window_prompt_5_properties     /* extended properties            */
};

GX_CONST GX_STUDIO_WIDGET window_prompt_4_define =
{
    "prompt_4",
    GX_TYPE_PROMPT,                          /* widget type                    */
    GX_ID_NONE,                              /* widget id                      */
    #if defined(GX_WIDGET_USER_DATA)
    0,                                       /* user data                      */
    #endif
    GX_STYLE_BORDER_THIN|GX_STYLE_ENABLED|GX_STYLE_TEXT_CENTER,   /* style flags */
    GX_STATUS_ACCEPTS_FOCUS,                 /* status flags                   */
    sizeof(GX_PROMPT),                       /* control block size             */
    GX_COLOR_ID_WIDGET_FILL,                 /* normal color id                */
    GX_COLOR_ID_SELECTED_FILL,               /* selected color id              */
    GX_COLOR_ID_WIDGET_FILL,                 /* disabled color id              */
    gx_studio_prompt_create,                 /* create function                */
    GX_NULL,                                 /* drawing function override      */
    GX_NULL,                                 /* event function override        */
    {5, 342, 137, 365},                      /* widget size                    */
    &window_prompt_5_define,                 /* next widget definition         */
    GX_NULL,                                 /* no child widgets               */ 
    offsetof(WINDOW_CONTROL_BLOCK, window_prompt_4), /* control block          */
    (void *) &window_prompt_4_properties     /* extended properties            */
};

GX_CONST GX_STUDIO_WIDGET window_prompt_3_define =
{
    "prompt_3",
    GX_TYPE_PROMPT,                          /* widget type                    */
    GX_ID_NONE,                              /* widget id                      */
    #if defined(GX_WIDGET_USER_DATA)
    0,                                       /* user data                      */
    #endif
    GX_STYLE_BORDER_THIN|GX_STYLE_ENABLED|GX_STYLE_TEXT_CENTER,   /* style flags */
    GX_STATUS_ACCEPTS_FOCUS,                 /* status flags                   */
    sizeof(GX_PROMPT),                       /* control block size             */
    GX_COLOR_ID_WIDGET_FILL,                 /* normal color id                */
    GX_COLOR_ID_SELECTED_FILL,               /* selected color id              */
    GX_COLOR_ID_WIDGET_FILL,                 /* disabled color id              */
    gx_studio_prompt_create,                 /* create function                */
    GX_NULL,                                 /* drawing function override      */
    GX_NULL,                                 /* event function override        */
    {358, 259, 407, 282},                    /* widget size                    */
    &window_prompt_4_define,                 /* next widget definition         */
    GX_NULL,                                 /* no child widgets               */ 
    offsetof(WINDOW_CONTROL_BLOCK, window_prompt_3), /* control block          */
    (void *) &window_prompt_3_properties     /* extended properties            */
};

GX_CONST GX_STUDIO_WIDGET window_prompt_2_define =
{
    "prompt_2",
    GX_TYPE_PROMPT,                          /* widget type                    */
    GX_ID_NONE,                              /* widget id                      */
    #if defined(GX_WIDGET_USER_DATA)
    0,                                       /* user data                      */
    #endif
    GX_STYLE_BORDER_THIN|GX_STYLE_ENABLED|GX_STYLE_TEXT_CENTER,   /* style flags */
    GX_STATUS_ACCEPTS_FOCUS,                 /* status flags                   */
    sizeof(GX_PROMPT),                       /* control block size             */
    GX_COLOR_ID_WIDGET_FILL,                 /* normal color id                */
    GX_COLOR_ID_SELECTED_FILL,               /* selected color id              */
    GX_COLOR_ID_WIDGET_FILL,                 /* disabled color id              */
    gx_studio_prompt_create,                 /* create function                */
    GX_NULL,                                 /* drawing function override      */
    GX_NULL,                                 /* event function override        */
    {500, 361, 629, 384},                    /* widget size                    */
    &window_prompt_3_define,                 /* next widget definition         */
    GX_NULL,                                 /* no child widgets               */ 
    offsetof(WINDOW_CONTROL_BLOCK, window_prompt_2), /* control block          */
    (void *) &window_prompt_2_properties     /* extended properties            */
};

GX_CONST GX_STUDIO_WIDGET window_pixelmap_slider_1_define =
{
    "pixelmap_slider_1",
    GX_TYPE_PIXELMAP_SLIDER,                 /* widget type                    */
    GX_ID_NONE,                              /* widget id                      */
    #if defined(GX_WIDGET_USER_DATA)
    0,                                       /* user data                      */
    #endif
    GX_STYLE_BORDER_RAISED|GX_STYLE_ENABLED,   /* style flags                  */
    GX_STATUS_ACCEPTS_FOCUS,                 /* status flags                   */
    sizeof(GX_PIXELMAP_SLIDER),              /* control block size             */
    GX_COLOR_ID_BLUE,                        /* normal color id                */
    GX_COLOR_ID_BLUE,                        /* selected color id              */
    GX_COLOR_ID_BLUE,                        /* disabled color id              */
    gx_studio_pixelmap_slider_create,        /* create function                */
    GX_NULL,                                 /* drawing function override      */
    GX_NULL,                                 /* event function override        */
    {113, 317, 522, 493},                    /* widget size                    */
    &window_prompt_2_define,                 /* next widget definition         */
    GX_NULL,                                 /* no child widgets               */ 
    offsetof(WINDOW_CONTROL_BLOCK, window_pixelmap_slider_1), /* control block */
    (void *) &window_pixelmap_slider_1_properties /* extended properties       */
};

GX_CONST GX_STUDIO_WIDGET window_prompt_1_define =
{
    "prompt_1",
    GX_TYPE_PIXELMAP_PROMPT,                 /* widget type                    */
    GX_ID_NONE,                              /* widget id                      */
    #if defined(GX_WIDGET_USER_DATA)
    0,                                       /* user data                      */
    #endif
    GX_STYLE_BORDER_THIN|GX_STYLE_TRANSPARENT|GX_STYLE_ENABLED|GX_STYLE_TEXT_CENTER,   /* style flags */
    GX_STATUS_ACCEPTS_FOCUS,                 /* status flags                   */
    sizeof(GX_PIXELMAP_PROMPT),              /* control block size             */
    GX_COLOR_ID_SCROLL_FILL,                 /* normal color id                */
    GX_COLOR_ID_GREEN,                       /* selected color id              */
    GX_COLOR_ID_SCROLL_FILL,                 /* disabled color id              */
    gx_studio_pixelmap_prompt_create,        /* create function                */
    GX_NULL,                                 /* drawing function override      */
    GX_NULL,                                 /* event function override        */
    {241, 6, 638, 167},                      /* widget size                    */
    &window_pixelmap_slider_1_define,        /* next widget definition         */
    GX_NULL,                                 /* no child widgets               */ 
    offsetof(WINDOW_CONTROL_BLOCK, window_prompt_1), /* control block          */
    (void *) &window_prompt_1_properties     /* extended properties            */
};

GX_CONST GX_STUDIO_WIDGET window_icon_2_define =
{
    "icon_2",
    GX_TYPE_ICON,                            /* widget type                    */
    GX_ID_NONE,                              /* widget id                      */
    #if defined(GX_WIDGET_USER_DATA)
    0,                                       /* user data                      */
    #endif
    GX_STYLE_BORDER_NONE|GX_STYLE_ENABLED|GX_STYLE_HALIGN_LEFT|GX_STYLE_VALIGN_TOP,   /* style flags */
    GX_STATUS_ACCEPTS_FOCUS,                 /* status flags                   */
    sizeof(GX_ICON),                         /* control block size             */
    GX_COLOR_ID_BTN_UPPER,                   /* normal color id                */
    GX_COLOR_ID_SELECTED_FILL,               /* selected color id              */
    GX_COLOR_ID_BTN_UPPER,                   /* disabled color id              */
    gx_studio_icon_create,                   /* create function                */
    GX_NULL,                                 /* drawing function override      */
    GX_NULL,                                 /* event function override        */
    {232, 176, 351, 339},                    /* widget size                    */
    &window_prompt_1_define,                 /* next widget definition         */
    GX_NULL,                                 /* no child widgets               */ 
    offsetof(WINDOW_CONTROL_BLOCK, window_icon_2), /* control block            */
    (void *) &window_icon_2_properties       /* extended properties            */
};

GX_CONST GX_STUDIO_WIDGET window_icon_button_1_define =
{
    "icon_button_1",
    GX_TYPE_ICON_BUTTON,                     /* widget type                    */
    GX_ID_NONE,                              /* widget id                      */
    #if defined(GX_WIDGET_USER_DATA)
    0,                                       /* user data                      */
    #endif
    GX_STYLE_BORDER_RAISED|GX_STYLE_TRANSPARENT|GX_STYLE_ENABLED|GX_STYLE_HALIGN_CENTER|GX_STYLE_VALIGN_CENTER,   /* style flags */
    GX_STATUS_ACCEPTS_FOCUS,                 /* status flags                   */
    sizeof(GX_ICON_BUTTON),                  /* control block size             */
    GX_COLOR_ID_WINDOW_BORDER,               /* normal color id                */
    GX_COLOR_ID_BTN_UPPER,                   /* selected color id              */
    GX_COLOR_ID_WINDOW_BORDER,               /* disabled color id              */
    gx_studio_icon_button_create,            /* create function                */
    GX_NULL,                                 /* drawing function override      */
    GX_NULL,                                 /* event function override        */
    {488, 181, 635, 356},                    /* widget size                    */
    &window_icon_2_define,                   /* next widget definition         */
    GX_NULL,                                 /* no child widgets               */ 
    offsetof(WINDOW_CONTROL_BLOCK, window_icon_button_1), /* control block     */
    (void *) &window_icon_button_1_properties /* extended properties           */
};

GX_CONST GX_STUDIO_WIDGET window_pixelmap_button_1_define =
{
    "pixelmap_button_1",
    GX_TYPE_PIXELMAP_BUTTON,                 /* widget type                    */
    GX_ID_NONE,                              /* widget id                      */
    #if defined(GX_WIDGET_USER_DATA)
    0,                                       /* user data                      */
    #endif
    GX_STYLE_BORDER_NONE|GX_STYLE_ENABLED,   /* style flags                    */
    GX_STATUS_ACCEPTS_FOCUS,                 /* status flags                   */
    sizeof(GX_PIXELMAP_BUTTON),              /* control block size             */
    GX_COLOR_ID_RED,                         /* normal color id                */
    GX_COLOR_ID_BTN_UPPER,                   /* selected color id              */
    GX_COLOR_ID_RED,                         /* disabled color id              */
    gx_studio_pixelmap_button_create,        /* create function                */
    GX_NULL,                                 /* drawing function override      */
    GX_NULL,                                 /* event function override        */
    {4, 177, 147, 344},                      /* widget size                    */
    &window_icon_button_1_define,            /* next widget definition         */
    GX_NULL,                                 /* no child widgets               */ 
    offsetof(WINDOW_CONTROL_BLOCK, window_pixelmap_button_1), /* control block */
    (void *) &window_pixelmap_button_1_properties /* extended properties       */
};

GX_CONST GX_STUDIO_WIDGET window_define =
{
    "window",
    GX_TYPE_WINDOW,                          /* widget type                    */
    GX_ID_NONE,                              /* widget id                      */
    #if defined(GX_WIDGET_USER_DATA)
    0,                                       /* user data                      */
    #endif
    GX_STYLE_BORDER_THIN|GX_STYLE_TRANSPARENT,   /* style flags                */
    GX_STATUS_ACCEPTS_FOCUS,                 /* status flags                   */
    sizeof(WINDOW_CONTROL_BLOCK),            /* control block size             */
    GX_COLOR_ID_SELECTED_FILL,               /* normal color id                */
    GX_COLOR_ID_SELECTED_FILL,               /* selected color id              */
    GX_COLOR_ID_SELECTED_FILL,               /* disabled color id              */
    gx_studio_window_create,                 /* create function                */
    (VOID (*)(GX_WIDGET *)) pic_win_draw,    /* drawing function override      */
    GX_NULL,                                 /* event function override        */
    {2, 1, 641, 480},                        /* widget size                    */
    GX_NULL,                                 /* next widget                    */
    &window_pixelmap_button_1_define,        /* child widget                   */
    0,                                       /* control block                  */
    (void *) &window_properties              /* extended properties            */
};
GX_CONST GX_STUDIO_WIDGET_ENTRY alphamap_16bppdriver_widget_table[] =
{
    { &window_define, (GX_WIDGET *) &window },
    {GX_NULL, GX_NULL}
};

static GX_WIDGET *gx_studio_nested_widget_create(GX_BYTE *control, GX_CONST GX_STUDIO_WIDGET *definition, GX_WIDGET *parent)
{
    UINT status = GX_SUCCESS;
    GX_WIDGET *widget = GX_NULL;
    GX_VALUE   list_count = 0;
    GX_VALUE   list_total_count = 0;

    if(parent && (parent->gx_widget_type == GX_TYPE_MENU))
    {
        list_total_count = ((GX_MENU *)parent)->gx_menu_list_total_count;
    }

    while(definition && status == GX_SUCCESS)
    {
        if (definition->create_function)
        {
            if (definition->style & GX_STYLE_DYNAMICALLY_ALLOCATED)
            {
                status = gx_widget_allocate(&widget, definition->control_block_size);
                if (status != GX_SUCCESS)
                {
                    return GX_NULL;
                }
            }
            else
            {
                if (control == GX_NULL)
                {
                    return GX_NULL;
                }
                widget = (GX_WIDGET *) (control + definition->control_block_offset);
            }

            status = definition->create_function(definition, widget, parent);

            if(list_count < list_total_count)
            {
                gx_menu_insert((GX_MENU *)parent, widget);
                ((GX_MENU *)parent)->gx_menu_list_total_count--;
                list_count++;
            }

            if (status == GX_SUCCESS)
            {
                if (definition->widget_type != GX_TYPE_TEMPLATE)
                {
#if defined(GUIX_5_4_0_COMPATIBILITY)
                    gx_widget_fill_color_set(widget, definition->normal_fill_color_id, definition->selected_fill_color_id);
#else
                    gx_widget_fill_color_set(widget, definition->normal_fill_color_id, definition->selected_fill_color_id, definition->disabled_fill_color_id);
#endif
                }

                if (!(definition->status & GX_STATUS_ACCEPTS_FOCUS))
                {
                    gx_widget_status_remove(widget, GX_STATUS_ACCEPTS_FOCUS);
                }

                if (definition->draw_function)
                {
                    gx_widget_draw_set(widget, definition->draw_function);
                }
                if (definition->event_function)
                {
                    gx_widget_event_process_set(widget, definition->event_function);
                }

                #if defined(GX_WIDGET_USER_DATA)
                widget->gx_widget_user_data = definition->user_data;
                #endif

                if (definition->child_widget)
                {
                    gx_studio_nested_widget_create(control, definition->child_widget, widget);
                }
            }
            definition = definition->next_widget;
        }
    }
    return widget;
}

GX_WIDGET *gx_studio_widget_create(GX_BYTE *control, GX_CONST GX_STUDIO_WIDGET *definition, GX_WIDGET *parent)
{
    GX_WIDGET *widget;
    widget = gx_studio_nested_widget_create(control, definition, GX_NULL);

    if (parent && widget)
    {
        gx_widget_attach(parent, widget);
    }
    return widget;
}

UINT gx_studio_named_widget_create(char *name, GX_WIDGET *parent, GX_WIDGET **new_widget)
{
    UINT status = GX_FAILURE;
    GX_CONST GX_STUDIO_WIDGET_ENTRY *entry = alphamap_16bppdriver_widget_table;
    GX_WIDGET *widget = GX_NULL;

    while(entry->widget_information)
    {
        if (!strcmp(name, entry->widget_information->widget_name))
        {
            widget = gx_studio_widget_create((GX_BYTE *) entry->widget, entry->widget_information, parent);
            if (widget)
            {
                status = GX_SUCCESS;
            }
            break;
        }
        entry++;
    }

    if (new_widget)
    {
        *new_widget = widget;
    }
    return status;
}


UINT gx_studio_display_configure(USHORT display, UINT (*driver)(GX_DISPLAY *),
    GX_UBYTE language, USHORT theme, GX_WINDOW_ROOT **return_root)
{
    GX_CONST GX_THEME *theme_ptr;
    GX_RECTANGLE size;

    GX_STUDIO_DISPLAY_INFO *display_info = &alphamap_16bppdriver_display_table[display];


/* create the requested display                                                */

    gx_display_create(display_info->display,
                      display_info->name,
                      driver,
                      (GX_VALUE) display_info->x_resolution,
                      (GX_VALUE) display_info->y_resolution);


/* install the request theme                                                   */

    if(display_info->theme_table)
    {
        theme_ptr = display_info->theme_table[theme];
        if(theme_ptr)
        {
            gx_display_color_table_set(display_info->display, theme_ptr->theme_color_table, theme_ptr->theme_color_table_size);
            
/* install the color palette if required                                       */
            if (display_info->display->gx_display_driver_palette_set &&
                theme_ptr->theme_palette != NULL)
            {
                display_info->display->gx_display_driver_palette_set(display_info->display, theme_ptr->theme_palette, theme_ptr->theme_palette_size);
            }

            gx_display_font_table_set(display_info->display, theme_ptr->theme_font_table, theme_ptr->theme_font_table_size);
            gx_display_pixelmap_table_set(display_info->display, theme_ptr->theme_pixelmap_table, theme_ptr->theme_pixelmap_table_size);
            gx_system_scroll_appearance_set(theme_ptr->theme_vertical_scroll_style, (GX_SCROLLBAR_APPEARANCE *) &theme_ptr->theme_vertical_scrollbar_appearance);
            gx_system_scroll_appearance_set(theme_ptr->theme_horizontal_scroll_style, (GX_SCROLLBAR_APPEARANCE *) &theme_ptr->theme_horizontal_scrollbar_appearance);
        }
    }

/* Install the language table.                                                 */

    if(display_info->language_table)
    {
        gx_display_language_table_set_ext(display_info->display, display_info->language_table, (GX_UBYTE) display_info->language_table_size, display_info->string_table_size);
        gx_display_active_language_set(display_info->display, language);
    }

/* Set screen rotation angle.                                                  */

    display_info->display->gx_display_rotation_angle = display_info->rotation_angle;

/* create the canvas for this display                                          */

    gx_canvas_create(display_info->canvas,
                     display_info->canvas_name,
                     display_info->display,
                     GX_CANVAS_MANAGED | GX_CANVAS_VISIBLE,
                     display_info->x_resolution,
                     display_info->y_resolution,
                     display_info->canvas_memory,
                     display_info->canvas_memory_size);

/* Create the root window for this canvas                                      */

    gx_utility_rectangle_define(&size,
                                0, 0,
                                (GX_VALUE) (display_info->x_resolution - 1),
                                (GX_VALUE) (display_info->y_resolution - 1));

    gx_window_root_create(display_info->root_window,
                          display_info->name,
                          display_info->canvas, GX_STYLE_NONE, 0, &size);
    if (return_root)
    {
        *return_root = display_info->root_window;
    }
    return GX_SUCCESS;
}
#undef GUIX_STUDIO_GENERATED_FILE

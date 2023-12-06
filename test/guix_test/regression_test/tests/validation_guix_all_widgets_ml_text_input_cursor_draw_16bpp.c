/* This is a small demo of the high-performance GUIX graphics framework. */

#include <stdio.h>
#include "tx_api.h"
#include "gx_api.h"
#include "gx_validation_utility.h"

TEST_PARAM test_parameter = {
    "guix_all_widgets_ml_text_input_cursor_draw_16bpp", /* Test name */
    311, 232, 582, 404  /* Define the coordinates of the capture area.
                         In this test, we only need to capture the multi 
                         line text input drawing area.  */
};

static VOID      control_thread_entry(ULONG);
int main(int argc, char ** argv)
{
    /* Parse the command line argument. */
    gx_validation_setup(argc, argv);

    /* Start ThreadX system */
    tx_kernel_enter(); 
    return(0);
}

VOID tx_application_define(void *first_unused_memory)
{

    /* Create a dedicated thread to perform various operations
       on the multi line text input example. These operations simulate 
       user input. */
    gx_validation_control_thread_create(control_thread_entry);

    /* Terminate the test if it runs for more than 100 ticks */
    /* This function is not implemented yet. */
    gx_validation_watchdog_create(100);

    /* Call the actual multi line text input routine. */
    gx_validation_application_define(first_unused_memory);

}


/* Replace the default graphics driver with the validation driver. */
#ifdef win32_graphics_driver_setup_565rgb  
#undef win32_graphics_driver_setup_565rgb  
#endif
#define win32_graphics_driver_setup_565rgb  gx_validation_graphics_driver_setup_565rgb


#ifdef WIN32
#undef WIN32
#endif

#include "gx_validation_wrapper.h"

#include "demo_guix_all_widgets_16bpp.c"

/* Define the input string.*/
static char string_array[3][200] = {
"ab\rcdefghijklmnopqrstuvwxyz 0123456789",
"ab\rcdefghijklmnopqrstuvwxyz 0123456789\r",
"ab\r\rcdefghijklmnopqrstuvwxyz0123456789\r\rabcdefghijk \r\rabcdefghijklmnopqrstuvwxyz \rabcdefghijklmnopqrst uvwxyz 12345"};

/* Define the x coordinate where mouse clicks.*/
static int x_value[] = {322, 400, 571};

/* Define the y coordinate where mouse clicks.*/
static int y_value[] = {250, 350, 395};

/* Define the nonprintable key value.*/
static USHORT noprint_key_value[] = {
GX_KEY_UP_ARROW, GX_KEY_SELECT, GX_KEY_LEFT_ARROW,
GX_KEY_BACKSPACE, GX_KEY_HOME, GX_KEY_DELETE,
GX_KEY_RIGHT_ARROW, GX_KEY_DOWN_ARROW, GX_KEY_END};

char test_comment[256];

/* This thread simulates user input.  Its priority is lower
   than the GUIX thread, so that GUIX finishes an operation 
   before this thread is able to issue the next command. */
static VOID control_thread_entry(ULONG input)
{
GX_MULTI_LINE_TEXT_INPUT *text_input = &(text_screen.text_screen_text_input_2);
int string_index, x_index, y_index, key_index;
int frame_id = 1;
GX_EVENT my_event;

    /* Toggle button_screen to text_screen. */
    ToggleScreen(pTextScreen, pButtonScreen);

    /* Set text color. */
    gx_multi_line_text_view_text_color_set((GX_MULTI_LINE_TEXT_VIEW *)text_input, GX_COLOR_ID_ORANGE, GX_COLOR_ID_ORANGE, GX_COLOR_ID_ORANGE);

    /* Remove the cursor blink flag. */
    gx_multi_line_text_input_style_remove(text_input, GX_STYLE_CURSOR_BLINK);
    gx_multi_line_text_input_style_add(text_input, GX_STYLE_CURSOR_ALWAYS);

    /* Set whitespace.  */
    gx_multi_line_text_view_whitespace_set((GX_MULTI_LINE_TEXT_VIEW *)text_input, 2);

    /* Set line space.  */
    gx_multi_line_text_view_line_space_set((GX_MULTI_LINE_TEXT_VIEW *)text_input, 6);

    /* Check the cursor when there is no word displayed in the window. */
    gx_validation_set_frame_id(frame_id++);

    sprintf(test_comment, "xpos:400, ypos:300, click inside");
    gx_validation_set_frame_comment(test_comment);

    memset(&my_event, 0, sizeof(GX_EVENT));
    my_event.gx_event_display_handle = 1;
    my_event.gx_event_type = GX_EVENT_PEN_DOWN;
    my_event.gx_event_payload.gx_event_pointdata.gx_point_x = 400;
    my_event.gx_event_payload.gx_event_pointdata.gx_point_y = 300;
    gx_system_event_send(&my_event);

    my_event.gx_event_type = GX_EVENT_PEN_UP;
    gx_system_event_send(&my_event);

    /* Check the cursor when input a printalbe character in the window. */    
    gx_validation_set_frame_id(frame_id++);
    sprintf(test_comment, "input character:%c", 'a');
    gx_validation_set_frame_comment(test_comment);

    my_event.gx_event_type = GX_EVENT_KEY_DOWN;
    my_event.gx_event_payload.gx_event_ushortdata[0] = 'a';
    gx_system_event_send(&my_event);

    /* Check the cursor when clicks in some places inside or outside
       the window and presses some no-printable keys. */
    for(string_index = 0; string_index < 3; string_index++)
    {
        /* Assign a text string to the multi line text view.  */
        gx_multi_line_text_view_text_set((GX_MULTI_LINE_TEXT_VIEW *)text_input, string_array[string_index]);

        for(x_index = 0; x_index < (INT)(sizeof(x_value)/sizeof(int)); x_index++)
        {
            for(y_index = 0; y_index < (INT)(sizeof(y_value)/sizeof(int)); y_index++)
            {
                gx_validation_set_frame_id(frame_id++);

                sprintf(test_comment, "string:%d, length:%d, xpos:%d, ypos:%d",
                                      string_index + 1, GX_STRLEN(string_array[string_index]),
                                      x_value[x_index], y_value[y_index]);

                gx_validation_set_frame_comment(test_comment);

                /* Send pen down event.  */
                my_event.gx_event_payload.gx_event_pointdata.gx_point_x = x_value[x_index];
                my_event.gx_event_payload.gx_event_pointdata.gx_point_y = y_value[y_index];
                my_event.gx_event_type = GX_EVENT_PEN_DOWN;
                gx_system_event_send(&my_event);

                my_event.gx_event_type = GX_EVENT_PEN_UP;
                gx_system_event_send(&my_event);

                for(key_index = 0; key_index < (INT)(sizeof(noprint_key_value)/sizeof(USHORT)); key_index++)
                {

                    gx_validation_set_frame_id(frame_id++);

                    switch(noprint_key_value[key_index])
                    {
                    case GX_KEY_UP_ARROW:
                        strcat(test_comment, " up key");
                        break;
                    case GX_KEY_SELECT:
                        strcat(test_comment, " return key");
                        break;
                    case GX_KEY_LEFT_ARROW:
                        strcat(test_comment, " left key");
                        break;
                    case GX_KEY_BACKSPACE:
                        strcat(test_comment, " backspace key");
                        break;
                    case GX_KEY_HOME:
                        strcat(test_comment, " home key");
                        break;
                    case GX_KEY_DELETE:
                        strcat(test_comment, " delete key");
                        break;
                    case GX_KEY_RIGHT_ARROW:
                        strcat(test_comment, " right key");
                        break;
                    case GX_KEY_DOWN_ARROW:
                        strcat(test_comment, " down key");
                        break;
                    case GX_KEY_END:
                        strcat(test_comment, " end key");
                        break;
                    }

                    gx_validation_set_frame_comment(test_comment);
 
                    /* Send key down event to the system. */
                    my_event.gx_event_payload.gx_event_ushortdata[0] = noprint_key_value[key_index];
                    my_event.gx_event_type = GX_EVENT_KEY_DOWN;
                    gx_system_event_send(&my_event);
                }
            }
        }
    }

    /* Signal the end of the test case.  Verify the output. */
    gx_validation_end();

    exit(0);
}
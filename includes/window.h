#ifndef WINDOW_H
# define WINDOW_H
# define PREV_CAM 123
# define NEXT_CAM 124
# define ESC_KEY 53

void img_to_window(t_rtindex *index);
int window_key_options(int key, t_rtindex *index);
int window_change_cam(int key, t_rtindex *index);
void window_generate_images(t_rtindex *index);

#endif

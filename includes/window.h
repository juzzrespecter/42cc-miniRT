#ifndef WINDOW_H
# define WINDOW_H

void img_to_window(t_rtindex *index);
int window_press_esc(int key, t_rtindex *index);
int window_click_exit(int button, int x, int y, t_rtindex *index);
int window_change_cam(int key, t_rtindex *index);
void window_generate_images(t_rtindex *index);

#endif

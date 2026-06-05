/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joystick.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnanga <vnanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 14:21:38 by vnanga            #+#    #+#             */
/*   Updated: 2026/06/05 14:45:50 by vnanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/joystick.h"

t_joystick  *js_init(const char *device_path)
{
    t_joystick *init = malloc(sizeof(t_joystick));
    if (!init) return NULL;
    
    init->fd = open(device_path, O_RDONLY | O_NONBLOCK);
    if (init->fd < 0)
    {
        free(init);
        return NULL;
    }
    
    for (int i = 0; i < 8; i++) init->buttons[i] = 0;
    for (int i = 0; i < 8; i++) init->axis[i] = 0;

    return (init);
}

int     js_update(t_joystick *init)
{
    struct js_event e;
    
    while (read(init->fd, &e, sizeof(e)) > 0)
    {
        e.type &= ~JS_EVENT_INIT;
        if (e.type == JS_EVENT_AXIS) {
            init->axis[e.number] = e.value;
        } else if (e.type == JS_EVENT_BUTTON) {
            init->buttons[e.number] = e.value;
        }
    }
    return (1);
}

void    js_close(t_joystick *init)
{
    if (init)
    {
        if (init->fd >= 0)
            close(init->fd);
        free(init);
    }
}
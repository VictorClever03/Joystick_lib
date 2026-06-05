/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joystick.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnanga <vnanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 13:32:34 by vnanga            #+#    #+#             */
/*   Updated: 2026/06/05 14:20:46 by vnanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JOYSTICK
#define JOYSTICK


#include "./macros.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdio.h>
#include <linux/joystick.h>


typedef struct s_joystick{
    int fd;
    int buttons[8];
    int axis[8];
} t_joystick;

t_joystick  *js_init(const char *device_path);
int         js_update(t_joystick *js);
void        js_close(t_joystick *js);

#endif
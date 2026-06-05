/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnanga <vnanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:13:48 by vnanga            #+#    #+#             */
/*   Updated: 2026/06/05 15:24:35 by vnanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/joystick.h"

int main()
{
	t_joystick *meu_controle = js_init("/dev/input/js0");
    
    if (!meu_controle) {
        printf("Controle PS3 não encontrado!\n");
        return 1;
    }

    // Loop principal do jogo (como no cub3d ou minilibx)
    while (1) {
        // 2. O usuário atualiza o estado
        js_update(meu_controle);

        if (meu_controle->buttons[BTN_CROSS]) {
            printf("Você clicou X!\n");
        }
        
        if (meu_controle->buttons[BTN_CIRCLE]) {
            printf("Você clicou Bola!\n");
        }


        if (meu_controle->buttons[BTN_SQUARE]) {
            printf("Você clicou quadrado!\n");
        }


        if (meu_controle->buttons[BTN_TRIANGLE]) {
            printf("Você clicou triangulo!\n");
        }


        if (meu_controle->buttons[BTN_L1]) {
            printf("Você clicou L1!\n");
        }


        if (meu_controle->buttons[BTN_R1]) {
            printf("Você clicou R1!\n");
        }


        if (meu_controle->buttons[BTN_START]) {
            printf("Você clicou Start!\n");
        }


        if (meu_controle->buttons[BTN_SELECT]) {
            printf("Você clicou Select!\n");
        }

        if (meu_controle->axis[LEFT_STICK_Y_AXIS] < -10000) {
            printf("Andando para frente...\n");
        }
		if (meu_controle->axis[LEFT_STICK_Y_AXIS] > 10000) {
            printf("Andando para tras...\n");
        }
    }

    js_close(meu_controle);
    return 0;
}

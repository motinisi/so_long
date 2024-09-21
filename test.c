/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:47:49 by timanish          #+#    #+#             */
/*   Updated: 2024/09/19 18:17:47 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "so_long.h"
# include "minilibx-linux/mlx.h"
#include <stdio.h>

int close_window(void *param)
{
    (void)param;  // 使用しない引数
    printf("ウィンドウを閉じました。\n");
    exit(0);  // 正常終了
}

int main(void)
{
    void *mlx;         // MiniLibXの初期化用ポインタ
    void *win;         // ウィンドウのポインタ
    void *img;         // 画像のポインタ
    int img_width = 64; // 画像の幅
    int img_height = 64; // 画像の高さ

    // MiniLibXを初期化
    mlx = mlx_init();
    if (!mlx)
    {
        printf("MiniLibXの初期化に失敗しました。\n");
        return (EXIT_FAILURE);
    }

    // ウィンドウを作成 (幅800, 高さ600, タイトルは "Hello MLX")
    win = mlx_new_window(mlx, 800, 600, "Hello MLX");
    if (!win)
    {
        printf("ウィンドウの作成に失敗しました。\n");
        return (EXIT_FAILURE);
    }

    // 画像（XPMファイル）を読み込み
    // printf("使用するファイルパス: %s\n", "images.xpm");
    img = mlx_xpm_file_to_image(mlx, "./animals.xpm", &img_width, &img_height);
    if (!img)
    {
        printf("画像の読み込みに失敗しました。\n");
        return (EXIT_FAILURE);
    }

    // // 画像をウィンドウに表示 (表示位置: x = 100, y = 100)
    mlx_put_image_to_window(mlx, win, img, 100, 100);

    mlx_hook(win, 17, 0, close_window, NULL);

    // イベントループ（ウィンドウが閉じられるまで待機）
    mlx_loop(mlx);

    return (0);
}

